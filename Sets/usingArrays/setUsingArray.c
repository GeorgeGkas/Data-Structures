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
     * The number of elements in set structure.
     */
     S->size = n;

    /**
     * Using this function we don't restrict ourselves
     * of using any number of elements for our set, so
     * we "unset" maxSize member.
     */
     S->maxSize = -1;

    /**
     * Allocates memory for our set.
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

    /**
     * Zero the size of set.
     */
     S->size = 0;
     S->maxSize = -1;
}

void createSetWithCapacity(Set *S, int n) {
    /**
     * Using this function we build a static
     * set with n elements, so we want to set
     * a maximum number of elements.
     */
     S->maxSize = n;

     /**
      * No elements exist yet.
      */
      S->size = 0;

    /**
     * Allocates memory for our set.
     */
    S->elems = malloc(sizeof(int)*n);
}

int addElementInSet(Set *S, int x) {
    for (int i = 0; i < S->size; ++i) {
        if (S->elems[i] == x) { /* Element already exist. */
            return 1;
        }
    }

    if (S->maxSize == -1) { /* We haven't set a maximum set size. */
       /**
         * 1) Update the size of set with one more element.
         * 2) Reallocates memory for the new size.
         * 3) Add the new element.
         */
        ++(S->size);
        S->elems = realloc(S->elems, sizeof(int)*(S->size));
        S->elems[(S->size)-1] = x;
    } else { /* We set a maximum set size.*/
        if (S->size < S->maxSize) { /* If there is space to add one more element.*/
            /**
             * 1) Update the size of set with one more element.
             * 2) Reallocates memory for the new size.
             * 3) Add the new element.
             */
            ++(S->size);
            S->elems = realloc(S->elems, sizeof(int)*(S->size));
            S->elems[(S->size)-1] = x;
        } else {
            return -2;
        }
    }

    return 0;
}

void reduceSet(Set *S, void (*f)(int, void *), void *x) {
    for (int i = 0; i < S->size; ++i) {
        f(S->elems[i], x);
    }
}

size_t sizeOfSet(Set *S) {
    return S->size;
}

int isEmptySet(Set *S) {
    return (S->size == 0);
}