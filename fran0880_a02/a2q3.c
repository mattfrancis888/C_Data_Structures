/*
--------------------------------------------------
Project: cp264a2q3 bisection algorithm 
File:    a2q3.c    test driver
Author:  HBF
Version  2020-01-13
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "bisection.h"

int main(int argc, char* args[])
{	
	float p[] = {1, 2, 3, 4};
	int n = 4;
	float a = -2, b = 2;
	
	float pa = horner(p, n, a);
	float pb = horner(p, n, b);
	printf("f(%f): %f\n", a, pa);
	printf("f(%f): %f\n", b, pb);
		
	if (pa * pb < 0) { // theres a root between x and y
	   float r = bisection(p, n, a, b);	
	   printf("root: %f\n", r);
	   printf("f(%f): %f\n", r, horner(p, n, r));
	}
	return 0;
}

/*
gcc bisection.h a2q3.c -o a2q3
a2q3

f(-2.000000): -2.000000
f(2.000000): 26.000000
root: -1.650629
f(-1.650629): 0.000001
*/
