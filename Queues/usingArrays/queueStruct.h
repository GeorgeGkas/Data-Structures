#ifndef _usingArrays_queueStruct_H
#define _usingArrays_queueStruct_H

#include <stdio.h>

typedef struct {
	int *front; /* Pointer to the front (head) of the queue. */
	int *rear; /* Pointer to the rear (tail) of the queue. */
	int *elems; /* Store our stack elements using dynamic array. */
	size_t lastElemPos; /* The index of the last element in queue. */
	size_t firstElemPos; /* The index of the first element int queue. */
	size_t currAllocatedSize; /* The number of elements that can be insert/remove before the next realloc(). */
} Queue;

#endif