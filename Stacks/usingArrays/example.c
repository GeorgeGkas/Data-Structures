#include "stackUsingArray.h"

int main(void) {
	Stack S, U;

	createStack(&S, 8);

	buildStack(&U, 5, 1, 3, 5, 4, 8);

	if (!pushStack(&S, 3)) {
		printf("Stack Overflow\n");
	}
	if (!pushStack(&S, 8)) {
		printf("Stack Overflow\n");
	}

	pushStack(&U, -5);
	pushStack(&U, 10);

	return 0;
}