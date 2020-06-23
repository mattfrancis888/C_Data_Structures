
int balance_factor(TNODE* np) {
// your implementation
    return (np) ? height(np->left) - height(np->right) : 0;
}

int is_avl(TNODE *root) {
// your implementation
//if not balanced it is an AVL tree
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
  
    /* If tree is empty then return true */
    if (root == NULL) 
        return 1; 
  
    /* Get the height of left and right sub trees */
    lh = height(root->left); 
    rh = height(root->right); 
  
    if (abs(lh - rh) <= 1 && is_avl(root->left) && is_avl(root->right)) 
        return 1; 
  
    /* If we reach here then  
    tree is not height-balanced */
    return 0; 

}

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

