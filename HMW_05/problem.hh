#ifndef PROBLEM_HH
#define PROBLEM_HH

#include <iostream>
#include <math.h>

template <typename T>
T bdy_term(T x){
	return cos(2*x);
}

template <typename T>
T source_term(T x){
	return -4*cos(2*x);
}

#endif