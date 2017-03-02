#include "stackUsingArray.h"

int main(void) {
	Stack S, U;

	createStack(&S, 8);
	buildStack(&S, 5, 1, 3, 5, 4, 8);

	return 0;
}