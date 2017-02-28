#include "setsUsingArray.h"

void reduceCallback(int index, void *x) {
    printf("%c\n", index);
}

int mapCallback(int index) {
    return index + 1;
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

    res = addElementInSet(&S, 'D');
    if (res != 0) {
        exit(-1);
    }

    res = addElementInSet(&S, 'E');
    if (res != 0) {
        exit(-1);
    }

    res = addElementInSet(&S, 'C');
    if (res != 0) {
        exit(-1);
    }

    res = addElementInSet(&S, 'B');
    if (res != 0) {
        exit(-1);
    }

    setMin = minSet(&S);
    printf("%d\n", setMin);

    setMax = maxSet(&S);
    printf("%d\n", setMax);

    setSize = sizeOfSet(&S);
    printf("%ld\n", setSize);

    setSum = sumOfSet(&S);
    printf("%ld\n", setSum);

    empty = isEmptySet(&S);
    printf("%d\n", empty);

    /**
     * Print our set.
     */
    for (int i = 0; i < S.size; ++i) {
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
    buildSet(&S, 26, 'B', 'A', 'C', 'D', 'E', 'F', 'G', 'H', \
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
    for (int i = 0; i < S.size; ++i) {
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

    /**
     * Check sets equality.
     */
    buildSet(&S, 6, 5, 20, -8, 2, 3, -8);

    for (int i = 0; i < S.size; ++i) {
        printf("%d\n", S.elems[i]);
    }

    Set S1;
    buildSet(&S1, 5, 20, 5, -8, 3, 2);


    printf("%d\n", equalSets(&S, &S1));

    addElementInSet(&S1, 900);

    printf("%d\n", equalSets(&S, &S1));

    removeElementFromSet(&S1, 900);

    printf("%d\n", equalSets(&S, &S1));

    printf("%d\n", isElementOfSet(&S, 2));
    printf("%d\n", isElementOfSet(&S, 3));

    Set S2;
    buildSet(&S2, 3, 20, 5, 2);

    printf("%d %d\n", subSet(&S2, &S), minSet(&S2));

    clearSet(&S1);
    clearSet(&S2);

    printf("%d\n", subSet(&S2, &S1));

    Set U;
    buildSet(&U, 0);

    buildSet(&S2, 4, 'A', 'B', 'C', 'D');
    buildSet(&S1, 5, 'A', 'C', 'E', 'F', 'I');

    intersectionSet(&S2, &S1, &U);

    for (int i = 0; i < U.size; ++i) {
        printf("%c ", U.elems[i]);
    }
    printf("\n");

    clearSet(&U);
    buildSet(&U, 0);

    unionSet(&S2, &S1, &U);

    for (int i = 0; i < U.size; ++i) {
        printf("%c ", U.elems[i]);
    }
    printf("\n");

    clearSet(&U);
    buildSet(&U, 0);

    differenceSet(&S1, &S2, &U);

    for (int i = 0; i < U.size; ++i) {
        printf("%c ", U.elems[i]);
    }
    printf("\n");

    Set T;
    buildSet(&T, 0);
    mapSet(&S2, mapCallback, &T);
    reduceSet(&T, reduceCallback, NULL);

    return 0;
}