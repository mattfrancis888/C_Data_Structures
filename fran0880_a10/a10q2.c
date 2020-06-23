/*
--------------------------------------------------
Project: cp264-a10q2
File:    a10q2.c
Description: test driver program
Author:  HBF  
Version: 2020-03-21
--------------------------------------------------
*/ 

#include <stdio.h>
#include "edgelist.h"

int main(){
  EDGELIST *elg = new_edgelist();  
  add_edge_end(elg, 0, 2, 3);
  add_edge_end(elg, 2, 1, 4);
  add_edge_end(elg, 1, 3, 9);
  add_edge_end(elg, 1, 4, 11);    
  display_edgelist(elg);
  printf("\nweight: %d", weight_edgelist(elg));
  clean_edgelist(&elg);
  printf("\ngraph is deleted");
  return 0;
}

/*
gcc edgelist.c a10q2.c -o a10q2
a10q2

weighted graph in edge list
size: 4
format: (from, to, weight)
(0, 2, 3)
(2, 1, 4)
(1, 3, 9)
(1, 4, 11)
weight: 27
graph is deleted
*/