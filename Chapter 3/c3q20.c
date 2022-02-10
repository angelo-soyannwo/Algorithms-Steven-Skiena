

#include <stdlib.h>
#include <stdio.h>
#include <math.h>



typedef struct node {
	struct node *next;
	int data;
} node;


node *createNode(int val){

	node * ptr = (node*) malloc(sizeof(node));
	ptr->data = val;
	ptr->next = NULL;

	return ptr;
}

node* findMid(node * root){
	node *current = root;
	int count = 1;
	while (current != NULL){
		current = current->next;
		count++;
	}
	for (int i=1; i<ceil(count/2); i++)
		root = root->next;
	return root;
}


int main() {
	node *root = createNode(10),
		*a = createNode(11),
		*b = createNode(12),
		*c = createNode(13);

	root->next = a;
	a->next = b;
	b->next = c;

	printf("%d\n", (findMid(root))->data);

return 0;
}
