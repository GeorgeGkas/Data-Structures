#include "setsUsingArray.h"

/**
 * Used as comparator function of qsort to
 * sort the elements in ascending order.
 * Return 1 if f > s.
 * Return 0 if f = s.
 * Return -1 if f < s.
 */
static int comparator_ascending(const void *elem1, const void *elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    return (f > s) - (f < s);
}

void buildSet(Set *S, size_t n, ...) {
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
      */
    S->elems[0] = va_arg(setElems, int);
    S->sum += S->elems[0];

    /**
     * Pass each set element, to our set
     * and update the sum counter.
     */
    for (size_t i = 1; i < n; ++i) {
        S->elems[i] = va_arg(setElems, int);
        S->sum += S->elems[i];
    }


    /**
     * We sort our set in ascending order. 
     * This will allow us to get better big-O complexity
     * in read functions. 
     */
    qsort (S->elems, S->size, sizeof(int), comparator_ascending);

    /**
     * Now the min element is the first one in our set implementation
     * with arrays and max element is the last one.
     */
     S->min = &(S->elems[0]);
     S->max = &(S->elems[(S->size)-1]);

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

void createSetWithCapacity(Set *S, size_t n) {
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
    for (size_t i = 0; i < S->size; ++i) {
        if (S->elems[i] == x) { /* Element already exist. */
            return 1;
        }
    }

    if (S->maxSize == -1) { /* We haven't set a maximum set size. */
        /**
         * Search the array-set for the position of the 
         * last element that was smallest than x.
         * That way we can know in which place we insert x.
         */
        long xIndex = 0;
        for (size_t i = 0; i < S->size; ++i) {
            if (S->elems[i] > x) {
                break;
            }
            xIndex = (long)i;
        }

       /**
         * 1) Update the size of set with one more element.
         * 2) Reallocates memory for the new size.
         */
        ++(S->size);
        S->elems = realloc(S->elems, sizeof(int)*(S->size));

        /**
         * Shift all elements found after the position xIndex
         * one place to right. If there is no element then
         * we just skip the operation.
         */
        for (long i = S->size-2; i > xIndex; --i) {
            S->elems[i+1] = S->elems[i];
        }

        /**
         * If the newly added element x is the first one,
         * take the place of the current xIndex.
         * Else add x one cell to right to avoid 
         * overriding the element in xIndex.
         */
        if (S->size == 1) {
            S->elems[xIndex] = x;
        } else {
            S->elems[xIndex+1] = x;
        }        
    } else { /* We set a maximum set size.*/
        if (S->size < S->maxSize) { /* If there is space to add one more element.*/
            /**
             * Search the array-set for the position of the 
             * last element that was smallest than x.
             * That way we can now in which place we insert x.
             */
            long xIndex = 0;
            for (size_t i = 0; i < S->size; ++i) {
                if (S->elems[i] > x) {
                    break;
                }
                xIndex = (long)i;
            }

           /**
             * 1) Update the size of set with one more element.
             * 2) Reallocates memory for the new size.
             */
            ++(S->size);
            S->elems = realloc(S->elems, sizeof(int)*(S->size));

            /**
             * Shift all elements found after the position xIndex
             * one place to right. If there is no element then
             * we just skip the operation.
             */
            for (long i = S->size-2; i > xIndex; --i) {
                S->elems[i+1] = S->elems[i];
            }

            /**
             * If the newly added element x is the first one,
             * take the place of the current xIndex.
             * Else add x one cell to right to avoid 
             * overriding the element in xIndex.
             */
            if (S->size == 1) {
                S->elems[xIndex] = x;
            } else {
                S->elems[xIndex+1] = x;
            }        
        } else { 
            return -1; /* Set is full. */
        }
    }

    /**
     * We update the sum counter. This will
     * allow us to get the sum using sumOfSet()
     * in O(1) time.
     */
     S->sum += x;

    /**
     * Update the values of min and max
     * with the first and last element in set-array. 
     * This is possible by the time we keep our set-array sorted.
     */
    S->min = &(S->elems[0]);
    S->max = &(S->elems[(S->size)-1]);

    return 0;
}

void reduceSet(Set *S, void (*f)(int, void *), void *x) {
    for (size_t i = 0; i < S->size; ++i) {
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
    size_t xIndex;
    bool xExist = false;
    for (size_t i = 0; i < S->size; ++i) {
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
     * 1) Update the size of set with one less element.
     * 2) Move all elements after x one position back, as
     *    the cell of x is not needed now.
     * 3) Reallocate new size. This will delete the last 
     *    array cell, which really don't need it, cause we moved
     *    all elements back to one position.
     */
    --(S->size);
    for (size_t i = xIndex; i < S->size; ++i) {
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
     * Update the values of min and max
     * with the first and last element in set-array. 
     * This is possible by the time we keep our set-array sorted.
     * If size is zero, the last element is set was just removed,
     * then there is no min and max.
     */
    if (S->size == 0) {
        S->min = S->max = NULL;
    } else {
        S->min = &(S->elems[0]);
        S->max = &(S->elems[(S->size)-1]);
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

int equalSets(Set *S, Set *T) {
    /**
     * First check if two sets have the
     * same number of elements.
     */
    if (S->size != T->size) {
        return 0;
    }

    /**
     * Then check if the two sets contains the same
     * elements. We only have to use one iteration
     * because we keep the set-array sorted, that 
     * means the neighbor values should be equal.
     */
    for (size_t i = 0; i < S->size; ++i) {
        if (S->elems[i] != T->elems[i]) {
            return 0;
        }
    }

    return 1;
}

int isElementOfSet(Set *S, int x) {
    /**
     * We use binary search in our array-set
     * to find if x belongs to S.
     */
    int middle, left = 0, right = (S->size)-1;
    while (left <= right) {
        middle = (left + right)/2;
        if (S->elems[middle] == x) {
            return 1;
        } else {
            if (S->elems[middle] > x) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
    }

    return 0;
}

int subSet(Set *S, Set *T) {
    /**
     * S has more elements than T.
     */
    if (S->size > T->size) {
        return 0;
    }

    /**
     * Check each element in S if it's present in T.
     * By the time we have sorted our set-array we 
     * know that if Si goes greater than Tj the element
     * is not exist, so we can terminate the procedure.
     */
    size_t i = 0, j = 0;
    while (i < S->size && j < T->size) {
        if (S->elems[i] == T->elems[j]) {
            ++i; /* Found Si on Tj. Proceed to next element in S. */
        } else if (S->elems[i] < T->elems[j]) {
            return 0; /* Element Si has not been found on Tj. */
        } else {
            ++j; /* Check the next element in T if match Si. */
        }
    }

    return 1;
}