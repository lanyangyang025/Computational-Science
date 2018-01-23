#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_2D.h"

#ifndef GAUSS_ELIMINATION_H
#define GAUSS_ELIMINATION_H

//author: CHuanwenjie Wei, Yiqing Lu
//gauss_elimination.h

matrix matrix_gauss_inverse(matrix m, char *tag);

void matrix_swap_row(matrix m, int n1, int n2);

void matrix_divide_row(matrix m, int n1, double r);

void matrix_subtract_row(matrix m, int n1, int n2, double r);

void array_swap(double **array, int n1, int n2, int columns);

void array_divide(double **array, int n1, double r, int columns);

void array_subtract(double **array, int n1, int n2, double r, int columns);

#endif