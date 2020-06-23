#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    // your implementation
	if(!(sp->top)) {
        sp->top = np; 
        return;
    }//if top is NUll
	np->next = sp->top; //new node-> next is stack's top
    sp->top = np;  //top is new node
}
NODE *pop(STACK *sp) {
    // your implementation
	if(!(sp->top)) {printf("Underflow\n"); return NULL;}
	NODE *ptr = sp->top;
    sp->top = sp->top->next;
     //free(ptr); // do not free ptr in dequeue or stack;free'd in other function
	return ptr;
}

void clean_stack(STACK *sp) {
    // your implementation
	if(!(sp->top)) {printf("Already Clean\n"); return;}
	NODE *ptr = sp->top;
	/*while(sp->top) {ptr = sp->top; sp->top = sp->top->next; free(ptr);}
	free(ptr);*/ 
	clean(&ptr); // use common clean function
	return;
}

