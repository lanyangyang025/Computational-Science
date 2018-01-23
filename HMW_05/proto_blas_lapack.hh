//Subroutine dgemm
//Compute C = alpha*(op(A)*op(B)) + beta C
//where op(A) is either A or its transpose. Same for op(B).
//Return C
//alpha and beta are scalars
//A, B and C are matrices



extern "C" void sgemm_(char*,  //Set to "N" to use matrix A, i.e. op(A)=A (set to "T" to use its tranpose)
	    char*,           //Set to "N" to use matrix B, i.e. op(B)=B (set to "T" to use its transpose)
	    int*,             //Integer M=Number of rows of matrices op(A) and C.
	    int*,             //Integer N=Number of columns of matrices op(B) and C
	    int*,             //Integer K=Number of columns of matrix op(A) and number of rows of matrix op(B)  (equal).
	    float*,       //Real alpha
	    float*,        //Matrix A
	    int*,             //Integer LDA= Number of rows of matrix A in its declaration (larger or equal than M).
	    float*,       //Matrix B
	    int*,             //Integer LDB= Number of rows of matrix B in its declaration (larger or equal than K).
	    float*,      //Real beta
	    float*,      //Matrix C
	    int*             //Integer LDC= Number of rows of matrix C in its declaration (larger or equal than M).
	    );



//Subroutine dgemm
//Compute C = alpha*(op(A)*op(B)) + beta C
//where op(A) is either A or its transpose. Same for op(B).
//Return C
//alpha and beta are scalars
//A, B and C are matrices
extern "C" void dgemm_(char*,char*, int*, int*, int*, double*, double*, 
	    int*, double*,int*, double*, double*, int*);




/*
SGESV computes the solution to a real system of linear equations
    A * X = B,
 where A is an N-by-N matrix and X and B are N-by-NRHS matrices.

 The LU decomposition with partial pivoting and row interchanges is
 used to factor A as
    A = P * L * U,
 where P is a permutation matrix, L is unit lower triangular, and U is
 upper triangular.  The factored form of A is then used to solve the
 system of equations A * X = B.
 */


extern "C" void sgesv_(int*, int*, float*, int*, int*, float*, int*, int*);


extern "C" void dgesv_(int*, int*, double*, int*, int*, double*, int*, int*);

