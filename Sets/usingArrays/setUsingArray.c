#include "setsUsingArray.h"

void buildSet(int **Set, int numOfElems, ...) {
	va_list setElems;
	va_start(setElems, numOfElems);

	*Set = malloc(sizeof(int)*numOfElems);

	for (int i = 0; i < numOfElems; ++i) {
		*(*Set+i) = va_arg(setElems, int);
	}

	va_end(setElems);
}