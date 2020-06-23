https://bohr.wlu.ca/hfan/cp264/examples/simple_linked_list.c
NODE insert_beg(struct node **startp, int num) {
  struct node* np = (struct node *)malloc(sizeof(struct node));
  if (np == NULL) {printf("malloc fails"); return;}
  np->data = num;
  np->next = NULL; 
  
  np->next = *startp;
  *startp = np;
  return *startp;
}

void insert_end(struct node **startp, int num) {
  struct node *np = (struct node *) malloc(sizeof(struct node));
  if (np == NULL) {printf("malloc fails"); return;} //malloc failed 
  np->data = num;
  np->next = NULL;  
  
  if (*startp == NULL) {
	*startp = np;
  } else {
	 struct node *p = *startp;
	 while ( p->next != NULL) {
		p = p->next;
	 }
	 p->next  = np;
  }	
}

/*
* insert after a node given value if found, otherwise insert at end
* time: O(n), space: O(1)
*/
void insert_after(struct node **startp, struct node* new_np, int num) {
  if (*startp == NULL) {
	*startp = new_np;
  }
  
  struct node *np = *startp, *prev = NULL;
  while ( (np != NULL) && (np->data != num )) {
    prev = np;
    np = np->next;
  } 
  
  if (np == NULL) {  // not found 
	 prev->next = new_np;
     new_np->next = NULL;	 
  }
  else { // found at np
     new_np->next = np->next;
	 np->next = new_np; 
  }
}

/*
* time: O(1), space: O(1)

/*
* iterative alg, time: O(n), space: O(1)
*/
int delete_end(struct node **startp) {
  if (startp == NULL || *startp == NULL) return 0; 
  struct node *np = *startp;
  struct node *prev = NULL;
 
  while (np->next != NULL) {
    prev = np;
    np = np->next;
  } 
   
  if (prev == NULL)
    *startp = NULL;
  else
    prev->next = np->next;
  
   free(np); 
   return 1;

}

/*
* iterative alg, time: O(n), space: O(1)
*/
int delete(struct node **startp, int num) {
	NODE *ptr = *startp;
	NODE *prev = NULL;
	
	if(*startp == NULL){
		return 0;
	}
	
	while(ptr != NULL && strcmp(ptr->data.name,name) != 0){
		prev = ptr;
		ptr = ptr->next;
	}
	if(prev == NULL){
		ptr = ptr->next;
		free(ptr);
	}else{
		prev->next = ptr->next;
		free(ptr);
	}
	return 1;
}

/*
* iterative alg, time: O(n), space: O(1)
*/     
struct node* search(struct node *start, int num) {
  while((start != NULL) && (start->data != num)) {
    start = start->next;
  }
  return start;
}

/*/*
* iterative alg, time: O(n), space: O(1)
*/