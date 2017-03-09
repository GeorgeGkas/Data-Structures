#ifndef _usingArrays_queueUsingArrays_H
#define _usingArrays_queueUsingArrays_H

#ifndef _usingArrays_queueStruct_H
#include "queueStruct.h"
#endif

#include <stdlib.h>

/**
 * Create an empty queue Q.
 */
void createQueue(Queue *Q);

/**
 * Returns the front element of the queue Q.
 */
int peekQueue(Queue *Q);

#endif