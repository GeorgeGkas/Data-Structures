#include "setsUsingArray.h"

void buildSet(Set *S, int n, ...) {
    /**
     * Pass each argument, representing a set element,
     * from our variadic function to variadic list.
     */
    va_list setElems; 

    /**
     * Get the number of elements we want to pass
     * to our set.
     */
    va_start(setElems, n);

    /**
     * Allocates memmory for our set.
     */
    S->elems = malloc(sizeof(int)*n);

    /**
     * Pass each set element, to our set.
     */
    for (int i = 0; i < n; ++i) {
        S->elems[i] = va_arg(setElems, int);
    }

    /**
     * Frees the variadic list.
     */
    va_end(setElems);
}

void clearSet(Set *S) {
    /**
     * Frees the allocated block memory used for
     * set elements.
     */
    free(S->elems);
    S->elems = NULL;
}

void createSetWithCapacity(Set *S, int n) {
    /**
     * Allocates memmory for our set.
     */
    S->elems = malloc(sizeof(int)*n);
}
