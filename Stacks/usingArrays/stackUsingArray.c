#include "stackUsingArray.h"

int createStack(Stack *S, long n) {
	S->elems = malloc(sizeof(int) * n);
	if (S->elems == NULL) {
		return COULD_NOT_ALLOCATE;
	}

	S->top = NULL;
	S->size = 0;
	S->maxCapacity = n;
	return OPERATION_SUCCESS;
} 

int buildStack(Stack *S, long n, ...) {
	S->elems = malloc(sizeof(int) * n);
	if (S->elems == NULL) {
		return COULD_NOT_ALLOCATE;
	}

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

	return OPERATION_SUCCESS;
}

int pushStack(Stack *S, int x) {
	if (S->maxCapacity == -1) {
		++(S->size);
		S->elems = realloc(S->elems, sizeof(int) * (S->size));
		if (S->elems == NULL) {
			return COULD_NOT_ALLOCATE;
		}

		S->elems[(S->size)-1] = x;
		S->top = &(S->elems[(S->size)-1]);
	} else {
		if (S->size != S->maxCapacity)	{
			++(S->size);
			S->elems[(S->size)-1] = x;
			S->top = &(S->elems[(S->size)-1]);
		} else {
			return STACK_IS_FULL;
		}
	}
	return 0;
}

int popStack(Stack *S) {
	if (S->size == 0) {
		return 0;
	} else {
		S->top = &(S->elems[(S->size)-1]);
		--(S->size);
		return *(S->top);
	}
}

int isEmptyStack(Stack *S) {
	return (S->size ? 0 : 1);
}

int peekStack(Stack *S) {
	if (S->size == 0) {
		return 0;
	} else {
		return *(S->top);
	}
}

size_t sizeOfStack(Stack *S) {
	return S->size;
}