#ifndef _usingArrays_queue_exalloc_H
#define _usingArrays_queue_exalloc_H

#include <stdlib.h>

#ifndef _usingArrays_queueStruct_H
#include "../queueStruct.h"
#endif

#define OPERATION_SUCCESS 0
#define COULD_NOT_ALLOCATE -1

/**
 * Insert element x to queue Q.
 * If succeed return 0 else -1.
 */
int queue_ex_insert(Queue *Q, int x);

/**
 * Remove element x to queue Q.
 * If succeed return 0 else -1.
 */
int queue_ex_remove(Queue *Q, int *removed);

#endif