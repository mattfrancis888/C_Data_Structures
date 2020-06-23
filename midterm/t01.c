int *la;
int iterative_fibonacci(int n)
{
   if (n == 0) return 0;
   else if (n <=2) return 1;
    else
    {
        int f1=1,f2 =1, temp,i;
        for(i = 3; i <=n; i++){
            temp = f2;
            f2 = f1 + f2;
            f1 = temp;
        }
        return f2;
    }
}

int rfib(int n) {
    if(n == 0) return 0;
    if (n <= 2) return 1;
    else return rfib(n-1) + rfib(n -2);
}

int iterative_factorial() {
    int n, i;
    unsigned long long fact = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    // shows error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("Factorial of %d = %llu", n, fact);
    }
    return 0;
}
//https://www.programiz.com/c-programming/examples/factorial

int recursive_factorial(int n)
{
   //Factorial of 0 is 1 
   if(n==0)
      return(1);
 
   //Function calling itself: recursion
   return(n*recursive_factorial(n-1));
}
//https://beginnersbook.com/2014/06/c-program-to-find-factorial-of-number-using-recursion/