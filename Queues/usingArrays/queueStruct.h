#ifndef _usingArrays_queueStruct_H
#define _usingArrays_queueStruct_H

#include <stdio.h>

typedef struct {
	int *front; /* Pointer to the front (head) of the queue. */
	int *rear; /* Pointer to the rear (tail) of the queue. */
	int *elems; /* Store our stack elements using dynamic array. */
	size_t size; /* The number of elements exist on our queue. */
	size_t currAllocatedSize; /* The number of elements that can be insert/remove before the next realloc(). */
} Queue;

#endif