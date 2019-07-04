#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

void DequeInit(Deque* pdq) {
	pdq->front = NULL;
	pdq->tail = NULL;
}

int DQIsEmpty(Deque* pdq) {
	if (pdq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pdq->front;
	if (DQIsEmpty(pdq) == TRUE)
		pdq->tail = newNode;
	else
		pdq->front->prev = newNode;
	newNode->prev = NULL;
	pdq->front = newNode;
}

void DQAddLast(Deque* pdq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdq->tail;
	if (DQIsEmpty(pdq) == TRUE)
		pdq->front = newNode;
	else
		pdq->tail->next = newNode;
	newNode->next = NULL;
	pdq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdq) {
	Node* delNode;
	Data delData;

	if (DQIsEmpty(pdq) == TRUE) {
		printf("Deque is empty\n");
		exit(-1);
	}

	delNode = pdq->front;
	delData = delNode->data;

	pdq->front = pdq->front->next;
	if (pdq->front == NULL)
		pdq->tail = NULL;
	else
		pdq->front->prev = NULL;

	free(delNode);
	return delData;
}

Data DQRemoveLast(Deque* pdq) {
	Node* delNode;
	Data delData;

	if (DQIsEmpty(pdq) == TRUE) {
		printf("Deque is empty\n");
		exit(-1);
	}

	delNode = pdq->tail;
	delData = delNode->data;

	pdq->tail = pdq->tail->prev;
	if (pdq->tail == NULL)
		pdq->front = NULL;
	else
		pdq->tail->next = NULL;

	free(delNode);
	return delData;
}

Data DQGetFirst(Deque* pdq) {
	if (DQIsEmpty(pdq) == TRUE) {
		printf("Deque is empty\n");
		exit(-1);
	}

	return pdq->front->data;
}

Data DQGetLast(Deque* pdq) {
	if (DQIsEmpty(pdq) == TRUE) {
		printf("Deque is empty\n");
		exit(-1);
	}

	return pdq->tail->data;
}