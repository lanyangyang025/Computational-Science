#include "matrix_2D.h"

//author: Yiqing Lu, Chuanwenjie Wei
//matrix_2D.c

//create a matrix
matrix matrix_constructor(int n1, int n2, char *tag){
  matrix m;
  m.tag = strdup(tag);
  m.rows = n1;
  m.columns = n2;
  if(n1 <= 0 || n2 <=0){
  	printf("Error when constructing the matrix %s: the dimension of the matrix should > 0.\n", m.tag);
  	m.status = 0;
  	return m;
  }
  double **pt_temp = (double **) malloc ( n1 * sizeof (double *));
  for (int i =0; i < n1 ; i ++){
    pt_temp[i] = (double *) malloc ( n2 * sizeof (double));
  }
  m.status = 1;
  m.pt = pt_temp;
  return m;
}

//delete a matrix
void matrix_destructor(matrix *m){
  free(m->pt);
  m->rows = 0;
  m->columns = 0;
  m->status = 0;
}

//set the element value of the matrix
void matrix_set(matrix m, int rows, int columns, double value){
  if(rows < 0 || rows >= m.rows || columns < 0 || columns >= m.columns){
    printf("Error when setting the matrix %s: index out of bounds in matrix.\n", m.tag);
    return ;
  }
  if(m.status == 0){
    printf("Error when setting the matrix %s: the status is 0.\n", m.tag);
    return ;
  }
  m.pt[rows][columns] = value;
}

//get the value of the element in the matrix
double matrix_get(matrix m, int rows, int columns){
  if(rows < 0 || rows >= m.rows || columns < 0 || columns >= m.columns){
    printf("Error when getting the matrix %s: index out of bounds in matrix.\n", m.tag);
    return 0.0;
  }
  if(m.status == 0){
    printf("Error when geting the matrix %s: the status is 0.\n", m.tag);
    return 0.0;
  }
  return m.pt[rows][columns];
}

//add two matrices
matrix matrix_add(matrix m1, matrix m2, char *tag){
  matrix res;
  res.tag = strdup(tag);

  if(m1.rows != m2.rows || m1.columns != m2.columns){
  	printf("Error when adding two matrices to %s: The dimensions of the two matrices are not the same.\n", tag);
    res.pt = NULL;
    res.status = 0;
    return res;
  }
  if(m1.status == 0 || m2.status == 0){
    printf("Error when adding two matrices to %s: the status is 0.\n", tag);
    res.pt = NULL;
    res.status = 0;
    return res;
  }
  res = matrix_constructor(m1.rows, m1.columns, tag);
  for(int i=0; i<m1.rows; i++){
    for(int j=0; j<m1.columns; j++){
      matrix_set(res, i, j, matrix_get(m1, i, j)+matrix_get(m2, i, j));
    }
  }

  return res;
}

//multiply two matrices
matrix matrix_product(matrix m1, matrix m2, char *tag){
  matrix res;
  res.tag = strdup(tag);
  
  if(m1.rows != m2.rows || m1.columns != m2.columns){
  	printf("Error when multiplying two matrices to %s: The dimensions of the two matrices are not the same.\n", tag);
    res.pt = NULL;
    res.status = 0;
    return res;
  }

  if(m1.status == 0 || m2.status == 0){
    printf("Error when multiplying two matrices to %s: the status is 0.\n", tag);
    res.pt = NULL;
    res.status = 0;
    return res;
  }
  res = matrix_constructor(m1.rows, m1.columns, tag);
  for(int i=0; i<m1.rows; i++){
    for(int j=0; j<m1.columns; j++){
      matrix_set(res, i, j, matrix_get(m1, i, j)*matrix_get(m2, i, j));
    }
  }

  return res;
}

//read the matrix from a file
matrix matrix_read(char *filename, char *tag){
  matrix m;

  FILE *fpt;
  fpt = fopen(filename, "r");
  int rows, columns;
  fscanf(fpt,"%d",&rows);
  fscanf(fpt,"%d",&columns);

  m = matrix_constructor(rows, columns, tag);
  
  double value;
  for (int i=0; i < rows;i++){
    for(int j=0; j<columns; j++){
      fscanf(fpt, "%lf", &value);
      m.pt[i][j] = value;    
    }
  }
  fclose(fpt);
  return m;
}

//write a matrix to a file
void matrix_write(matrix m){
  FILE *fpt;
  fpt = fopen(m.tag, "w");
  fprintf (fpt, "%d ", m.rows);
  fprintf (fpt, "%d\n", m.columns);

  for (int i=0; i < m.rows;i++){
    for(int j=0; j<m.columns; j++){
      fprintf(fpt, "%.5lf ", m.pt[i][j]);   
    }
    fprintf(fpt, "\n");
  }
  fclose(fpt);
}

