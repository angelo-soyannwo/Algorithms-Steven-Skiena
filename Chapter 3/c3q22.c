
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int data;
	struct node *next;
} node;


node *createNode(int val) {
	node *ptr = (node*) malloc(sizeof(node));
	ptr->data = val;
	ptr->next = NULL;
	return ptr;
}

void traversePrint(node *l) {

	while(l->next != NULL){
		printf("%d\n", l->data);
		l = l->next;
	}
	printf("%d\n", l->data);
}

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
	

} tree;

tree *createTNode(int val) {
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

int hasChild(tree *ptr) {

	if (ptr->left !=NULL && ptr->right != NULL) {
		return 2;
	}
	else if ((ptr->left == NULL &&  ptr->right != NULL) || (ptr->left != NULL &&  ptr->right == NULL)) {
                return 1;
        }
	else 
		return 0;
}

tree * oneUp(tree * root, tree * ptr) {
	//returns the parent node of ptr in the tree from root
	tree * result = root;
	while (result->right != ptr && result->left != ptr) {
		if (result->data < ptr->data)
			result = result->right;
		else
			result = result-> left;
	}
	return result;
}


void deleteTNode(tree * root, tree * ptr) {

	int key = ptr->data;

	if (root == NULL || ptr == NULL)
		return;

	else if ((ptr->right == NULL) && (ptr->left == NULL)){
		free(ptr);
		return;
	}

	else if (key < root->data){
		deleteTNode(root->left, ptr);
	}
	else if (key > root->data){
		deleteTNode(root->right, ptr);
	}
	else {
		if (root->left == NULL && root->right != NULL) {
			tree * temp = root;
			root->data = (root->right)->data;
			free(temp);
			return;
		}
		else if (root->right == NULL && root->left != NULL) {
			tree * temp = root->left;
			root->data = (root->left)->data;
			free(temp);
			return;
		}
		tree * temp = findMin(root->right);
		root->data = temp->data;
		free(temp);
		return;
	}
}


node * bs2ll(tree * root) {
	tree *min = findMin(root);
	node *first = createNode(min->data),
	*current;
	tree * x = oneUp(root, min);
	x->left = NULL;
	min = NULL;
	current = first;
	while(root) {
		min = findMin(root);
		printf("min: %d", min->data); 
		x = oneUp(root, min);
		x->left = NULL;
		x = NULL;
		current->next = createNode(min->data);
		min = NULL;
		current = current->next;

	}
	return first;
}

int main() {
	tree *root = createTNode(10), 
	*a = createTNode(50), 
	*b = createTNode(5), 
	*c = createTNode(9), 
	*d = createTNode(4), 
	*e = createTNode(25), 
	*f = createTNode(60),
	*g = createTNode(55);

	root->right = a;
	root->left = b;

	a->left = e;
	a->right = f;
	
	b->left = d;
	b->right = c;
	
	f->left = g;


	node *first = bs2ll(root);

//	tree *temp = searchTree(root, 60);
//	printf("%d\n", (root->left)->data);
//	deleteTNode(root, b);		
//	printf("%d\n", (root->left)->data);

//	traversePrint(first);

return 0;
}


 
