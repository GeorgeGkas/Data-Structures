#include "queueUsingArray.h"

void createQueue(Queue *Q) {
	Q->elems = malloc(0);
	Q->front = Q->rear = NULL;
	Q->size = 0;
}

int peekQueue(Queue *Q) {
	if (Q->front == NULL) {
		return 0;
	}

	return *(Q->front);
}