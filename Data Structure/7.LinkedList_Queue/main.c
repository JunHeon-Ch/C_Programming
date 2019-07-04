#include <stdio.h>
#include "ListQueue.h"

void main() {
	Queue queue;
	Data rData;

	QueueInit(&queue);

	while (1) {
		scanf("%d", &rData);
		if (rData < 1)
			break;

		Enqueue(&queue, rData);
	}

	while (QIsEmpty(&queue) != TRUE) {
		printf("%d ", Dequeue(&queue));
	}

}