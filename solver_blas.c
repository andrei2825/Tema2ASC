/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
#include "cblas.h"
/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	double *C = calloc(N * N, sizeof(double));

	// AT * A
	cblas_dtrmm(CblasRowMajor,CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, A, N);
	// B * (AT * A)
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, B, N, A, N, 1.0, C, N);
	// C = C + BT * B
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B, N, B, N, 1.0, C, N);


	printf("BLAS SOLVER\n");
	return C;
}
