#include<stdio.h>
#include<stdlib.h>
 
float horner(float *p, int n, float x);
float bisection(float *p, int n, float a, float b);

float horner(float *p, int n, float x)
{
   // your implementation
   int r = 0, i;
   for(i= 0; i< n; i++){
    r = r * x + *(p + i); 
   }  
   return r;
}

//your bisection method implementation
float bisection(float *p, int n, float a, float b)
{

    float tol = 1e-6;
    float c = (a+b)/2;
    while( horner(p,n,c) > tol){
        c = (a+b)/2;
        float hornerc = horner(p, n, c);
        float hornera = horner(p, n, a);

        if( abs(hornerc) < tol && (c - a) < tol ){
            return c;
        } else if( (hornerc < 0  && hornera < 0)  || (hornerc >= 0  && hornera>= 0) ) {
            a = c;
        } else {
            b = c;
        }
    }
    return c;
}