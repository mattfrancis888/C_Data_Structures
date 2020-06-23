#include <stdio.h>
#include <malloc.h>
#include "common.h"

NODE *new_node(int data, int type) {
// your implementation
	NODE *np =(NODE *) malloc(sizeof(NODE));
	np->data = data;
	np->type = type;
	np->next = NULL;
	return np;
}

void display(NODE *start) {
	if(!(start)) {printf("stack/queue is empty\n"); return;}
  	while (start) {
    	if (start->type == 0) printf("%d ", start->data);
    	else printf("%c ", start->data);      
    	start = start->next;
  }
}

void clean(NODE **topp) {
// your implementation
	if(*topp == NULL) {printf("Underflow\n"); return;}
    //When a queue is empty, deletion can not be done, such a situation is called underflow
	NODE *curr, *ptr = *topp; // intitialize current node pointer used in loop.ptr points to topp(start)
	while(ptr != NULL) {
        curr = ptr; 
        ptr = ptr->next; 
        free(curr);
    }
	free(curr); 
    *topp = NULL;	
    //did not include rear= NULL because stacks dosent have rear, only queues do 
}