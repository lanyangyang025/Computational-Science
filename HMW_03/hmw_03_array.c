#include<stdio.h>

double mysquare(double);
double mycube(double);
void modif_array(double*, int, double(*f)(double));

int main(){
	double tab[3] = {2.0, 3.0, 4.0};
	int len = sizeof(tab)/sizeof(tab[0]);
	modif_array(tab, len, mysquare);
	for(int i=0; i<len; i++){
		printf("square result = %.3lf\n", tab[i]);
	}
	modif_array(tab, len, mycube);
	for(int i=0; i<len; i++){
		printf("cube result = %.3lf\n", tab[i]);
	}
	
}

double mysquare(double x){
	return x*x;
}

double mycube(double x){
	return x*x*x;
}

void modif_array(double* tab, int len, double(*f)(double)){
	for(int i=0; i<len; i++){
		*tab = (*f)(*tab);
		tab += 1;
	}
}
