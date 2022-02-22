#include "quicksort.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;

}

int partition(int array[], int l, int h) {
	int i, p, firsthigh;

	p = h;
	firsthigh = l;
	for(i=l; i<h; i++){
		if(array[i] < array[p]){
			swap(&array[i], &array[firsthigh]);
			firsthigh++;
		}
	}
	swap(&array[p],&array[firsthigh]);
return(firsthigh);
}

void quicksort(int array[], int l, int h) {
	int p;

	if ((h-l) >0){
		p = partition(array, l, h);
		quicksort(array, l, p-1);
		quicksort(array, p+1, h);
	}
}

