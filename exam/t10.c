
TNODE* search(TNODE *root, char *name) {
    // your implementation
	while(root) {
		if(strcmp(name, root->data.name) == 0) return root;
		if(strcmp(name, root->data.name) < 0) root = root->left;
		else root = root->right;
	}
	return NULL;
}

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
int iterative_delete(tnode **rootp, int val) {
  tnode *tnp, *parentp, *suc, *psuc, *ptr;
  if (*rootp == NULL) {
    printf("\nThe tree is empty ");
    return 0;
  }
  else 
  {
    //find the node of the given value
    parentp = NULL;
    tnp = *rootp;
    while (tnp != NULL && val != tnp->data) {
      parentp = tnp;
      tnp = (val < tnp->data) ? tnp->left : tnp->right;
    }
    
    // value node not found
    if (tnp == NULL) {
      printf("\nThe value to be deleted is not present in the tree");
      return 0;
    }
    //should have if (tnp -> left == null && tnp -> right == null)
    //tnp->data == val, node tnp will be deleted,    
    if (tnp->left == NULL) //has one child
      ptr = tnp->right;
    else if (tnp->right == NULL)
      ptr = tnp->left;
    else { // has 2 child
      // find the smallest on right subtree
      psuc = tnp;
      suc = tnp->right;
      while (suc->left != NULL) {
        psuc = suc;
        suc = suc->left;
      }

      if (tnp == psuc) {
        suc->left = tnp->left;
      } else {
        psuc->left = suc->right;
        suc->left = tnp->left;
        suc->right = tnp->right;
      }
      ptr = suc;
    }
    
  // Attach ptr to the parent node
    if (parentp == NULL) 
      *rootp = ptr;
    else if (parentp->left == tnp) 
      parentp->left = ptr;
    else 
      parentp->right = ptr;
    
    free(tnp);
  }
}
   
   
