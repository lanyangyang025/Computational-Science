#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MATRIX_2D_H
#define MATRIX_2D_H

//author: Chuanwenjie Wei, Yiqing Lu
//matrix_2D.h

typedef struct{
  int rows, columns;

  double **pt;

  char *tag;
  
  int status;

}matrix;

matrix matrix_constructor(int n1, int n2, char *tag);

void matrix_destructor(matrix *m);

void matrix_set(matrix m, int rows, int columns, double value);

double matrix_get(matrix m, int rows, int columns);

matrix matrix_add(matrix m1, matrix m2, char *tag);

matrix matrix_product(matrix m1, matrix m2, char *tag);

matrix matrix_read(char *filename, char *tag);

void matrix_write(matrix m);

#endif
