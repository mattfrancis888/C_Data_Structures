/*
--------------------------------------------------
Project: cp264-a8q1
File:    a8q1.c
Description: test driver program
Author:  HBF  
Version: 2020-03-03
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}


//creating own itoa because hb's itoa is not working
// function to reverse buffer[i..j]

char* reverse(char *buffer, int i, int j){
    while (i < j)
        swap(&buffer[i++], &buffer[j--]);
    return buffer;
}

char* itoa(int value, char* buffer, int base){
    // invalid input
    if (base < 2 || base > 32)
        return buffer;
    // consider absolute value of number

    int n = abs(value);
    int i = 0;
    while (n){
        int r = n % base;
        if (r >= 10)
            buffer[i++] = 65 + (r - 10);
        else
            buffer[i++] = 48 + r;
        n = n / base;
    }
    // if number is 0
    if (i == 0)
        buffer[i++] = '0';
    // If base is 10 and value is negative, the resulting string

    // is preceded with a minus sign (-)

    // With any other base, value is always considered unsigned

    if (value < 0 && base == 10)
        buffer[i++] = '-';
    buffer[i] = '\0'; // null terminate string
    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}

int main(int argc, char* args[])
{
  int n = 8;
  if (argc >1)  {
    n = atoi(args[1]);
  }

  printf("Build AVL by inserting key-value (i, i) for if from 0 to %d\n", n);
  TNODE *root = NULL, *np;
  int i;
  char name[20];
  for (i = 0; i < n; i++) {
    itoa(i, name, 10);  //itoa(int value, char *string, int radix), use number string as name
    insert(&root, name, i+0.0);  // use number i as score data
  }

  printf("Display tree: name, socre, height\n");
  display_tree(root, 0);
  
  printf("\nis_val:%d\n", is_avl(root));
  
  printf("Inorder traversal\n");
  display_inorder(root);
  
  printf("Delete nodes of even number keys\n");
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      itoa(i, name, 10);
      delete(&root, name);
    }
  }
  display_tree(root, 0);
  
  printf("\nis_val:%d\n", is_avl(root));
  
  display_inorder(root);
  clean_tree(&root);
  return 0;
}

/*
gcc avl.c a8q1.c -o a8q1
a8q1
|___3 3.0 4
    |___5 5.0 3
        |___6 6.0 2
            |___7 7.0 1
        |___4 4.0 1
    |___1 1.0 2
        |___2 2.0 1
        |___0 0.0 1
is_val:1
0              0.0
1              1.0
2              2.0
3              3.0
4              4.0
5              5.0
6              6.0
7              7.0
|___5 5.0 3
    |___7 7.0 1
    |___3 3.0 2
        |___1 1.0 1
is_val:1
1              1.0
3              3.0
5              5.0
7              7.0
*/