#ifndef _usingArrays_queueUsingArrays_H
#include "queueUsingArray.h"
#endif

int main(void) {
	Queue Q;
	createQueue(&Q);

	printf("Queue is empty: %d\n", isEmptyQueue(&Q));
	printf("Size of Queue is: %ld\n", sizeOfQueue(&Q));
	printf("The front element in our queue is: %d\n", peekQueue(&Q));

	printf("--INSERTING ELEMENS--\n");
	for (size_t i = 0; i <= 1000; ++i) {
		if (enQueue(&Q, i) == -1) {
			printf("out of memory...\n");
			exit(-1);
		}
	}

	printf("Queue is empty: %d\n", isEmptyQueue(&Q));
	printf("Size of Queue is: %ld\n", sizeOfQueue(&Q));
	printf("The front element in our queue is: %d\n", peekQueue(&Q));

	printf("--REMOVING ELEMENS--\n");
	for (int i = 0; i < 100; ++i) {
		deQueue(&Q);
	}

	printf("Queue is empty: %d\n", isEmptyQueue(&Q));
	printf("Size of Queue is: %ld\n", sizeOfQueue(&Q));
	printf("The front element in our queue is: %d\n", peekQueue(&Q));

	return 0;
}
