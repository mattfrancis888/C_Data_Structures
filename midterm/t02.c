//refer to a02 horner's a2q2
float horner(float p[], int n, float x)
{
   int r = 0, i;
   for(i= 0; i< n; i++){
    r = r * x + *(p + i); //where p represent the coefficients from the argument eg; {1,2,3,4}
                        //n represents the size of the arguments - 1
                        //x represents the user input
   }  
   return r;
}