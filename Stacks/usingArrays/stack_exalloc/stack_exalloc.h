#ifndef _usingArrays_stack_exalloc_H
#define _usingArrays_stack_exalloc_H

#include <stdlib.h>

#ifndef _usingArrays_stackStruct_H
#include "../stackStruct.h"
#endif

#define OPERATION_SUCCESS 0
#define COULD_NOT_ALLOCATE -1

/**
 * Insert element x to stack S.
 * If succeed return 0 else -1.
 */
int stack_ex_insert(Stack *S, int x);

/**
 * Remove element x to stack S.
 * If succeed return 0 else -1.
 */
int stack_ex_remove(Stack *S);

#endif