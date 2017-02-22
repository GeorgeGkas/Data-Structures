#include "setsUsingArray.h"

int main(void) {
	/**
	* Bellow we define our set.
	*/
	int *Set;

	/**
	 * Build a set that contains all the capital letters of
	 * the english alphabet.
	 */
	buildSet(&Set, 26, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', \
				'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', \
				'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', \
				'Y', 'Z');

	for (int i = 0; i < 26; ++i) {
		printf("%c\n", Set[i]);
	}

	return 0;
}