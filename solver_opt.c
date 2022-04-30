/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *C = calloc(N * N, sizeof(double));
	double *AT = calloc(N * N, sizeof(double));
	double *BT = calloc(N * N, sizeof(double));
	double *OP1 = calloc(N * N, sizeof(double));
	double *OP2 = calloc(N * N, sizeof(double));
	double *OP3 = calloc(N * N, sizeof(double));
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			BT[j*N+i] = B[i*N+j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			AT[j*N+i] = A[i*N+j];
		}
	}
	// BT * B
	for (i = 0; i < N; i++ ){
		double *orig_pbt = BT+i*N;
		for (j = 0; j < N; j++) {
			double *pbt = orig_pbt;
			double *pb = B + j;
			register double suma = 0;
			for (k = 0; k < N; k++) {
				suma += *pbt * *pb;
				pbt++;
				pb += N;
			}
			OP1[i*N+j] = suma;
		}
	}
	// B * A
	for (i = 0; i < N; i++ ){
		double *orig_pb = B+i*N;
		for (j = 0; j < N; j++) {
			double *pb = orig_pb;
			double *pa = A + j;
			register double suma = 0;
			for (k = 0; k <= j; k++) {
				suma += *pb * *pa;
				pb++;
				pa += N;
			}
			OP2[i*N+j] = suma;
		}
	}
	// OP2 * AT
	for (i = 0; i < N; i++ ){
		double *orig_op2 = OP2+i*N;
		for (j = 0; j < N; j++) {
			double *pop2 = orig_op2;
			double *pat = AT + j;
			register double suma = 0;
			for (k = j; k < N; k++) {
				suma += *pop2 * *pat;
				pop2++;
				pat += N;
			}
			OP3[i*N+j] = suma;
		}
	}
	// OP3 + OP1
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[i*N+j] = OP3[i*N+j] + OP1[i*N+j];
		}
	}

	printf("OPT SOLVER\n");
	free(AT);
	free(BT);
	free(OP1);
	free(OP2);
	free(OP3);
	return C;	
}
