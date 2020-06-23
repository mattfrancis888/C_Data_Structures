#include <stdio.h>
#include <malloc.h>
#include "tree.h"

TNODE *new_node(int value) {
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np == NULL) return NULL;
  np->data = value;
  np->left = NULL;
  np->right = NULL;
  return np;
}

int get_count(TNODE *root) {
	if(root == NULL) return 0; // if(!(root))
	return 1 + get_count(root->left) + get_count(root->right);
}

int get_height(TNODE *root) { //longest # of nodes (NOT edges like in SO; hb wants ndoes) from root to leaf
// your implementation
	if(root == NULL) return 0;
	int lh = get_height(root->left);
	int rh = get_height(root->right);	
    if(lh > rh){ //exist to only increment the highest side (left or right), check the tree ex 2 below; it will explain why doing
    //this without if blocks will not work! you can't just do lh + 1 or rh + 1!
        return lh + 1; //add 1 height each time you traverse to left leave; 
    }
    else{//exist to only increment the highest side, check the tree ex 2 below.
        return rh + 1; //will always be executed first when reached at the end of a leaf because lh = 0 and rh = 0 
    } 
    //compare LH and RH

    //Pretend a tree of 
    //lh=1->2    A    rh = 2 -> then rh = 3 after the first call gets invoked
      //lh=0  B   C  rh = 1
        //         D return 0  

     //Pretend a tree of 
    //lh=2->3    A    rh = 1->2
//lh=1,rh= 1  B    C  lh = 0, rh = 0 
    //lh=0   D  E     
}

void clean_tree(TNODE **rootp) {
	TNODE *ptr = *rootp;
        if(ptr) {
        clean_tree(&(ptr->left));
        clean_tree(&(ptr->right));
        free(ptr);
	}
}

void display_preorder(TNODE *root) {
// your implementation
    if(root == NULL) return; // base case
    printf("%c", root->data);
    display_preorder(root->left);
    display_preorder(root->right);
}

void display_inorder(TNODE *root) {
// your implementation
    if(root == NULL) return; // base case
	display_inorder(root->left);
	printf("%c",root->data);
	display_inorder(root->right);
}

void display_postorder(TNODE *root) {
// your implementation
    if(root == NULL) return; // base case
    display_preorder(root->left);
    display_preorder(root->right);
    printf("%c", root->data);
}

void display_tree(TNODE *root, int prelen) {
  if (root) {
    int i;
    for (i = 0; i < prelen; i++)
      printf("%c", ' ');
    printf("%s", "|___");
    printf("%c\n", root->data);
    display_tree(root->right, prelen + 4);
    display_tree(root->left, prelen + 4);
  }
}

/* use auxiliary queue data structure for the algorithm */
void iterative_bf_display(TNODE *root) { //based on levels
// your implementation
	if(!(root)) return;
	QUEUE qp = {0};
	TNODE *tn;
	enqueue(&qp, root);
	while(qp.front) {// while qp.front != NULL
			tn = dequeue(&qp);
			printf("%c", tn->data);
			if(tn->left)
				enqueue(&qp, tn->left);
			if(tn->right)
				enqueue(&qp, tn->right);
		}
}	
/* use auxiliary queue data structure for the algorithm */
TNODE *iterative_bf_search(TNODE *root, int val) {
// your implementation
	if(!(root)) return NULL;
	QUEUE qp = {0};
	TNODE *tn;
	enqueue(&qp, root);
	while(qp.front) {
			tn = dequeue(&qp);
			if(tn->data == val) return tn;
			if(tn->left)
				enqueue(&qp, tn->left);
			if(tn->right)
				enqueue(&qp, tn->right);
		}
	
}

/* use auxiliary stack data structure for the algorithm */
TNODE *iterative_df_search(TNODE *root, int val) {// using pre-order traversal
// your implementation
//https://www.youtube.com/watch?v=elQcrJrfObg
//pop child; visit right and left by adding to sttack
	if(!(root)) return NULL;
	STACK stack = {0};
	TNODE *tn;
	push(&stack, root);
	while(stack.top) {
		tn = peek(&stack);
		pop(&stack);
		if(tn->data == val) return tn;
    if(tn->right) //right first!
			push(&stack, tn->right);
  	if(tn->left)
			push(&stack, tn->left);
	}
}


// queue functions adapted and modified from a6
void enqueue(QUEUE *qp, void *data) {
   QNODE *p = (QNODE*) malloc(sizeof(QNODE));
   if (p == NULL) return; 
   else { 
     p->data = data;
     p->next = NULL;
     
     if (qp->front == NULL) {
      qp->front = p;
      qp->rear = p;
     } else {
      (qp->rear)->next = p;
      qp->rear = p; 
    }
  }
}
void *dequeue(QUEUE *qp) {
  void *temp = NULL;
  if (qp->front) {
    QNODE *p = qp->front;
    temp = p->data;
    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;
    } else {
      qp->front = p->next;
    }
    free(p);
    return temp;
  }
  return NULL;
}
void clean_queue(QUEUE *qp) {
  QNODE *temp, *p = qp->front; 
  while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp);
  }
}

// stack functions adapted and modified from a6
void push(STACK *sp, void *data) {
  SNODE *p = (SNODE*) malloc(sizeof(SNODE));
  p->data = data;
  p->next = NULL;
  if (sp->top == NULL) {
    sp->top = p;
  } else {
    p->next = sp->top;
    sp->top = p  ;
  }
}
void pop(STACK *sp) {
  if (sp->top != NULL) {
    SNODE *p = sp->top;
    sp->top = p->next;
    free(p);
  }
}
void *peek(STACK *sp) {
  if (sp->top != NULL) {
     return sp->top->data;
  }
  return NULL;
}
void clean_stack(STACK *sp) {
  SNODE *temp, *p = sp->top;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  sp->top = NULL;
}