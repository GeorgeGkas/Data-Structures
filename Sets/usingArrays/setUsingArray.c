#include "setsUsingArray.h"

void buildSet(int **S, int n, ...) {
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
	*S = malloc(sizeof(int)*n);

	/**
	 * Pass each set element, to our set.
	 */
	for (int i = 0; i < n; ++i) {
		*(*S+i) = va_arg(setElems, int);
	}

	/**
	 * Frees the variadic list.
	 */
	va_end(setElems);
}