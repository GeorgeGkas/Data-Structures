#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

#define OPERATION_SUCCESS 0
#define COULD_NOT_ALLOCATE -1
#define STACK_IS_FULL -2
#define MAX_CAPACITY_NOT_SET -3

typedef struct {
	int *elems; /* Store our stack elements using dynamic array. */
	int *top; /* The top element of our stack. */
	size_t size; /* The number of elements exist on our stack. */
	long maxCapacity; /* The max capacity of our stack. (-1) If we don't set it. */
} Stack;

/**
 * Create an empty stack S with max capacity n.
 */
int createStack(Stack *S, size_t n);

/**
 * Creates a stack S with n elements x1,x2, x3,….
 */
int buildStack(Stack *S, size_t n, ...);

/**
 * Adds the element x to stack S.
 */
int pushStack(Stack *S, int x);

/**
 * Removes the element x from stack S and return it.
 */
int popStack(Stack *S);

 /**
  * Checks whether the stack S contains no elements.
  * Returns either 0 (not empty) or 1 (empty).
  */
int isEmptyStack(Stack *S);

/**
 * Returns the last inserted element to stack S 
 * without removing it.
 */
int peekStack(Stack *S);

/**
 * Returns the number of elements in stack S.
 */
size_t sizeOfStack(Stack *S);
