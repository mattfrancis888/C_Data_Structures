/*
--------------------------------------------------
Project: cp264a4q2
File:    a4q2.c  
Description: public test driver program
Author:  HBF
Version: 2020-01-30
--------------------------------------------------
*/  
#include "myrecord.h"

int main(int argc, char *args[]) {
  char infilename[40] = "marks.txt";   //default input file name
  char outfilename[40] = "report.txt"; //default output file name
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  
  RECORD dataset[MAX_REC];
  int record_count = 0;  
  record_count = import_data(dataset, infilename); 
  if (record_count >=1) { 
    report_data(dataset, record_count, outfilename);
	printf("output to file\n");
  } 
  else 
    printf("no data, no output to file\n");
  
  FILE *fp =fopen(outfilename, "r");
  if ( fp == NULL ) {
    printf("output file does not exist\n");
    return 0;
  }
  char buf[100];
  while( !feof(fp) ) {
     fgets(buf, sizeof(buf), fp);
     printf("%s", buf);
  }
  fclose(fp);
  
  return 0;
}