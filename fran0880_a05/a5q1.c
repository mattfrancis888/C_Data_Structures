/*
--------------------------------------------------
Project: cp264oa5q1
File:    a5q1.c
Description: test driver program
Author:  HBF
Version: 2020-02-04
--------------------------------------------------
*/ 
#include "record_llist.h"

int main(int argc, char* args[]) {
  char infilename[40] = "marks.txt";
  char outfilename[40] = "report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  

  NODE *start = NULL; //null address
  import_data(&start, infilename);
  display(start);

  insert(&start, "Moore", 92.0); //insert to *start address
  NODE *p = search(start, "Moore");
  if (p == NULL)
    printf("Not Fount\n");
  else
    printf("Found:%s, %5.2f\n", p->data.name, p->data.score);
  delete(&start, "Wang");
  report_data(start, outfilename);
  clean(&start);
  return 0;
}
