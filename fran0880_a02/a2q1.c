#include <stdio.h>
#include <time.h>

int *la;
int *ha;

int iterative_fibonacci(int n)
{
    if (&n < la) la = &n;  // update the lowest memory address reached.
    int a,b=1,c=0;
    for(int i=0;i<n;i++){
        a=b;
        b=c;
        c=a+b;
    }
    return c;

    // if (n <=2) return 1;
    // else
    // {
    //     int f1=1,f2 =1, temp,i
    //     for(i = 3; i <=n; i++){
    //         temp = f2;
    //         f2 = f1 + f2;
    //         f1 = temp;
    //     }
    //     return f2;
    // }

}

int recursive_fibonacci(int n) {
    if (&n < la) la = &n;  // update the lowest memory address reached. 
    
    if (n<=1){
        return n;
    }
    else{
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
    }

    // if (n == 0) return 1;
   //  if (n <= 2) return 1;
   //  else return rfib(n-1) + rfib(n -2);

}

int main(){
    int i=0, n = 40;
    clock_t t1, t2; 
    int m1, m2;
    double time_span1, time_span2;
    
    printf("Iterative algorithm measurement:\n");
    
    //measuring memory span for iterative_fibonacci function
    ha = &i;
    la = ha;
    printf("iterative_fibonacci(%d): %d\n", n, iterative_fibonacci(n));
    printf("high address: %lu\n", ha);
    printf("low address: %lu\n", la);
    int memory_span1 = (unsigned long) ha - (unsigned long) la;
    printf("memory span: %d\n",memory_span1);

    //measuring runtime for iterative_fibonacci function
    m1 = 500000;
    t1=clock();
    for (i=0; i< m1; i++) {
        iterative_fibonacci(n);
    }
    t2=clock();
    time_span1 = (double) t2-t1;
    printf("time_span(iterative_fibonacci(%d) for %d times): %0.1f (ms)\n", n, m1, time_span1);
    
    printf("\nRecursive algorithm measurement:\n");
    
    // add your memory span and time span measuring for the recursive_fibonacci function
    //memory span
    ha = &i;
    la = ha;
    printf("iterative_fibonacci(%d): %d\n", n, recursive_fibonacci(n));
    printf("high address: %lu\n", ha);
    printf("low address: %lu\n", la);
    int memory_span2 = (unsigned long) ha - (unsigned long) la;
    printf("memory span: %d\n",memory_span2);
    //time span
    m2 = 10; 
    t1 = clock();
    for (i=0; i< m2; i++) {
        recursive_fibonacci(n);
    }
    t2 = clock();
    time_span2 = (double) t2 - t1;
    printf("time_span(recursive_fibonacci(%d) for %d times): %0.1f (ms)\n", n, m2, time_span2);
    // comparison
    printf("\nComparison of recursive and iterative algorithms:\n");
    printf("memory_span(recursive_fibonacci(%d))/memory_span(iterative_fibonacci(%d)): %0.1f\n", n, n, ((double) memory_span2)/memory_span1);
    printf("time_span(recursive_fibonacci(%d))/time_span(iterative_fibonacci(%d)): %0.1f\n", n, n, (time_span2/time_span1)*(m1/m2));
    
    return 0;
}