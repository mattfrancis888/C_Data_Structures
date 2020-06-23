#include "markstats.h"

void add_data(MARKS *dsp, char *name, float score) {
// your implementation
	insert(&dsp->bst, name, score);
	int count = dsp->count;
	float mean = dsp->mean;
	float stddev = dsp->stddev;
	dsp->mean = ((count * mean + score) / (count + 1));
	float newmean = dsp->mean;
	dsp->stddev = sqrt((count*(stddev*stddev + mean*mean) + score*score)/(count+1) - newmean*newmean);
	dsp->count++;
}

void remove_data(MARKS *dsp, char *name) {
// your implementation
	TNODE *tn = search(dsp->bst, name);
	float score = tn->data.score;
	int count = dsp->count;
	float mean = dsp->mean;
	float stddev = dsp->stddev;
	dsp->mean = (count * mean - score)/(count - 1);
	float newmean = dsp->mean;
	dsp->stddev = sqrt(((stddev*stddev + mean*mean)*count - score*score)/(count-1) - newmean*newmean);
	dsp->count--;
	delete(&dsp->bst, name);
	
}

void display_marks(MARKS *dsp) {
  printf("grade report\n");  
  display_inorder(dsp->bst);    
  printf("\nstatistics summary\n");
  printf("%-15s%d\n", "count", dsp->count);
  printf("%-15s%3.1f\n", "mean", dsp->mean);
  printf("%-15s%3.1f\n", "stddev", dsp->stddev);
}

void clean_marks(MARKS *dsp) {
  clean_tree(&dsp->bst);
  dsp->count = 0;
  dsp->mean = 0;
  dsp->stddev = 0;
}

void import_data(MARKS *ds, char *filename) {
  char line[40], name[20];
  FILE *fp = fopen(filename, "r");
  char *result = NULL;
  float score = 0;
  char delimiters[] = ",\n";
  
  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    result = strtok(line, delimiters);
    if (result){
      strcpy(name, result);
      result = strtok(NULL, delimiters);
      score = atof(result);
      add_data(ds, name, score); 
    }
  }
  fclose(fp);
}

void print_to_file_inorder(TNODE *root, FILE *fp) {
  if (root){
    if (root->left) print_to_file_inorder(root->left, fp);
    fprintf(fp, "%-15s%3.1f%4c\n", root->data.name, root->data.score, letter_grade(root->data.score));
    if (root->right) print_to_file_inorder(root->right, fp);
  }
}

void report_data(MARKS *dsp, char *filename) {
  FILE *fp = fopen(filename, "w");
  fprintf(fp, "grade report\n");  
  print_to_file_inorder(dsp->bst, fp);
  fprintf(fp, "\nstatistics summary\n");
  fprintf(fp, "%-15s%d\n", "count", dsp->count);
  fprintf(fp, "%-15s%3.1f\n", "mean", dsp->mean);
  fprintf(fp, "%-15s%3.1f\n", "stddev", dsp->stddev);
  fclose(fp);
}

char letter_grade(float s){
  char r = 'F';
  if (s >= 85) r = 'A';
  else if (s >= 70) r = 'B';
  else if (s >= 60) r = 'C';
  else if (s >= 50) r = 'D';
  else r = 'F';
  return r;
}

