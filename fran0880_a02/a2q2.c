#include<stdio.h>
#include<stdlib.h>
#include <math.h>
float horner(float p[], int n, float x)
{
// your implementation
    int i, power, y;
    float result;
    power = n;
    for(i = 0; i < n; ++i){ 
        power = power - 1;
        result = result + p[i] * pow(x, power);  //eg; 1.0 * 0.0 ^ 3 + 2.0

        if(i == 0) printf("%.1f * %.1f^%d", p[i], x, power);
        else printf(" + %.1f * %.1f^%d", p[i], x, power);


    //SHYAM DAVES WAY:
        // int r = 0, i;
        // for (i = 0; i < n; i++){
        //     r = r * x + p[i];
        // }
        // return r;
    }

    //NOTE TO SELF: TRIED USING POWER WITHOUT MAHT LIB BUT DOSENT WORK!!!
    // for(i = 0; i < n; ++i){ 
    //     power = power - 1;
    //     int powerResult; = x;
    //     for(y = 0; y < power; ++y){
    //         powerResult = powerResult * x;
    //     }
    //     result = result + p[i] * powerResult;  //eg; 1.0 * 0.0 ^ 3 + 2.0
    //     if(i == 0) printf("%.1f * %.1f^%d", p[i], x, power);
    //     else printf(" + %.1f * %.1f^%d", p[i], x, power);
    // }

    printf(" = %.1f \n", result);
}
 
int main(int argc, char* args[])
{   
    //get polynomial efficients from command line arguments
    if (argc <= 1) {
        printf("Need more than one arguments, e.g.: 1 2 3 4\n");
        return 0;
    }
    int i, n = argc-1;
    // declare float array data structure for coefficients
    // read command line arguments convert them to floating numbers atof(args[i+1]);
    float coef_array[n];
   // printf("args %.1f", atof(args[2])); //2 .0
    for (i = 0; i < n; i++){
        coef_array[i] = atof(args[i + 1]); // note to self: args start at 1
    }
    // repetitive polynomial evaluation for user input of x value
    float x = 0.0;
    do {
        //get x value from keyboard
        printf("Please enter x value (Ctrl+C or 999 to quit): \n");
        do {
            if (scanf("%f", &x) != 1) {
                printf("Invalid input\n");
            } else {            
                break;
            }
            // handle invalid input 
            //while(getchar() !='\n') ; 
            do {
                if (getchar() == '\n') break;
            } while (1);
        } while (1);

        if(x != 999){
            horner(coef_array, n, x);
            // escape when input 999
            // print the polynomial expression
            // use x^n to denote x raised to the n-th power
            // use %.1f format for floating number
            // print polynomial by calling horner(p, n, x)
        }
        else break;
    
    } while (1);
    //strcmp("999", input) != 0
    return 0;
}