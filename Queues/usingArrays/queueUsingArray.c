#include "queueUsingArray.h"

void createQueue(Queue *Q) {
	Q->elems = malloc(0);
	Q->front = Q->rear = NULL;
	Q->size = 0;
}