#include "queueUsingArray.h"

static size_t QueueSize(Queue *Q) {
    return (Q->lastElemPos - Q->firstElemPos);
}

void createQueue(Queue *Q) {
	Q->elems = malloc(sizeof(int) * 4);
	Q->front = NULL;
	Q->rear = Q->elems;
	Q->firstElemPos = Q->lastElemPos = -1;
	Q->currAllocatedSize = 4;
}

int peekQueue(Queue *Q) {
	if (Q->front == NULL) {
		return 0;
	}

	return *(Q->front);
}

int isEmptyQueue(Queue *Q) {
	return (QueueSize(Q) ? 0 : 1);
}

size_t sizeOfQueue(Queue *Q) {
	return QueueSize(Q);
}

int enQueue(Queue *Q, int x) {
	if (queue_ex_insert(Q, x) == COULD_NOT_ALLOCATE) {
    	return COULD_NOT_ALLOCATE;
    }

    if (QueueSize(Q) == 1) {
        Q->firstElemPos = 0;
    }

    return OPERATION_SUCCESS;
}

int deQueue(Queue *Q) {
    if (QueueSize(Q) == 0) {
        return 0;
    }

    int removed;
    if (queue_ex_remove(Q, &removed) == COULD_NOT_ALLOCATE) {
        return COULD_NOT_ALLOCATE;
    }
    
    return removed;
}