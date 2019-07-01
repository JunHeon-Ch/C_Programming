#include <stdio.h>
#include "CircularQueue.h"

void QueueInit(Queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

int QIsEmpty(Queue* queue) {
	if (queue->front == queue->rear)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* queue, Data data) {
	if (NextPosIdx(queue->rear) == queue->front) {
		printf("Queue is full\n");
		exit(-1);
	}

	queue->rear = NextPosIdx(queue->rear);
	queue->queArr[queue->rear] = data;
}

Data Dequeue(Queue* queue) {
	if (QIsEmpty(queue) == TRUE) {
		printf("Error: Queue is empty\n");
		exit(-1);
	}

	queue->front = NextPosIdx(queue->front);
	return queue->queArr[queue->front];
}

Data QPeek(Queue* queue) {
	if (QIsEmpty(queue) == TRUE) {
		printf("Queue is Empty\n");
		exit(-1);
	}

	return queue->queArr[NextPosIdx(queue->front)];
}