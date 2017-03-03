#ifndef _usingArrays_stackStruct_H
#define _usingArrays_stackStruct_H

#include <stdio.h>

typedef struct {
    int *elems; /* Store our stack elements using dynamic array. */
    int *top; /* The top element of our stack. */
    size_t size; /* The number of elements exist on our stack. */
    size_t currAllocatedSize; /* The number of elements that can be insert/remove before the next realloc(). */
    long maxCapacity; /* The max capacity of our stack. (-1) If we don't set it. */
} Stack;

#endif