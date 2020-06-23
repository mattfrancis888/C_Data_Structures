/*--------------------------------------------------
Project: cp264oc-a6q2
File:    a6q2.c
Description: test driver program
Author:  Matthew Francis  
Version: 2020-02-26
--------------------------------------------------
*/

#include <stdio.h>
#include <malloc.h> 
#include "common.h" 
#include "stack.h"

int main(int argc, char* args[]) {
  STACK stack = {0};
  char str[] = "0123456789+-*/%()";
  printf("push: %s\n", str);
  
  char *p = str;
  while (*p) {
    if (*p >= '0' && *p <= '9') 
   	   push(&stack, new_node(*p-'0', 0));
    else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%')
       push(&stack, new_node(*p, 1));
    else if (*p == '(')
       push(&stack, new_node(*p, 2));
    else if (*p == ')')
       push(&stack, new_node(*p, 3));
    else 
       printf("invalid symbol\n");	
    p++;
  }
    
  printf("display stack: ");
  display(stack.top);
  printf("\n");
  
  printf("pop: ");
  NODE *np = NULL;  
  while (stack.top) {
    np = pop(&stack);
      if (np->type == 0) 
      printf("%d ", np->data);
    else 
      printf("%c ", np->data);  
    free(np);
  }
  printf("\n");
  clean_stack(&stack);
  
  return 0;
}

