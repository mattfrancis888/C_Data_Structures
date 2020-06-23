// add your signature
//if you have *ptr = &x and you do print(ptr) [or *&ptr] you get the address of x stored in memory 
//note to me: LINKED_LIST IS BASIALLY *ptr1 = ptr2 (which means address of a var stored in ptr2); refer to "Pointers in C vid" 
#include "record_llist.h"
void display(NODE *start) {
// your implementation

  //start works as an address of NODE *start
  if(start == NULL){printf("Empty\n"); return;}
	NODE *ptr = start;
	while(ptr != NULL){
    printf("%s \t %5.1f \n",ptr->data.name, ptr->data.score);
     ptr = ptr->next;
  }
}

NODE* search(NODE *startp, char *name) {
// your implementation
  if(startp == NULL) return NULL;  // start == NULL
	NODE *ptr = startp;	// NODE *start
	while((ptr != NULL) && ((strcmp((ptr->data.name), name)) != 0)){
    ptr = ptr->next;
  } // stop loop when ptr->data.name is identical to parameter name
	return ptr;	// return ptr node that has same name as the parameter name
    
}



void insert(NODE **startp, char *name, float score) {
// your implementation
  //uses a double pointer because you cannot change a node with single pointers
  //repl example: https://repl.it/@matthewfrancis/why-you-need-double-pointers-for-nodes

  // the creation of the node and -> is at struct slides
    NODE *np = (NODE*) malloc (sizeof(NODE)); //creates a node that also gives the address
    strcpy(np->data.name, name);  //hence this is valid
    np->data.score = score; //notice how we refer to address of what the pointer,np, holds (we are not doing *np to get the value of the poitner)
    //for ex; *aptr = &x; *aptr holds the address of x, we get it by printf(aptr)
    //we still use -> because an address is still considered a pointer (@Brandon)
    NODE *ptr = *startp; // *ptr = start [due to *&startp]; start is an address of what the pointer,start, holds
     //notice how it's essentialy like *aptr = &x because *startp is an address of what the pointer, start, holds :)!
    NODE *prev_ptr = NULL;
    while((ptr != NULL) && (strcmp(ptr->data.name,name) < 0)) {
      prev_ptr = ptr; 
      ptr = ptr->next; //get next address; notice how we manipulate nodes by address of what the pointer holds = address of what the pointer holds
    }
	  if(prev_ptr == NULL) {
      np->next = *startp;  //just like np->data.score = score above; we can conclude that
      //to manipulate a node, we need to refer to the address of what the pointer holds
      //we make it equal to another addrss; so that later the node could change the values like np->data.score = score above
      *startp = np;
    } // first
    else {
      np->next = ptr;
      prev_ptr->next = np;
    } // insert in ascii order
}

int delete(NODE **startp, char *name) {
// your implementation
    NODE *ptr = *startp; //addres of NODE *start
    NODE *prev_ptr = NULL; 
    while((ptr != NULL) && 
      (strcmp(ptr->data.name, name)!=0)){ //stop if data.name == 0
        prev_ptr = ptr; 
        ptr = ptr->next;
    }
	if(ptr == NULL) return 0; // if name wasnt found
	if(prev_ptr == NULL) {
    *startp = ptr->next; 
    free(ptr); // if name was found at start; skipped loop sp prev_ptr remains null
  } else{ //name was found
    prev_ptr->next = ptr->next; 
    free(ptr);
  }
}

void clean(NODE **startp) {
// your implementation
//get rid of everything
// Refer to code example https://bohr.wlu.ca/hfan/cp264/examples/simple_linked_list.c 
	NODE *ptr = *startp, *prev_ptr = NULL;
	while(ptr != NULL) {
    prev_ptr = ptr;
    ptr = ptr->next; 
    free(prev_ptr);
  }
	free(prev_ptr); // loop doesnt free last node
	*startp = NULL;
}

// the following functions are adapted and modified from previous assignments. You make use of them. 

void report_data(NODE *start, char *filename) {
  NODE *np = start;
  int count = 0;
  float mean = 0;
  float stddev = 0;
  int histogram[6] = {0};
  FILE *fp = fopen(filename, "w");

  fprintf(fp, "grade report\n");  
  while (np != NULL) {
    count++;
    mean += np->data.score;
    stddev += np->data.score * np->data.score ;
      //histogram data
    if (np->data.score >=100)  histogram[0]++;
    else if (np->data.score < 50)  histogram[5]++;
    else histogram[(unsigned int) (99.99-np->data.score)/10]++;
    
    fprintf(fp, "%-15s%3.1f%4c\n", np->data.name, np->data.score, letter_grade(np->data.score));
    np = np->next;
  }
  mean /= count;
  stddev = sqrt(stddev/count - mean*mean);
  
  fprintf(fp, "\nstatistics summary\n");
  fprintf(fp, "%-15s%d\n", "count", count);
  fprintf(fp, "%-15s%3.1f\n", "mean", mean);
  fprintf(fp, "%-15s%3.1f\n", "stddev", stddev);
  fprintf(fp, "%-15s%3.1f\n", "median", median(start));
  
  fprintf(fp, "histogram\n");
  int i;
  fprintf(fp, "%-15s%d\n", "[90,100]", histogram[0]);
  for (i=1; i<5; i++) {
     fprintf(fp, "[%d,%d)        %d\n", 90-i*10, 100-i*10, histogram[i]);
  }
  fprintf(fp, "%-15s%d\n", "[0,50)", histogram[5]);
  
  fclose(fp);
}

void import_data(NODE **startp, char *filename) {
  char line[40], name[20];
  FILE *fp = fopen(filename, "r");
  char *result = NULL;
  char delimiters[] = ",";
  float score = 0;

  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    result = strtok(line, delimiters);
    strcpy(name, result);
    result = strtok(NULL, delimiters);
    score = atof(result);
    insert(startp, name, score);
  }
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

void swap(float *first, float *second )
{
  float temp = *first;
  *first = *second;
  *second = temp;
}
  
void quick_sort(float *a, int left, int right)
{ 
  float key;
  int i,j;
  if( left < right ) {  
    key = *(a+left);
    i = left+1;
    j = right;
    while(i <= j) {
      while( i <= right && *(a+i) <= key) i++;
      while( j >= left && *(a+j) > key ) j--;
      if( i < j) swap(a+i, a+j);
    }    
    swap(a+left, a+j);
    quick_sort(a, left, j-1);
    quick_sort(a, j+1, right); 
  }
}

float median(NODE *start)
{
  if (start == NULL) return 0;
  int len = 0, i=0;
  NODE *np = start;
  while (np) { len++; np = np->next; }
  
  float a[len];
  for (i=0, np=start; i<len; i++, np=np->next) {
    a[i] = np->data.score;
  } 
  
  quick_sort(a, 0, len-1);
  
  return (len % 2 == 1)?  a[len/2] : (a[len/2-1] + a[len/2])/2 ; 
 } 
