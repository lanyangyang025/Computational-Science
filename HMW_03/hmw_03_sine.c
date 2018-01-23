#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int myfactorial(int);
double mysin(double, double);
int main(int argc , char ** argv){
	if(argc != 3){
		printf("Need three arguments: executable, real x (double) and tolerance eps (double).\n");
		return 0;
	}
	double x = atof(argv[1]);
	double eps = atof(argv[2]);
	printf("sin(%.4lf) = %.10lf\n", x, sin(x));
	printf("mysin(%.4lf) = %.10lf\n", x, mysin(x, eps));
	return 0;
}

int myfactorial(int x){
	int res = 1;
	for(int i=1; i<=x; i++){
		res *= i;
	}
	return res;
}

double mysin(double x, double eps){
	int n = 0;
	double sum = 0;
	while(1.0 * pow(x, 2*n+3)/myfactorial(2*n+3) > eps){
		sum += pow(-1,n)*pow(x, 2*n+1)/myfactorial(2*n+1);
		n++;
	}
	sum += pow(-1,n)*pow(x, 2*n+1)/myfactorial(2*n+1);

	return sum;
}