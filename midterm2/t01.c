/*1 - LINKED LIST PROPERTIES*/
/* ALL IN https://bohr.wlu.ca/hfan/cp264/examples/simple_linked_list.c */   

/*2 ALSO IN https://bohr.wlu.ca/hfan/cp264/examples/simple_linked_list.c*/
NODE insert_beg(struct node **startp, int num) {
  struct node* np = (struct node *)malloc(sizeof(struct node));
  if (np == NULL) {printf("malloc fails"); return;}
  np->data = num;
  np->next = NULL; 
  
  np->next = *startp;
  *startp = np;
  return *startp;
}

void display_backward_iterative(struct node *start) {
  if (start == NULL) return;
  struct node *stk = NULL, *ptr;
  
  while(start != NULL) {
    stk = insert_beg(&stk, start->data);
    start = start->next;
  }
  
  while(stk != NULL) {
    printf("%5d %d\n", stk->data, stk);
    ptr = stk;
    stk = stk->next;
    free(ptr);
  }
}

/*3 FROM A07*/
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

int get_count(TNODE *root) {
	if(root == NULL) return 0; // if(!(root))
	return 1 + get_count(root->left) + get_count(root->right);
} 

/*4 BST FROM A07*/
TNODE* search(TNODE *root, char *name) {
// your implementation
// Iterative bst search. T(n)=O(h), S(n)=O(1)
	while(root) {
		if(strcmp(name, root->data.name) == 0) return root;
		if(strcmp(name, root->data.name) < 0) root = root->left;
		else root = root->right;
	}
	return NULL;
}

/* 
TNODE *search(TNODE *root) {
// Recursive bst search. T(n)=S(n)=O(h)
	if(!(root)) return NULL;
	if(strcmp(name, root->data.name) == 0) return root;
	if(strcmp(name, root->data.name) < 0) return search(root->left);
	else return search(root->right);
}*/


void insert(TNODE **rootp, char *name, float score) {
// your implementation 
	TNODE *new = malloc (sizeof(TNODE));
	new->left = NULL;
	new->right = NULL;
	strcpy(new->data.name, name);
	new->data.score = score;
	if(!(*rootp)) {*rootp = new; return;}
	else {
		TNODE *p = *rootp;
		while(1) {
			if(strcmp(name, p->data.name) == 0) {
				printf("Name already found.\n"); return;
			}
			if(strcmp(name, p->data.name) < 0) {
				if(!(p->left)) {p->left = new; break;}
				else p = p->left;
			}
			else {
				if(!(p->right)) {p->right = new; break;}
				else p = p->right;
			}
		}
	}
}
/*
void insert(TNODE **rootp, char *name, float score) {
// Recursive bst insert. T(n)=S(n)=O(h)
	TNODE *new;
	strcpy(new->data.name, name);
	new->data.score = score;
	if(!(*rootp)) *rootp = new;
	else {
		if(strcmp(name, (*rootp)->data.name) == 0) {
				printf("Name already found.\n"); return;
		}
	 	if(strcmp(name, (*rootp)->data.name) < 0) {
				if(!((*rootp)->left)) (*rootp)->left = new;
				else insert(&(*rootp)->left, name, score);
		}
		else {
			if(!((*rootp)->right)) (*rootp)->right = new;
			else insert(&(*rootp)->left, name, score);
		}
	}
}
*/

