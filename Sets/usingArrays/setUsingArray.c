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
     * We initialize the sum counter. This will
     * allow us to get the sum using sumOfSet()
     * in O(1) time.
     */
     S->sum = 0;

    /**
     * Allocates memory for our set.
     */
    S->elems = malloc(sizeof(int)*n);

    /**
      * 1) Pass the first element to set.
      * 2) Update sum counter.
      * 3) Set the first set element to be both minimum and maximum 
      * element in set.
      */
    S->elems[0] = va_arg(setElems, int);
    S->sum += S->elems[0];
    S->min = S->max = &(S->elems[0]);

    /**
     * Pass each set element, to our set
     * and update the sum counter.
     * Also update min and max elements.
     */
    for (int i = 1; i < n; ++i) {
        S->elems[i] = va_arg(setElems, int);
        S->sum += S->elems[i];

        if (S->elems[i] < *(S->min)) {
            S->min = &(S->elems[i]);
        }

        if (S->elems[i] > *(S->max)) {
            S->max = &(S->elems[i]);
        }
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
     * Zero set values.
     */
     S->size = 0;
     S->maxSize = -1;
     S->sum = 0;
     S->min = S->max = NULL;
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
     * We initialize the sum counter. This will
     * allow us to get the sum using sumOfSet()
     * in O(1) time.
     */
     S->sum = 0;

     /**
      * No elements means no min and max value.
      */
    S->min = S->max = NULL;

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
            return -1;
        }
    }

    /**
     * We update the sum counter. This will
     * allow us to get the sum using sumOfSet()
     * in O(1) time.
     */
     S->sum += x;

    /**
     * If x is the first element in set,
     * use it as min and max, else check x 
     * with the current min and max.
     */
    if (S->min == NULL) {
        S->min = S->max = &(S->elems[(S->size)-1]);
    } else {
        if (x < *(S->min)) {
            S->min = &(S->elems[(S->size)-1]);
        }

        if (x > *(S->max)) {
            S->max = &(S->elems[(S->size)-1]);
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

long capacityOfSet(Set *S) {
    return S->maxSize;
}

int removeElementFromSet(Set *S, int x) {
    int xIndex;
    bool xExist = false;
    for (int i = 0; i < S->size; ++i) {
        if (S->elems[i] == x) { /* Found the position of x. */
            xIndex = i;
            xExist = true;
            break;
        }
    }

    if (!xExist) { /* We could not found the x in S. Element does not exist. */
        return 1;
    }

    /**
     * 1) Update the size of set with one more element.
     * 2) Move all elements after x one position back, as
     *    the cell of x is not needed now.
     * 3) Reallocate new size. This will delete the last 
     *    array cell, which really don't need it, cause we moved
     *    all elements back to one position.
     */
    --(S->size);
    for (int i = xIndex; i < S->size; ++i) {
        S->elems[i] = S->elems[i+1];
    }
    S->elems = realloc(S->elems, sizeof(int)*(S->size));


    /**
     * We update the sum counter. This will
     * allow us to get the sum using sumOfSet()
     * in O(1) time.
     */
     S->sum -= x;

     /**
      * Check if the removed element is the current
      * min or max one. If it is, then check the set
      * to find the new min or max value.
      */
    if (x == *(S->min)) {
        for (int i = 0; i < S->size; ++i) {
            if (S->elems[i] < *(S->min)) {
                S->min = &(S->elems[i]);
            }
        }
     } else if (x == *(S->max)) {
        for (int i = 0; i < S->size; ++i) {
            if (S->elems[i] > *(S->max)) {
                S->max = &(S->elems[i]);
            }
        }
     }
 
    return 0;
}

long sumOfSet(Set *S) {
    return S->sum;
}

int minSet(Set *S) {
    return *(S->min);
}

int maxSet(Set *S) {
    return *(S->max);
}