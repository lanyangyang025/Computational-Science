#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
//Create a header that contains the prototype of BLAS/LAPACK subroutines
#include "my_matrix_.hh"
#include "problem.hh"
#include "solver_poisson.hh"
#include "proto_blas_lapack.hh"

int main(int argc, char** argv){

//Part2 solving a Poisson problem with finite difference method
  if(argc != 4){
    printf("Enter the number of elements N>1 and the boundaries a<b of the domain when running the program.");
  }
  int N = atof(argv[1]);
  double a = atof(argv[2]);
  double b = atof(argv[3]);
  if(N <= 1){
    printf("Enter the number of elements N>1 when running the program.");
  }
  if(a >= b){
    printf("Enter the number of the boundaries a<b of the domain when running the program.");
  }
  my_matrix<double> U = solver_poisson(N, a, b);

  int u_row = U.get_row();
  int u_column = U.get_column();


  for (int i=0; i<u_row; i++){
    for (int j=0; j<u_column; j++){
      printf("%lf ", U(i,j));
    }
    printf("\n");
  }




/*Part1 question 4.a

  int m1_columns = 3;
  int m1_rows = 2;
  my_matrix<float> m1(m1_rows,m1_columns);

  for (int i=0; i<m1_rows; i++){//columns
    for (int j=0; j<m1_columns; j++){//rows
      m1(i,j) = 1.0;
    }
  }

  my_matrix<float> m3 = m1+m1;

  for (int i=0; i<m1_rows; i++){
    for (int j=0; j<m1_columns; j++){
      printf("%lf ", m3(i,j));
    }
    printf("\n");
  }
*/

/*Part2 question 4.b
  int m2_columns = 3;
  int m2_rows = 3;

  my_matrix<float> m2(m2_rows,m2_columns);

  for (int i=0; i<m2_rows; i++){//columns
    for (int j=0; j<m2_columns; j++){//rows
       m2(i,j) = 2.0;
    }
  }

  my_matrix<float> m4 = m1*m2;

  for (int i=0; i<m1_rows; i++){
    for (int j=0; j<m2_columns; j++){
      printf("%lf ", m4(i,j));
    }
    printf("\n");

  }
*/


/*test operator |

  int m1_columns = 2;
  int m1_rows = 2;
  my_matrix<double> m1(m1_rows,m1_columns);

  for (int i=0; i<m1_rows; i++){//columns
    for (int j=0; j<m1_columns; j++){//rows
      if(i == j){
        m1(i,j) = 1.0;
      }else{
        m1(i,j) = 0;
      }
    }
  }

  int m2_columns = 1;
  int m2_rows = 2;

  my_matrix<double> m2(m2_rows,m2_columns);

  for (int i=0; i<m2_rows; i++){//columns
    for (int j=0; j<m2_columns; j++){//rows
      if(i == j){
        m2(i,j) = 3.0;
      }else{
        m2(i,j) = 2;
      }
    }
  }

  my_matrix<double> m4 = m1|m2;

  for (int i=0; i<m1_columns; i++){
    for (int j=0; j<m2_columns; j++){
      printf("%lf ", m4(i,j));
    }
    printf("\n");
  }


*/

  return 0;
}