void delete(TNODE **rootp, char *name) {
// your implementation
//Iterative delete. T(n)=O(h), S(n)=O(1)
	TNODE *tnp, *parentp, *minrn;
	if(!(*rootp)) {
		printf("\nBST is empty"); return;
	} 
	else {
		parentp = NULL;
		tnp = *rootp;
		while(tnp && name != tnp->data.name) { 
			parentp = tnp;
			tnp = (strcmp(name, tnp->data.name) < 0) ? tnp->left : tnp->right;
		}
		if(!(tnp)) { // if name has not been found
			printf("\nName not found."); return;
		}
		else{ // name was found
			if(!(tnp->right)) { // If tnp->right == NULL, make parent point to tnp->left
				(!(parentp)) ? (*rootp = tnp->left) :
				((parentp->left == tnp) ? (parentp->left = tnp->left) : (parentp->right = tnp->left));;
			}
			else if(!(tnp->left)) { // If tnp->left == NULL, make parent point to tnp->right//
				(!(parentp)) ? (*rootp = tnp->right) :
				((parentp->left == tnp) ? (parentp->left = tnp->right) : (parentp->right = tnp->right));;
			}
			else { // If tnp has two children
				minrn = extract_smallest_node(&(tnp->right)); // get smallest node from right subtree of trn
				minrn->left = tnp->left; 
				minrn->right = tnp->right;// make smallest node from right subtree of trn point to the same nodes that trn points to
				(!(parentp)) ? (*rootp = minrn) :
				((parentp->left == tnp) ? (parentp->left = minrn) : (parentp->right = minrn));; // attach smallest node from right subtree of trn to parent of trn
			}
		}
		free(tnp);
	}
}

/*
void delete(TNODE **rootp, char *name) {
// Recursive delete. T(n)=S(n)=O(h)
	if(!(*root)) return;
	TNODE *root = *rootp;
	else if(strcmp(name, root->data.name) == 0) {
		if(!(root->left) && !(root->right)) {
			*root = NULL; free(root);
		}
		else if((root->left) && !(root->right)) {
			*rootp = root->left; free(root);
		}
		else if(!(root->left) && (root->right)) {
			*rootp = root->right; free(root);
		}
		else {
			TNODE *tnp = *extract_smallest_node(&root->right);
			tnp->left = root->left;
			tnp->right = root->right;
			*root = tnp; free(root);
		}
	}
	else {
		(strcmp(name, root->data.name) < 0) ?
		delete(&root->left, name) : delete(&root->right, name);
	}
}
*/

/*5 FROM A08 */

TNODE *rotate_right(TNODE *y)  {
    // y represents the crit node
    TNODE *x = y->left;
    TNODE *T2 = x->right;
    // perform rotation
    x->right = y;// looking at case 1's graph,  T2 bcomes "x"
    y->left = T2;// left of new position of "x" becomes T2
    // update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;                                   
}
TNODE *rotate_left(TNODE *x) {
    TNODE *y = x->right;
    TNODE *T2 = y->left;
    //  perform rotation
    y->left = x; //T2 becomes "x" (looking at case 3's graph)
    x->right = T2; //right of new x position is T2
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}


void insert(TNODE **rootp, char *name, float score)
{
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np == NULL) return;
  strcpy(np->data.name, name);
  np->data.score = score;
  np->height = 1;
  np->left = NULL;
  np->right = NULL;
  
  // 1. Perform the normal BST insertion
  if (*rootp == NULL) {
    *rootp = np;
    return;
  }
  
  TNODE *root = *rootp;
  if (strcmp(name, root->data.name) < 0 )
    insert(&root->left, name, score);
  else if (strcmp(name, root->data.name) > 0 )
    insert(&root->right, name, score);
  else return ;

  // 2. update height of this root node

    root->height = max(height(root->left), height(root->right)) + 1;
  // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced

    int bf = balance_factor(root);  
  // 4. re-balance if not balanced
    // If this node becomes unbalanced, then  
    // there are 4 cases  

        if(bf>1){
                if(balance_factor(root->left) >= 0)
                    *rootp = rotate_right(root);
                else {
                   root->left= rotate_left(root->left);
                   *rootp =rotate_right(root);
                }
		}
            else if(bf<-1){
                if(balance_factor(root->right) <= 0)
                   *rootp = rotate_left(root);
                else {
                    root->right = rotate_right(root->right);
                    *rootp = rotate_left(root);
                }
			}
	}

