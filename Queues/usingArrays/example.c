#ifndef _usingArrays_queueUsingArrays_H
#include "queueUsingArray.h"
#endif

int main(void) {
	Queue Q;
	createQueue(&Q);

	printf("Queue is empty: %d\n", isEmptyQueue(&Q));
	printf("Size of Queue is %ld\n", sizeOfQueue(&Q));
	printf("The front element in our queue is: %d\n", peekQueue(&Q));



	return 0;
}
