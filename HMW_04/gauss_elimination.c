#include "matrix_2D.h"
#include "gauss_elimination.h"

//author: Yiqing Lu, Chuanwenjie Wei

//Implementation of Gauss elimination method
matrix matrix_gauss_inverse(matrix m, char *tag){
	matrix res;
	res.tag = tag;

	//not a square matrix and set to a NULL matrix
	if(m.rows != m.columns){
		printf("The matrix is not a square matrix.\n");
		res.tag = NULL;
		res.pt = NULL;
		return res;
	}
	res.rows = m.rows;
	res.columns = m.columns;

    //identity matrix
	double **array = (double **) malloc ( m.rows * sizeof (double *));
	for (int i =0; i < m.rows ; i ++){
		array[i] = (double *) malloc ( m.columns * sizeof (double));
	}

	for(int i=0; i<m.rows; i++){
		array[i][i] = 1;
	}

	//Gauss elimination method
	for(int i=0; i<m.rows; i++){
		//if m.pt[i][i] == 0, swap the row to the row where m.pt[j][i] != 0
		if(m.pt[i][i] == 0){
			int j = i+1;

			while(j<m.rows && m.pt[j][i] == 0){
				j++;
			}
			//not invertible and set to a zero matrix
			//in this case, we want to set the matrix m to upper triangular matrix
			//rows from 0 to (i-1) are set correctly, but the element of i column are all 0 from ith row to the last row
			//the rank of matrix m < m.rows
			if(j == m.rows){
				for(int p = 0; p<m.rows; p++){
					for(int q=0; q<m.columns; q++){
						m.pt[p][q] = 0;
					}
				}
				return res;
			}
			matrix_swap_row(m, i, j);
		    array_swap(array, i, j, m.columns);
		}


		//set m.pt[i][i] to 1
	    double div = m.pt[i][i];
		matrix_divide_row(m, i, div);
	    array_divide(array, i, div, m.columns);

	    //set the ith column from row i+1 to the last row to 0
		for(int j=i+1; j<m.rows; j++){
			double r1 = m.pt[j][i];
			matrix_subtract_row(m, j, i, r1);
		    array_subtract(array, j, i, r1, m.columns);			
		}
	}

	//set to lower triangular matrix
	for(int j = m.rows-2; j>=0; j--){
			
		for(int i=j+1; i<m.rows; i++){
			double r2 = m.pt[j][i];
			matrix_subtract_row(m, j, i, r2);
			array_subtract(array, j, i, r2, m.columns);
		}
	}

	res.pt = array;
	return res;
}

//swap the row in array
void array_swap(double **array, int n1, int n2, int columns){
    for(int k = 0; k < columns; k ++){
        double v = array[n1][k];
        array[n1][k] = array[n2][k];
        array[n2][k] = v;
    }
}

//divide the row in array with parameter r
void array_divide(double **array, int n1, double r, int columns){
    for(int k = 0; k < columns; k ++){
        array[n1][k] /= r;
    }
}

//subtract row n1 to row n2 * r
void array_subtract(double **array, int n1, int n2, double r, int columns){
	for(int k=0; k<columns; k++){
		array[n1][k] -= r*array[n2][k]; 
	}
}

//swaps the row n1 with the row n2 of the input matrix
void matrix_swap_row(matrix m, int n1, int n2){
  if(n1 < 0 || n1 >= m.rows || n2 < 0 || n2 >= m.rows){
    printf("Error when swapping the matrix %s: index out of bounds in matrix\n", m.tag);
    return ;
  }
  if(m.status == 0){
    printf("Error when swapping the matrix %s: the status is 0.\n", m.tag);
    return ;
  }
  for(int k = 0; k < m.columns; k ++){
        double v = m.pt[n1][k];
        m.pt[n1][k] = m.pt[n2][k];
        m.pt[n2][k] = v;
    }
}

//divides the elements of the row n1 of the input matrix by the real r
void matrix_divide_row(matrix m, int n1, double r){
  if(n1 < 0 || n1 >= m.rows){
    printf("Error when dividing the row in matrix %s: index out of bounds in matrix\n", m.tag);
    return ;
  }
  if(r == 0){
  	printf("Error when dividing the row in matrix %s: the divisor couldn't be 0.\n", m.tag);
  	return ;
  }

  if(m.status == 0){
    printf("Error when dividing the row in matrix %s: the status is 0.\n", m.tag);
    return ;
  }

  for(int i=0; i<m.columns; i++){
  	m.pt[n1][i] /= r;
  }
  
}

//subtracts from the row n1 of the input matrix, the row n2 multiplied by the real r
void matrix_subtract_row(matrix m, int n1, int n2, double r){
  if(n1 < 0 || n1 >= m.rows || n2 < 0 || n2 >= m.rows){
    printf("Error when subtracting the row in matrix %s: index out of bounds in matrix\n", m.tag);
    return ;
  }

  if(m.status == 0){
    printf("Error when subtracting the row in matrix %s: the status is 0.\n", m.tag);
    return ;
  }

  for(int i=0; i<m.columns; i++){
  	m.pt[n1][i] -= r*m.pt[n2][i];
  }
}