#ifndef _usingArrays_queueUsingArrays_H
#include "queueUsingArray.h"
#endif

int main(void) {
	Queue Q;
	createQueue(&Q);

	int frontElem = peekQueue(&Q);
	printf("The front element in our queue is: %d\n", frontElem);

	return 0;
}
