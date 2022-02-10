
#include <stdio.h>
#include <stdlib.h>

typedef struct pq{
	unsigned int size;
	int q[100],
	n;
	
}pq;

int pq_parent(int n) {
	if (n==1)
		return -1;
	else
		return ((int) n/2);
}

int pq_yChild(int n) {
	return 2*n;
}

int pq_oChild(int n) {
	return 2*n+1;
}

void pq_swap(pq *p, int i, int parent) {
	int temp =  p->q[parent];
	p->q[parent] = p->q[i];
	p->q[i] = temp;
} 

void bubbleUp(pq *p, int index) {
	if (pq_parent(index) == -1)
		return;
	if (p->q[pq_parent(index)] > p->q[index]){
		pq_swap(p, index, pq_parent(index));
		bubbleUp(p, pq_parent(index));
	}

}


void pq_insert(pq *p, int x) {

	if (p->n > p->size)
		 printf("Warning: priority queue overflow insert x=%d\n",x);

	else {
		p->n = p->n + 1;
		p->q[p->n-1] = x;
		bubbleUp(p, p->n-1);
	}

}

pq *makeHeap(int array[], int n){
	int i;
	pq *p = (pq*) malloc(sizeof(pq));
	p->n = 0;
	p->size = 100;
	for (i=0; i<n; i++){
		pq_insert(p, array[i]);
	}
//	for (i=p->n; i>=1; i--)
//		bubble_down(p,i);

	return p;
}


void bubble_down(pq *p, int n) {
	int child = pq_yChild(n);
	int count;
	int min_index = n;

	for (count=0; count<=1; count++)
                 if ((child+count) <= p->n-1) {
			if (p->q[min_index] > p->q[child+count]) 
			min_index = child+count;
                 }

         if (min_index != n) {
                 pq_swap(p,n,min_index);
                 bubble_down(p, min_index);
	} 


}

int extractMin(pq *p){
	int min = -1;
	
	if (p->n <= 0)
		printf("Warning: empty priority queue.\n");
	else {
		min = p->q[0];
        	p->q[0] = p->q[ p->n-1 ];
        	p->n = p->n - 1;
        	bubble_down(p,0);

	}
	return min;

}

void heapSort(int s[], int n){
	int i;
	pq *p;

	p = makeHeap(s,n);

	for (i=0; i<n; i++)
        	s[i] = extractMin(p);
}

int main() {
	int data[11] = {1492, 1783, 2042, 2049, 1835, 1945, 1963, 1918, 2001, 2020};
//	pq *min = makeHeap(data, 10);

	heapSort(data, 10);

//	int c = extractMin(min);

	for (int i = 0; i<10; i++) {
	printf("%d\n", data[i]);
	}
}


