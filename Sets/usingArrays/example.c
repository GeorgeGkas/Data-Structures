#include "setsUsingArray.h"

void reduceCallback(int index, void *x) {
    printf("%c\n", index);
}

int main(void) {
    /**
     * Bellow we define our set.
     */
    Set S;

    /**
     * Return code.
     */
    int res;
 
    /**
     * Create a set for storing 5 elements.
     */
    createSetWithCapacity(&S, 5);

    /**
     * Print set sum.
     */
    long setSum = sumOfSet(&S);
    printf("%ld\n", setSum);

    /**
     * Get the size of set.
     */
    size_t setSize = sizeOfSet(&S);
    printf("%ld\n", setSize);

    /**
     * Get the max capacity of set.
     */
    long capacitySet = capacityOfSet(&S);
    printf("%ld\n", capacitySet);

    /**
     * Check if S is empty.
     */
    int empty = isEmptySet(&S);
    printf("%d\n", empty);

    /**
     * Add elements to set.
     */
    res = addElementInSet(&S, 'A');
    if (res != 0) {
        exit(-1);
    }

    /**
     * Show min and max element in set.
     */
    int setMin = minSet(&S);
    printf("%d\n", setMin);

    int setMax = maxSet(&S);
    printf("%d\n", setMax);

    /**
     * Remove element from set.
     */
    res = removeElementFromSet(&S, 'A');
    if (res != 0) {
        exit(-1);
    }

    res = addElementInSet(&S, 'B');
    if (res != 0) {
        exit(-1);
    }

    res = addElementInSet(&S, 'C');
    if (res != 0) {
        exit(-1);
    }

    res = addElementInSet(&S, 'D');
    if (res != 0) {
        exit(-1);
    }

    res = addElementInSet(&S, 'E');
    if (res != 0) {
        exit(-1);
    }

    setMin = minSet(&S);
    printf("%d\n", setMin);

    setMax = maxSet(&S);
    printf("%d\n", setMax);

    setSize = sizeOfSet(&S);
    printf("%ld\n", setSize);

    empty = isEmptySet(&S);
    printf("%d\n", empty);

    /**
     * Print our set.
     */
    for (int i = 0; i < 5; ++i) {
        printf("%c\n", S.elems[i]);
    }

    /**
     * Delete our set.
     * Now S is empty.
     */
    clearSet(&S);

    /**
     * Build a set that contains all the capital letters of
     * the English alphabet.
     */
    buildSet(&S, 26, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', \
                     'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', \
                     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', \
                     'Y', 'Z');


    setMin = minSet(&S);
    printf("%d\n", setMin);

    setMax = maxSet(&S);
    printf("%d\n", setMax);

    /**
     * Get the max capacity of set.
     */
    capacitySet = capacityOfSet(&S);
    printf("%ld\n", capacitySet);

    /**
     * Print set sum.
     */
    setSum = sumOfSet(&S);
    printf("%ld\n", setSum);

    res = removeElementFromSet(&S, 'W');
    if (res != 0) {
        exit(-1);
    }

    /**
     * Print our set.
     */
    for (int i = 0; i < 26; ++i) {
        printf("%c\n", S.elems[i]);
    }

    /**
     * We also can use reduceSet function to print our
     * results.
     */
    reduceSet(&S, reduceCallback, NULL);

    clearSet(&S);

    /**
     * The above procedure could be done like the following example.
     */
    buildSet(&S, 0);
    for (int i = 65; i < 65+26; ++i) {
        res = addElementInSet(&S, i);
        if (res != 0) {
            exit(-1);
        }
    }

    /**
     * Print our set.
     */
    reduceSet(&S, reduceCallback, NULL);

    /**
     * Print set sum.
     */
    setSum = sumOfSet(&S);
    printf("%ld\n", setSum);

    clearSet(&S);

    return 0;
}