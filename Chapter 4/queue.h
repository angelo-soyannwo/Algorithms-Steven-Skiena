#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int front, rear, size;
	unsigned capacity;

	int *array;

} queue;

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
		printf("%d enqueued to queue\n", data);
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

//int main()
//{
//    queue* q = createQueue(1000);
// 
//    enqueue(10, q);
//    enqueue(20, q);
//    enqueue(30, q);
//    enqueue(40, q);
// 
//    printf("%d dequeued from queue\n\n",
//           dequeue(q));
// 
//    printf("Front item is %d\n", front(q));
//    printf("Rear item is %d\n", rear(q));
// 
//    return 0;
//}

