/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
#include "cblas.h"
// func cblas_dgemm(_ __Order: CBLAS_ORDER, 
//                _ __TransA: CBLAS_TRANSPOSE, 
//                _ __TransB: CBLAS_TRANSPOSE, 
//                _ __M: Int32, 
//                _ __N: Int32, 
//                _ __K: Int32, 
//                _ __alpha: Double, 
//                _ __A: UnsafePointer<Double>!, 
//                _ __lda: Int32, 
//                _ __B: UnsafePointer<Double>!, 
//                _ __ldb: Int32, 
//                _ __beta: Double, 
//                _ __C: UnsafeMutablePointer<Double>!, 
//                _ __ldc: Int32)

// func cblas_dtrmm(_ __Order: CBLAS_ORDER, 
//                _ __Side: CBLAS_SIDE, 
//                _ __Uplo: CBLAS_UPLO, 
//                _ __TransA: CBLAS_TRANSPOSE, 
//                _ __Diag: CBLAS_DIAG, 
//                _ __M: Int32, 
//                _ __N: Int32, 
//                _ __alpha: Double, 
//                _ __A: UnsafePointer<Double>!, 
//                _ __lda: Int32, 
//                _ __B: UnsafeMutablePointer<Double>!, 
//                _ __ldb: Int32)
/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	double *C = calloc(N * N, sizeof(double));
	double *OP1 = calloc(N * N, sizeof(double));
	double *OP2 = calloc(N * N, sizeof(double));
	double *OP3 = calloc(N * N, sizeof(double));
	for(int i = 0; i < N*N; i++) {
		OP2[i] = B[i];
	}
	// BT * B
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B, N, B, N, 1.0, OP1, N)

	// B * A
	cblas_dtrmm(CblasRowMajor, CblasLower, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, OP2, N);

	// OP2 * AT
	cblas_dtrmm(CblasRowMajor, CblasLower, CblasLower, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, OP2, N);

	for(i = 0; i < N*N; i++) {
		C[i] = OP2[i];
	}
	printf("BLAS SOLVER\n");
	free(OP1);
	free(OP2);
	free(OP3);
	return C;
}
