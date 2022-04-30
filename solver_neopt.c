/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double *my_solver(int N, double *A, double *B)
{
	double *C = calloc(N * N, sizeof(double));
	double *AT = calloc(N * N, sizeof(double));
	double *BT = calloc(N * N, sizeof(double));
	double *OP1 = calloc(N * N, sizeof(double));
	double *OP2 = calloc(N * N, sizeof(double));
	double *OP3 = calloc(N * N, sizeof(double));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			BT[j*N+i] = B[i*N+j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			AT[j*N+i] = A[i*N+j];
		}
	}

	// B * A
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= j; k++) {
				OP1[i * N + j] += B[i * N + k] * A[k * N + j];
			}
		}
	}

	// OP1 * AT
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = j; k < N; k++) {
				OP2[i * N + j] += OP1[i * N + k] * AT[k * N + j];
			}
		}
	}

	// BT * B
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				OP3[i * N + j] += BT[i * N + k] * B[k * N + j];
			}
		}
	}

	// OP2 + OP3
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i*N+j] += OP2[i*N+j] + OP3[i*N+j];
		}
	}

	printf("NEOPT SOLVER\n");
	free(AT);
	free(BT);
	free(OP1);
	free(OP2);
	free(OP3);
	return C;
}
