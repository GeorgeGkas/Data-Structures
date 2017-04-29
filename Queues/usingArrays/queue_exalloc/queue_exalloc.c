#include "queue_exalloc.h"

int queue_ex_insert(Queue *Q, int x) {
	if (Q->currAllocatedSize == Q->lastElemPos + 1) {
		Q->currAllocatedSize *= 2;
		Q->elems = realloc(Q->elems, sizeof(int) * Q->currAllocatedSize);
		if (Q->elems == NULL) {
			return COULD_NOT_ALLOCATE;
		}

		Q->rear = Q->elems + Q->lastElemPos + 1;
	}

	*(Q->rear) = x;
	++(Q->rear);
	++(Q->lastElemPos);

	if (Q->lastElemPos - Q->firstElemPos == 1) {
		Q->front = Q->elems;
	}

	return OPERATION_SUCCESS;
}


int queue_ex_remove(Queue *Q, int *removed) {
	*removed = *(Q->front);
	++(Q->front);
	++(Q->firstElemPos);

	return OPERATION_SUCCESS;
}