#ifndef _usingArrays_queueUsingArrays_H
#define _usingArrays_queueUsingArrays_H

#ifndef _usingArrays_queueStruct_H
#include "queueStruct.h"
#endif

#ifndef _usingArrays_queue_exalloc_H
#include "queue_exalloc/queue_exalloc.h"
#endif

/**
 * Create an empty queue Q.
 */
void createQueue(Queue *Q);

/**
 * Returns the front element of the queue Q.
 */
int peekQueue(Queue *Q);

/**
 * checks whether the queue Q contains no elements 
 * and returns either 0 (not empty) or 1 (empty).
 */
int isEmptyQueue(Queue *Q);

/**
 * Returns the number of elements in queue Q.
 */
size_t sizeOfQueue(Queue *Q);

/**
 * Qnqueue element x to the rear of Q.
 */
int enQueue(Queue *Q, int x);

/**
 * Dequeue the front element of Q, returning it.
 */
int deQueue(Queue *Q);

#endif