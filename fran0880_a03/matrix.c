//---------------------------------------------------------
#include "matrix.h"
void magic_square(int *m, int n) {
    /* assign 3X3 matrix to following values
     8     1     6
     3     5     7
     4     9     2
     */
    int values[9] = { 8, 1, 6, 3, 5, 7, 4, 9, 2 };
    int i, len = n*n, *p = values;
    for (i = 0; i < len; i++) *m++ = *p++;
}


//---------------------------------------------------------
void display_matrix(int *m, int n) {
    int *p = m, i, j;
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++) printf("%4d", *p++); 
    }
    printf("\n");
}

//---------------------------------------------------------
int is_magic_square(int *m, int n) {
// // your implementation
// There are n rows, n columns, and 2 diagonals to check.
    int i, j, rowsum, sum, offset,  *p;
    rowsum= n*(n*n+1)/2;
    int checks = 2*n+2; 
    for (j=0; j < checks;  j++) {
        if (j<n ) {  
            p = m+j*n;  
            offset = 1; 
        }   
     // this check all n rows
        else if (j<2*n) { 
            //check columns, first pointer, and offset
            p = m + (j - 3);
            offset = 3;
        }
        else if (j==2*n) {
        //   check positive diagonal, first pointer, and offset
            p = m;
            offset = 4;
        }
        else {
            p = m + 2; 
            offset = 2;
            //negative diagonal, first pointer, and offset 
        }
            sum = 0;
        for (i=0; i< n; i++) {
            sum += *p;
            p += offset;
        }
        if (sum != rowsum  ) return 0;
        // Check  n*n numbers, within range, and no two are same
        //..............................................
        if (sum != rowsum) return 0;
    }
    return 1;  
}

//---------------------------------------------------------
void transpose_matrix(int *m1, int *m2, int n) {
    //m2 represents the result of the matrix after going a transpose
    int i, j;
    for (i= 0; i< n; i++) {
        for (j = 0; j < n; j++) {
        // m2[j][i] = m1[i][j];   // won’t work,  represent by pointers  
        *(m2+j*n+i) = *(m1+i*n+j) ; //given at lecutre; the n repreesnts the # of columns and the * in the middle represents mutiplication@
        }
    }
}

//---------------------------------------------------------
void multiply_matrix(int *m1, int *m2, int *m3, int n) {    
    //m3 represents the result of the matrix after being multiplied
    int i, j, k, sum;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum = sum + *(m1 + i *n + k) * *(m2 + k *n + j);
            }
            *(m3 + i *n + j) = sum;
        }
    }
}