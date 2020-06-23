BINARY TREE
void display_preorder(TNODE *root){
if (root) {
	printf("%c", root -> data);
	display_preorder(root -> left);
	display_preorder(root -> right);
	}
}
void display_inorder(TNODE *root){
if (root){
	display_inorder(root -> left);
	printf("%c", root -> data);
	display_inorder(root -> right);
	}
}
void display_postorder(TNODE *root){
if (root){
	display_postorder(root -> left);
	display_postorder(root -> right);
	printf("%c", root -> data);
	}
}

TNODE *iterative_bf_search(TNODE *root, int val) { //breath first search uses queue
    //bf visit neightbor nodes before moving to the next level of node
    if (root==NULL)return NULL;
    QUEUE a={0};
    TNODE *np;
    enqueue(&a,root);
    while(a->front){
        np=dequeue(&a)
        if(np->value==val)
            return np;
        if(np->left)enqueue(&a,&np->left);
        if(np->right)enqueue(&a,&np->right)
    }
}


TNODE *iterative_df_search(TNODE *root, int val) {// using pre-order traversal
// your implementation
//https://www.youtube.com/watch?v=elQcrJrfObg
//pop child; visit right and left by adding to sttack
	if(!(root)) return NULL;
	STACK stack = {0};
	TNODE *tn;
	push(&stack, root);
	while(stack.top) {
		tn = pop(&stack);
		if(tn->data == val) return tn;
        if(tn->right) //right first!
                push(&stack, tn->right);
        if(tn->left)
                push(&stack, tn->left);
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

static int bst_leaf_count_aux(const bst_node *node) {
	int count = 0;

	if (node == NULL) {
		// Base case: no node.
		count = 0;
	} else if (node->left == NULL && node->right == NULL) {
		// Base case: node has no children.
		count = 1;
	} else {
		count = bst_leaf_count_aux(node->left)
				+ bst_leaf_count_aux(node->right);
	}
	return count;
}