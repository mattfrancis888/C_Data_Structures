#include "bigint_dllist.h"

NODE *new_node(char data) {
// your implementation
	NODE *np =(NODE *) malloc(sizeof(NODE));
	np->data = data;
	np->next = NULL;
	np->prev = NULL;
	return np;
}

void display_forward(NODE *np) {
// your implementation
	// if(np == NULL) {
    //     printf("Empty"); 
    //     return;
    // }
	NODE *ptr = np;
	while(ptr != NULL) {
        printf("%c ", ptr->data); 
        ptr = ptr->next;
    }	
    //print nexts
}

void display_backward(NODE *end) {
// your implementation
	// if(end == NULL) {
    //     printf("Empty");
    //     return;
    // } 
	NODE *ptr = end;
	while(ptr != NULL) {
        printf("%c ", ptr->data); 
        ptr = ptr->prev;
    }
    //print prevs
}

void insert_start(NODE **startp, NODE **endp, NODE *new_np) {
// your implementation
	if(*startp == NULL) {
        *startp = new_np;
        *endp = new_np;
        //next and prev are still null
        return;
    }
	new_np->next = *startp;
    //new_np prev is null
    //move pervious start node over
	NODE *ptr = *startp;
	ptr->prev = new_np;

	*startp = new_np;
}

void insert_end(NODE **startp, NODE **endp, NODE *new_np) {
// your implementation
	if(*startp == NULL) {
        *startp = new_np; 
        *endp = new_np; 
        return;
    } 
	new_np->prev = *endp;

	NODE *ptr = *endp;
	ptr->next = new_np;

	*endp = new_np;
}

void delete_start(NODE **startp, NODE **endp) {
// your implementation
	if(*startp == NULL) return; // robustness
	NODE *ptr = *startp;
	if(ptr->next == NULL) {
        *startp = NULL; 
        *endp = NULL; 
        free(ptr);
        return;
    } // if only one node is in list
	NODE *prev_ptr = ptr;

    //ptr of 2nd node
	ptr = ptr->next;
	ptr->prev = NULL;

	free(prev_ptr);
	*startp = ptr;	
}

void delete_end(NODE **startp, NODE **endp) {
// your implementation
	if(*startp == NULL) return;
	NODE *ptr = *endp;
	if(ptr->prev == NULL) {
        *startp = NULL; 
        *endp = NULL; 
        free(ptr); 
        return;
    } // if one node is in list
	NODE *post_ptr = ptr;
	ptr = ptr->prev;
	ptr->next = NULL;
	free(post_ptr);
	*endp = ptr;
}

void clean(NODE **startp, NODE **endp) {
//your implementation
	if(*startp== NULL) {
        printf("Already empty"); 
        return;
    }
	NODE *ptr = *startp;
	if(ptr->next == NULL) {
        *startp = NULL;
        *endp = NULL;
        free(ptr);
        return;
     } // if one node in list
	NODE *prev_ptr = NULL;
	while(ptr != NULL) {
		prev_ptr = ptr;
		ptr = ptr->next;
		free(prev_ptr); 
	}
	free(ptr);
	*startp = NULL;
	*endp = NULL;
}