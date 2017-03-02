#include "stackUsingArray.h"

void createStack(Stack *S, long n) {
	S->elems = malloc(sizeof(int) * n);
	S->top = NULL;
	S->size = 0;
	S->maxCapacity = n;
} 

void buildStack(Stack *S, long n, ...) {
	S->elems = malloc(sizeof(int) * n);
	S->top = NULL;
	S->size = 0;
	S->maxCapacity = -1;

	va_list stackElems;
	va_start(stackElems, n);

	for (size_t i = 0; i < n; ++i) {
		S->elems[i] = va_arg(stackElems, int);
		++(S->size);
		S->top = &(S->elems[i]);
	}
}