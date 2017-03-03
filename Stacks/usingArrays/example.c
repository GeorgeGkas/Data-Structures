#include "stackUsingArray.h"

int main(void) {
	Stack S, U;
	int retval;

	retval = createStack(&S, 8);
	if (retval < 0) {
		printf("Could not create stack S\n");
		return -1;
	}

	retval = buildStack(&U, 5, 1, 3, 5, 4, 8);
	if (retval < 0) {
		printf("Could not build stack U\n");
		return -1;
	}

	retval = pushStack(&S, 3);
	if (retval < 0) {
		printf("Stack Overflow\n");
	} else {
		printf("pushed: %d to S.\n", 3);
	}

	retval = pushStack(&S, 8);
	if (retval < 0) {
		printf("Stack Overflow\n");
	} else {
		printf("pushed: %d to S.\n", 8);
	}

	retval = pushStack(&U, -5);
	if (retval < 0) {
		printf("Stack Overflow\n");
	} else {
		printf("pushed: %d to U.\n", -5);
	}

	retval = pushStack(&U, 10);
	if (retval < 0) {
		printf("Stack Overflow\n");
	} else {
		printf("pushed: %d to U.\n", 10);
	}

	printf("S is empty: %d\n", isEmptyStack(&S));

	printf("Top element of S: %d\n", peekStack(&S));

	printf("How many elements in our stack S? %ld\n", sizeOfStack(&S));

	int poped;
	while (poped = popStack(&S)) {
		printf("poped: %d from S.\n", poped);
	}

	printf("S is empty: %d\n", isEmptyStack(&S));

	printf("Top element of S: %d\n", peekStack(&S));

	printf("How many elements in our stack S? %ld\n", sizeOfStack(&S));
		
	return 0;
}