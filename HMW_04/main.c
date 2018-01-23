#include "matrix_2D.h"
#include "gauss_elimination.h"

//arthor: Yiqing Lu, Chuanwenjie Wei
//main function



int main(void){

  //read files
  matrix ma = matrix_read("matrix_A.txt", "ma");
  matrix mb = matrix_read("matrix_B.txt", "mb");

  //add ma and mb and write to file
  matrix maplusb = matrix_add(ma, mb, "maplusb");
  matrix_write(maplusb);

  //multiply ma and mb and write to file
  matrix maxb = matrix_product(ma, mb, "maxb");
  matrix_write(maxb);

  //inverse ma and write to file
  matrix ma_inverse = matrix_gauss_inverse(ma, "ma_inverse");
  matrix_write(ma_inverse);

  //inverse mb and write to file
  matrix mb_inverse = matrix_gauss_inverse(mb, "mb_inverse");
  matrix_write(mb_inverse);

  //free the storage
  matrix_destructor(&ma);
  matrix_destructor(&mb);
  matrix_destructor(&maplusb);
  matrix_destructor(&maxb);
  matrix_destructor(&ma_inverse);
  matrix_destructor(&mb_inverse);
}
