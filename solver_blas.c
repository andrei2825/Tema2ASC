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

	// AT * A
	cblas_dtrmm(CblasRowMajor,CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, A, N);
	// B * (AT * A)
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, B, N, A, N, 1.0, C, N);
	// C = C + BT * B
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B, N, B, N, 1.0, C, N);


	printf("BLAS SOLVER\n");
	return C;
}
