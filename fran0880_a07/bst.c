#include "bst.h"

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

void delete(TNODE **rootp, char *name) {
// your implementation
	TNODE *tnp, *parentp, *minrn;
	if(!(*rootp)) {
		printf("\nBST is empty"); return;
	} 
	else {
		parentp = NULL;
		tnp = *rootp;
		while((tnp) && (strcmp(name, tnp->data.name) != 0)) { 
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

TNODE *extract_smallest_node(TNODE **rootp) {
// your implementation
//Iterative
	if(!(*rootp)) return NULL;
	TNODE *tnp = *rootp, *parentp = NULL;
	while(tnp->left) {
		parentp = tnp;
		tnp = tnp->left;
	}
	if(tnp == *rootp) {
		if(!(tnp->right))
			*rootp = NULL;
		else
			*rootp = tnp->right;
	}
	else{
		parentp->left = tnp->right;
	}
	return tnp;
}

void display_inorder(TNODE *root) {
    if (root) {
        if (root->left) display_inorder(root->left);
        printf("%-15s%3.1f\n", root->data.name, root->data.score);
        if (root->right) display_inorder(root->right);
    }
}

void clean_tree(TNODE **rootp) {
    TNODE *root = *rootp;
    if (root) {
        if (root->left)
            clean_tree(&root->left);
        if (root->right)
            clean_tree(&root->right);
        free(root);
    }
    *rootp = NULL;
}