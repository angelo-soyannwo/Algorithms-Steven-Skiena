

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


void reverse(node *l) {
	node *current = l,
		*temp = current,
		*prev = current;
	current = current->next;
	temp->next = NULL;
	temp = current;
	while(current->next != NULL){
		current = current->next;
		temp->next = prev;
		prev = temp;
		temp = current;
	}
	current->next = prev;
}


void reverse(node *l) {
 
}

int main() {
	node *root = createNode(4),
		*a = createNode(5),
		*b = createNode(6),
		*c = createNode(7),
		*d = createNode(8);

	root->next = a;
	a->next = b;
	b->next = c;
	c->next = d;

	reverse(root);
	traversePrint(d);
	return 0;
}
