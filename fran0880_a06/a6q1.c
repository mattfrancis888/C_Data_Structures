/*--------------------------------------------------
Project: cp264oc-a6q1
File:    a6q1.c
Description: test driver program
Author:  Matthew Francis  
Version: 2020-02-26
--------------------------------------------------
*/
 
#include <stdio.h>
#include <malloc.h> 
#include "common.h"
#include "queue.h"

int main(int argc, char* args[]) {

  char str[] = "9-((3*4)+8)/4";
  printf("enqueue: %s\n", str);
  
  // create a queue to store the infix expression
  QUEUE q = {0}; //why not *q? 
  char *p = str;
  while (*p) {
    if (*p >= '0' && *p <= '9') 
      enqueue(&q, new_node(*p-'0', 0));
    else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%')
       enqueue(&q, new_node(*p, 1));
    else if (*p == '(')
       enqueue(&q, new_node(*p, 2));
    else if (*p == ')')
       enqueue(&q, new_node(*p, 3));
    else 
       printf("invalid symbol\n");	
    p++;
  }
   
  printf("display queue: ");
  display(q.front);
  printf("\n");
  
  printf("dequeue: ");
  NODE *np = NULL;  
  while (q.front) {
    np = dequeue(&q);
    if (np->type == 0) 
      printf("%d ", np->data);
    else 
      printf("%c ", np->data);  
  
    free(np);
  }
  
  clean_queue(&q);
    
  return 0;
}

/*
gcc common.c queue.c a6q1.c -o a6q1
a6q1

enqueue: 9-((3*4)+8)/4
display queue: 9 - ( ( 3 * 4 ) + 8 ) / 4
dequeue: 9 - ( ( 3 * 4 ) + 8 ) / 4
*/