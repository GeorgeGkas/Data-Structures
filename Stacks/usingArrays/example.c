#include "stackUsingArray.h"

int main(void) {
	Stack S, U;

	createStack(&S, 8);

	buildStack(&U, 5, 1, 3, 5, 4, 8);

	if (!pushStack(&S, 3)) {
		printf("Stack Overflow\n");
	} else {
		printf("pushed: %d to S.\n", 3);
	}
	if (!pushStack(&S, 8)) {
		printf("Stack Overflow\n");
	} else {
		printf("pushed: %d to S.\n", 8);
	}

	if (!pushStack(&U, -5)) {
		printf("Error\n");
	} else {
		printf("pushed: %d to U.\n", -5);
	}
	if (!pushStack(&U, 10)) {
		printf("Error\n");
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