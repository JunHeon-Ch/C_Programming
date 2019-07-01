#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

void StackInit(Stack* pStack) {
	pStack->head = NULL;
}

int SEmpty(Stack* pStack) {
	if (pStack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pStack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pStack->head;

	pStack->head = newNode;
}

Data SPop(Stack* pStack) {
	Node* rNode;
	Data rData;

	if (SEmpty(pStack) == TRUE) {
		printf("Error\n");
		exit(-1);
	}

	rNode = pStack->head;
	rData = pStack->head->data;

	pStack->head = pStack->head->next;

	free(rNode);
	return rData;
}

Data SPeek(Stack* pStack) {
	if (SEmpty(pStack) == TRUE) {
		printf("Error\n");
		exit(-1);
	}

	return pStack->head->data;
}

void SFree(Stack* pStack) {
	Node* fNode;

	while (SEmpty(pStack) != TRUE) {
		fNode = pStack->head;
		pStack->head = pStack->head->next;
		free(fNode);
	}
}