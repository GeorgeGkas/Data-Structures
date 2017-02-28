#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>

#define SET_ELEMENT_NOT_FOUND -1

typedef struct {
	int *elems; /* Array contains our set elements. */
	size_t size; /* Number of elements exist in set. */
	long maxSize; /* Maximum allowed number of elements in set. */
	long sum; /* Sum of all elements in set. */
	int *min; /* The minimum element in set. */
	int *max; /* The maximum element in set. */
} Set;

/**
 * Creates a set structure S 
 * with n elements x1,x2, x3,….
 */
void buildSet(Set *S, size_t n, ...);

/**
 * Delete all elements of S.
 */
void clearSet(Set *S);

/**
 * Creates a set structure S 
 * capable of holding up to n elements.
 */
void createSetWithCapacity(Set *S, size_t n);

/**
 * Adds the element x to S, 
 * if it is not present already.
 */
int addElementInSet(Set *S, int x);

/**
 * Iterates through every element in set S passing each 
 * element found in function f.
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

/**
 * Returns the minimum element of S.
 */
int minSet(Set *S);

/**
 * Returns the maximum element of S.
 */
int maxSet(Set *S);

/**
 * Checks if sets S1 and S2 contain all 
 * and only the same elements. 
 */
int equalSets(Set *S, Set *T);

/**
 * Checks whether the value x is in the set S.
 */
int isElementOfSet(Set *S, int x);

/**
 * Check if all elements in set S 
 * are also elements of set T.
 */
int subSet(Set *S, Set *T);

/**
 * Returns new set U with elements found on set S, 
 * that also belong on set T, but no other elements.
 */
void intersectionSet(Set *S, Set *T, Set *U);

/**
 * Returns new set U which contains all elements 
 * found both on set S and set T. 
 * As in sets no duplicates are allowed, 
 * U keeps only the first occurrence of each element.
 */
void unionSet(Set *S, Set *T, Set *U);

/**
 * Returns new set U which contains elements found 
 * on set S, but not on set T.
 */
void differenceSet(Set *S, Set *T, Set *U);

/**
 * Returns the set T of distinct values resulting 
 * from applying function f to each element of S.
 */
void mapSet(Set *S, int (*f)(int), Set *T);

/**
 * Returns the set T of distinct values resulting 
 * from applying function f to each element of S.
 */
void filterSet(Set *S, int (*f)(int), Set *T);

/**
 * Copy to set structure S all the elements 
 * of the given set T.
 */
void copyToSet(Set *S, Set *T);