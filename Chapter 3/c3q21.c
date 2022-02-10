
#include <stdio.h>
#include <stdlib.h>


typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
	

} tree;

tree *createNode(int val) {
	tree *node = malloc(sizeof(tree));
	node->left = NULL;
	node->right = NULL;
	node->data = val;
	return node;
}

tree *searchTree(tree *root, int x) {
	if (root == NULL) return NULL;

	else if (root->data == x)
		return root;

	if (x > root->data) {
		return(searchTree(root->right, x));
	}
	else {
		return(searchTree(root->left, x));
	}
}

tree *findMin(tree *root) {
	if (root == NULL) return NULL;
	
	tree *min = root;
	while(min->left != NULL)
		min = min -> left;

	return min;

}


int cmpTrees(tree *root1, tree *root2) {

	if (root1 == NULL &&  root2 == NULL )
		return 1;

	if ((root1->data != root2->data)){
		return 0;
	}

	else {
		return(cmpTrees(root1->left, root2->left) && cmpTrees(root1->right, root2->right));
	}
	
}


int main() {
	tree *root = createNode(10), 
	*a = createNode(50), 
	*b = createNode(5), 
	*c = createNode(9), 
	*d = createNode(4), 
	*e = createNode(25), 
	*f = createNode(60);

	tree *j = createNode(8);
	j->left = d; 
	j->right = f; 

	tree * root2 = createNode(10);
		root2->right = a;
		root2->left = b;

	root->right = a;
	root->left = b;

	a->left = e;
	a->right = f;
	
	b->left = d;
	b->right = f;

//	tree *temp = searchTree(root, 60);
//	temp->data = 4;

	printf("%d\n", cmpTrees(root, root2));

return 0;
}


