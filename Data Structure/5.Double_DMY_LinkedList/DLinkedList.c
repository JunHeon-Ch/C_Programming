#include <stdio.h>
#include "DLinkedList.h"

void ListInit(List* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));

	list->head->prev = NULL;
	list->head->next = list->tail;

	list->tail->next = NULL;
	list->tail->prev = list->head;

	list->numOfData = 0;
}

void LInsert(List* list, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = list->tail->prev;
	list->tail->prev->next = newNode;

	newNode->next = list->tail;
	list->tail->prev = newNode;

	(list->numOfData)++;
}

int LFirst(List* list, Data* data) {
	if (list->head->next == list->tail)
		return FALSE;

	list->cur = list->head->next;
	*data = list->cur->data;
	return TRUE;
}

int LNext(List* list, Data* data) {
	if (list->cur->next == list->tail)
		return FALSE;

	list->cur = list->cur->next;
	*data = list->cur->data;
	return TRUE;
}

int LPrevious(List* list, Data* data) {
	if (list->cur->prev == list->head)
		return FALSE;

	list->cur = list->cur->prev;
	*data = list->cur->data;
	return TRUE;
}

Data LRemove(List* list) {
	Node* rPos = list->cur;
	Data rData = list->cur->data;

	list->cur->prev->next = list->cur->next;
	list->cur->next->prev = list->cur->prev;

	list->cur = list->cur->prev;

	free(rPos);
	(list->numOfData)--;
	return rData;
}

int LCount(List* list) {
	return list->numOfData;
}

void LFree(List* list) {
	Data data;

	if (LFirst(list, &data) == TRUE) {
		LRemove(list);
		while (LNext(list, &data) == TRUE)
			LRemove(list);
	}
	free(list->head);
	free(list->tail);
}