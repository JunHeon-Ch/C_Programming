#include <stdlib.h>
#include <stdio.h>
#include "ListQueue.h"

void QueueInit(Queue* pQueue) {
	pQueue->front = NULL;
}

int QIsEmpty(Queue* pQueue) {
	if (pQueue->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pQueue, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (QIsEmpty(pQueue) == TRUE)
		pQueue->front = newNode;
	else
		pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

Data Dequeue(Queue* pQueue) {
	Node* delNode;
	Data delData;

	if (QIsEmpty(pQueue) == TRUE) {
		printf("Queue is Empty\n");
		exit(-1);
	}

	delNode = pQueue->front;
	delData = delNode->data;
	pQueue->front = pQueue->front->next;

	free(delNode);
	return delData;
}

Data QPeek(Queue* pQueue) {
	if (QIsEmpty(pQueue) == TRUE) {
		printf("Queue is empty\n");
		exit(-1);
	}

	return pQueue->front->data;
}