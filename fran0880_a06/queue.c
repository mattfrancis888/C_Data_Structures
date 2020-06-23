#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
// your implementation
	if(!(qp->front)) { //can use qp, whcih is &q because it is a pointer, 
    // a pointer [like x = 14, *ptr = &x] holds the memory location of the x variable
    // its basically the same as *ptr = &x; and ptr = ptr (like in the prev assignment)
        qp->front = np; 
         qp->rear = np;
        return;
    } // if front of queue is NULL, set front and rear pointing to the new node
	qp->rear->next = np; 
    qp->rear = np;
}  

NODE *dequeue(QUEUE *qp) {
// your implementation
	if(!(qp->front)) {printf("Underflow\n"); return NULL;} // if front value is NULL, remove nothing; called "Underflow"
	NODE *ptr = qp->front;
	if(qp->front == qp->rear){// if only one element
        qp->front = NULL;
        qp->rear = NULL;
    }
	else qp->front = qp->front->next; 
	//free(ptr); // do not free ptr in dequeue or stack. Will be free'd in a6q1.c
	return ptr;
}

void clean_queue(QUEUE *qp) {
// your implementation
	if(!(qp->front)) {printf("Underflow\n"); return;}
	NODE *ptr = qp->front;
	clean(&ptr); //must make rear NULL
	qp->rear = NULL;
}
	
