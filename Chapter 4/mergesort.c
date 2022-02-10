
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
        int front, rear, size;
        unsigned capacity;

        int *array;

} queue;

queue * createQueue(unsigned capacity);
int isFull(queue* q);
int isEmpty(queue * q);
void enqueue(int data, queue *q);
int dequeue(queue *q);
int front(queue *q);
int rear(queue *q);
void mergeSort(int array[], int low, int middle);
void merge(int array[], int low, int middle, int high);

//int main()
//{
//   queue* q = createQueue(1000);
//
//   enqueue(10, q);
//  enqueue(20, q);
// enqueue(30, q);
//enqueue(40, q);
//
//   printf("%d dequeued from queue\n\n",
//         dequeue(q));
//
//   printf("Front item is %d\n", front(q));
//  printf("Rear item is %d\n", rear(q));
//
//    return 0;
//}


queue * createQueue(unsigned capacity) {

        queue *q = (queue*) malloc(sizeof(queue));
        q ->capacity = capacity;
        q -> front = q -> size = 0;

        q -> rear = q ->capacity - 1;
        q -> array = (int*) malloc(q->capacity * sizeof(int));

        return q;
}

int isFull(queue* q)
{
    return (q->size == q->capacity);
}

int isEmpty(queue * q) {
        return (q->size == 0);
}

void enqueue(int data, queue *q) {
        if (isFull(q))
                return;
        else {
                q -> rear = (q -> rear + 1) % q->capacity;
                q -> array[q -> rear] = data;
                q -> size = q -> size + 1;
//                printf("%d enqueued to queue\n", data);
        }
}

int dequeue(queue *q) {
        if (isEmpty(q))
                return INT_MIN;

        int data = q->array[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size = q->size - 1;

        return data;
}

int front(queue *q) {
        if (isEmpty(q))
                return INT_MIN;
        return q->array[q->front];
}

int rear(queue *q) {
        if (isEmpty(q))
                return INT_MIN;
        return q->array[q->rear];
}

//Merge Sort Implementation
//---------------------------------------------------------------------
//---------------------------------------------------------------------

void mergeSort(int array[], int low, int high) {
	int i, middle;
		
	if (low < high) {
		middle = (low + high)/2;
		mergeSort(array, low, middle);
		mergeSort(array, middle+1, high);
		merge(array, low, middle, high);
	}

}

void merge(int array[], int low, int middle, int high) {
	
	int i;

	queue *buffer1 = createQueue(100),
	*buffer2 = createQueue(100);
	
	for (i=low; i<=middle; i++) enqueue(array[i], buffer1);
	for (i=middle+1; i<=high; i++) enqueue(array[i], buffer2);

	i = low;
	while(!(isEmpty(buffer1)) || !(isEmpty(buffer2))) {

		if (front(buffer1) <= front(buffer2))
			array[i++] = dequeue(buffer1);
		else
			array[i++] = dequeue(buffer2);

		while(!isEmpty(buffer1)) array[i++] = dequeue(buffer1);
		while (!isEmpty(buffer2)) array[i++] = dequeue(buffer2);
	}



}

int main () {
	int list[] = {1, 4, 5, 6, 7, 1, 5, 7, 9, 8};


	for (int i=0; i<10; i++)
		printf("%d, ",list[i]);
	printf("\n\n");

	mergeSort(list, 0, 9);
	for (int i=0; i<10; i++)
		printf("%d, ",list[i]);
	printf("\n");

return 0;
}
