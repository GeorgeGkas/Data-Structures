#ifndef _usingArrays_stackUsingArrays_H
#define _usingArrays_stackUsingArrays_H

#include <stdarg.h>

#ifndef _usingArrays_stackStruct_H
#include "stackStruct.h"
#endif

#ifndef _usingArrays_stack_exalloc_H
#include "stack_exalloc/stack_exalloc.h"
#endif

#define STACK_IS_FULL -2
#define MAX_CAPACITY_NOT_SET -3


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

#endif