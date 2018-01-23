#ifndef SOLVER_POISSON_HH
#define SOLVER_POISSON_HH

#include <iostream>
#include <math.h>
#include "my_matrix_.hh"
#include "proto_blas_lapack.hh"



// solver poisson  function
template <typename T>
my_matrix<T> solver_poisson(int N, T a, T b){
	my_matrix<T> F(N,1);
	F(0,0) = bdy_term(a);
	F(N-1,0) = bdy_term(b);
	double h = 1.0*(b-a)/(N-1);
	for(int i=1; i<N-1; i++){
		F(i,0) = source_term(a+i*h);
	}


	my_matrix<T> A(N,N);

	//A matrix, the change of the A matrix should be the same as the update question 6.b, the change of the source term
	A(0,0) = 1;
	A(N-1,N-1) = 1;
	for(int i=1; i<N-1; i++){
		A(i,i-1) = 1.0/(h*h);
		A(i,i) = -2.0/(h*h);
		A(i,i+1) = 1.0/(h*h);
	}

	//retrive matrix U and print
	my_matrix<double> U = A|F;


	FILE *fpt;
	fpt = fopen("my_solution", "w");

	for (int i=0; i < N;i++){
		for(int j=0; j<1; j++){
		  fprintf(fpt, "%.5lf ",a+i*h);
		  fprintf(fpt, "%.5lf ", U(i,j));  
		}
		fprintf(fpt, "\n");
	}
	fclose(fpt);

	return U;
}

#endif