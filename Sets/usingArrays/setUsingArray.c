#include "setsUsingArray.h"

/**
 * Used as comparator function of qsort() to
 * sort the elements in ascending order.
 */
static int comparator_ascending(const void *elem1, const void *elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    return (f > s) - (f < s);
}

static void swapSetElements(int *E1, int *E2) {
    int tmp = (*E1);
    (*E1) = (*E2);
    (*E2) = tmp;
}

/**
 * lastSort is a variation of insert sort algorithm.
 * We take the newly added element which is in the last
 * position of our array-set and we move it to the left
 * until we find it's position.
 */
static void lastSort_ascending(Set *S, int x) {
    /**
     * 1) Update the size of set with one more element.
     * 2) Reallocates memory for the new size.
     * 3) Add x in the end of the array-set.
     * 4) Position the x in the correct place.
     */
    ++(S->size);
    S->elems = realloc(S->elems, sizeof(int)*(S->size));
    S->elems[(S->size)-1] = x;

    for (size_t i = (S->size)-1; i > 0 && S->elems[i] < S->elems[i-1]; --i ) {
        swapSetElements(&(S->elems[i]), &(S->elems[i-1]));
    }
}

void buildSet(Set *S, size_t n, ...) {
    va_list setElems; 
    va_start(setElems, n);

    S->size = 0;

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

    S->elems = malloc(0);

    /**
     * Pass each set element, to our set
     * and update the sum counter, only 
     * if there is not exist already.
     */
    int elem;
    for (size_t i = 0; i < n; ++i) {
        elem = va_arg(setElems, int);
        if (!isElementOfSet(S, elem)) {
            lastSort_ascending(S, elem);
            S->sum += elem;
        }
    }


    /**
     * We sort our set in ascending order. 
     * This will allow us to get better big-O complexity
     * in read functions. 
     */
    qsort(S->elems, S->size, sizeof(int), comparator_ascending);

    /**
     * Now the min element is the first one in our set implementation
     * with arrays and max element is the last one.
     */
    S->min = &(S->elems[0]);
    S->max = &(S->elems[(S->size)-1]);

    va_end(setElems);
}

void clearSet(Set *S) {
    free(S->elems);
    S->elems = NULL;

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

    S->elems = malloc(sizeof(int)*n);
}

int addElementInSet(Set *S, int x) {
    /**
     * We don't want to add duplicates values.
     */
    if (isElementOfSet(S, x)) {
        return 1;
    }

    /**
     * We have set a maximum set size and we
     * don't have capacity for new element x.
     */
    if (S->maxSize != -1 && S->size >= S->maxSize) {
        return -1;
    }

    /**
     * Insert element in set and position it.
     */
    lastSort_ascending(S, x);

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
    bool xExist = false; /* x exist in set? */
    for (size_t i = 0; i < S->size; ++i) {
        if (S->elems[i] == x) {
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

void intersectionSet(Set *S, Set *T, Set *U) {
    size_t i = 0, j = 0;
    while (i < S->size && j < T->size) {
        if (S->elems[i] == T->elems[j]) {
            lastSort_ascending(U, S->elems[i]);
            ++i;
            ++j;
        } else {
            if (S->elems[i] < T->elems[j]) {
                ++i;
            } else {
                ++j;
            }
        }    
    }
}

void unionSet(Set *S, Set *T, Set *U) {
    size_t i = 0, j = 0;
    while (i < S->size && j < T->size) {
        if (S->elems[i] < T->elems[j]) {
            lastSort_ascending(U, S->elems[i]);
            ++i;
        } else if (S->elems[i] > T->elems[j]) {
            lastSort_ascending(U, T->elems[j]);
            ++j;
        } else {
            lastSort_ascending(U, T->elems[j]);
            ++j;
            ++i;
        }
    }

    /**
     * S had more elements than T, so
     * insert the remaining ones to U.
     */
    while (i < S->size) {
        lastSort_ascending(U, S->elems[i]);
        ++i;
    } 

    /**
     * T had more elements than S, so
     * insert the remaining ones to U.
     */
    while (j < T->size) {
        lastSort_ascending(U, T->elems[j]);
        ++j;
    }
}

void differenceSet(Set *S, Set *T, Set *U) {
    size_t i = 0, j = 0;
    while (i < S->size && j < T->size) {
        if (S->elems[i] != T->elems[j]) {
            if (!isElementOfSet(T, S->elems[i])) {
                lastSort_ascending(U, S->elems[i]);
            }
        }
        ++i;
        ++j;
    }   

    /**
     * S had more elements than T, so
     * insert the remaining ones to U.
     */
    while (i < S->size) {
        lastSort_ascending(U, S->elems[i]);
        ++i;
    }
}