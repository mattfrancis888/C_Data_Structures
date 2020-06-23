/*
--------------------------------------------------
Project: cp264a4q1 
File:    a4q1.c  
Description: public test driver program
Author:  HBF
Version: 2020-01-30
--------------------------------------------------
*/ 
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

int main(int argc, char *args[]) {
  char infilename[40] = "textdata.txt"; //default input file name
  char outfilename[40] = "result.txt";  //default output file name
  char stopwordfilename[40] = "common-english-words.txt"; //default stop word file name
  if (argc > 1) {
    if (argc >= 2)
      strcpy(infilename, args[1]);
    if (argc >= 3)
      strcpy(outfilename, args[2]);
    if (argc >= 4)
      strcpy(stopwordfilename, args[3]);
  }
  //stop word dictionary as array of strings  
  char stopword_arrays[26][100] = { 0 }; 
  char *stopwords[26];
  int i;
  for (i = 0; i < 26; i++) {
    stopwords[i] = &stopword_arrays[i][0];
  }
  set_stopword(stopwordfilename, stopwords);
  printf("loading stop words done\n");
  WORDSUMMARY wordsummary = {0};
  process_word(infilename, &wordsummary, stopwords);
  printf("word processing done\n");
  save_to_file(outfilename, &wordsummary);
  printf("saving result to file done\n");
  
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