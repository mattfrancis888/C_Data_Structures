/*--------------------------------------------------
Project: cp264oc-a6q3
File:    a6q3.c
Description: test driver program
Author:  HBF  
Version: 2020-02-09
--------------------------------------------------
*/
#include "expeval.h"

int main(int argc, char *args[]) {
  char *infix = "9-((3*4)+8)/4";
  if (argc > 1) infix = args[1];

  printf("infix: %s\n", infix);  
  QUEUE postfix_queue = infix_to_postfix(infix);
  
  printf("postfix: ");
  display(postfix_queue.front);
  printf("\n");
    
  int val = evaluate_postfix(postfix_queue);
  printf("evaluation: %d", val);
  return 0;
}

/*
gcc common.c queue.c stack.c expeval.c  a6q3.c  -o a6q3
a6q3

infix: 9-((3*4)+8)/4
postfix: 9 3 4 * 8 + 4 / -
evaluation: 4
*/