#include "setsUsingArray.h"

int main(void) {
    /**
    * Bellow we define our set.
    */
    int *S;

    /**
     * Build a set that contains all the capital letters of
     * the english alphabet.
     */
    buildSet(&S, 26, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', \
                       'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', \
                       'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', \
                       'Y', 'Z');

    /**
     * Print our set.
     */
    for (int i = 0; i < 26; ++i) {
        printf("%c\n", S[i]);
    }

    /**
     * Delete our set.
     * Now S is just an ordinary pointer.
     */
    deleteSet(&S);

    

    return 0;
}