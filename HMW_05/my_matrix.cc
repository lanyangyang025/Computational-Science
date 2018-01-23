#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
//Create a header that contains the prototype of BLAS/LAPACK subroutines
#include "proto_blas_lapack.hh"
#include "my_matrix_.hh"

//Overloading operator * and |


template <>
my_matrix<float> my_matrix<float>::operator*(my_matrix<float>& m){
  try{
    if(this->columns != m.rows){
      throw "The two matrices are not compatible.";
    } 
    my_matrix<float> res(this->rows, m.columns);

    float alpha=1.0;
    float beta=0.0;

    float* temp1 = new float[rows*columns];
    for(int i=0; i<columns; i++){
      for(int j=0; j<rows; j++){
        temp1[rows*i+j] = pt[i][j];
      }
    }

    float* temp2 = new float[m.rows*m.columns];
    for(int i=0; i<m.columns; i++){
      for(int j=0; j<m.rows; j++){
        temp2[m.rows*i+j] = m.pt[i][j];
      }
    }

    float* temp3 = new float[rows*m.columns];

    sgemm_((char*) "N", (char*) "N", &this->rows, &m.rows, &this->columns, 
      &alpha, temp1, &this->rows, temp2, &this->columns, &beta, temp3, 
      &this->rows);

    for (int i=0; i<m.columns; i++){//columns
      for (int j=0; j<rows; j++){//rows
         res(j,i) = temp3[rows*i+j];
      }
    }
    return res;     
  }catch ( const char * e ){
    std :: cout << e << std :: endl ;
  }
}

template <>
my_matrix<double> my_matrix<double>::operator*(my_matrix<double>& m){
  try{
    if(this->columns != m.rows){
      throw "The two matrices are not compatible.";
    } 
    my_matrix<double> res(this->rows, m.columns);

    double alpha=1.0;
    double beta=0.0;

    double* temp1 = new double[rows*columns];
    for(int i=0; i<columns; i++){
      for(int j=0; j<rows; j++){
        temp1[rows*i+j] = pt[i][j];
      }
    }

    double* temp2 = new double[m.rows*m.columns];
    for(int i=0; i<m.columns; i++){
      for(int j=0; j<m.rows; j++){
        temp2[m.rows*i+j] = m.pt[i][j];
      }
    }

    double* temp3 = new double[rows*m.columns];

    dgemm_((char*) "N", (char*) "N", &this->rows, &m.rows, &this->columns, 
      &alpha, temp1, &this->rows, temp2, &this->columns, &beta, temp3, 
      &this->rows);

    for (int i=0; i<m.columns; i++){//columns
      for (int j=0; j<rows; j++){//rows
         res(j,i) = temp3[rows*i+j];
      }
    }

    return res;     
  }catch ( const char * e ){
    std :: cout << e << std :: endl ;
  }
}


template <>
my_matrix<float> my_matrix<float>::operator|(const my_matrix<float>& m){
  float* temp1 = new float[rows*columns];
  for(int i=0; i<columns; i++){
    for(int j=0; j<rows; j++){
      temp1[rows*i+j] = pt[i][j];
    }
  }
  float* temp2 = new float[m.rows*m.columns];
  for(int i=0; i<m.columns; i++){
    for(int j=0; j<m.rows; j++){
      temp2[m.rows*i+j] = m.pt[i][j];
    }
  }
  int n = columns;
  int lda = n;
  int nrhs = m.columns;
  int ldb = n;
  int ipiv[n], info;
  sgesv_(&n, &nrhs, temp1, &lda, ipiv, temp2, &ldb, &info );
  try{
    if( info > 0 ) {
      throw "The diagonal element of the triangular factor of A, so that A is singular";
    }else if(info < 0){
      throw "The argument had an illegal value";
    }
    my_matrix<float> res(columns, m.columns);
    for (int i=0; i<m.columns; i++){//columns
      for (int j=0; j<columns; j++){//rows
         res(j,i) = temp2[rows*i+j];
      }
    }

    return res;
  }catch ( const char * e ){
    std :: cout << e << std :: endl ;
  }
}


template <>
my_matrix<double> my_matrix<double>::operator|(const my_matrix<double>& m){
  double* temp1 = new double[rows*columns];
  for(int i=0; i<columns; i++){
    for(int j=0; j<rows; j++){
      temp1[rows*i+j] = pt[i][j];
    }
  }
  double* temp2 = new double[m.rows*m.columns];
  for(int i=0; i<m.columns; i++){
    for(int j=0; j<m.rows; j++){
      temp2[m.rows*i+j] = m.pt[i][j];
    }
  }
  int n = columns;
  int lda = n;
  int nrhs = m.columns;
  int ldb = n;
  int ipiv[n], info;
  dgesv_(&n, &nrhs, temp1, &lda, ipiv, temp2, &ldb, &info);
  try{
    if( info > 0 ) {
      throw "The diagonal element of the triangular factor of A, so that A is singular";
    }else if(info < 0){
      throw "The argument had an illegal value";
    }

    my_matrix<double> res(columns, m.columns);
    for (int i=0; i<m.columns; i++){//columns
      for (int j=0; j<columns; j++){//rows
         res(j,i) = temp2[rows*i+j];
      }
    }
    return res;
  }catch ( const char * e ){
    std :: cout << e << std :: endl ;
  }
}


