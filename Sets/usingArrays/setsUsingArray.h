#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>


typedef struct {
	int *elems; /* Array contains our set elements. */
	size_t size; /* Number of elements exist in set. */
	long maxSize; /* Maximum allowed number of elements in set. */
	long sum; /* Sum of all elements in set. */
} Set;

/**
 * Creates a set structure S 
 * with n elements x1,x2, x3,….
 */
void buildSet(Set *S, int n, ...);

/**
 * Delete all elements of S.
 */
void clearSet(Set *S);

/**
 * Creates a set structure S 
 * capable of holding up to n elements.
 */
void createSetWithCapacity(Set *S, int n);

/**
 * Adds the element x to S, 
 * if it is not present already.
 */
int addElementInSet(Set *S, int x);

/**
 * Iterate every element in S and pass it to function S.
 * x is used in case we want to return a result from f
 * back to our caller function.
 */
void reduceSet(Set *S, void (*f)(int, void *), void *x);

/**
 * Returns the number of elements in S.
 */
size_t sizeOfSet(Set *S);

/**
 * Checks whether the set S contains no elements.
 */
int isEmptySet(Set *S);

/**
 * Returns the maximum number of elements that S can hold.
 */
long capacityOfSet(Set *S);

/**
 * Removes the element x from S, 
 * if it is present.
 */
int removeElementFromSet(Set *S, int x);

/**
 * Returns the sum of all elements of S.
 */
long sumOfSet(Set *S);