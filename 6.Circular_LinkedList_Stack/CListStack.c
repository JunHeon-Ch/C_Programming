#include <stdio.h>
#include <stdlib.h>
#include "CListStack.h"

void StackInit(Stack* pStack) {
	pStack->pList = (List*)malloc(sizeof(List));
	ListInit(pStack->pList);
}

int SEmpty(Stack* pStack) {
	if (LCount(pStack->pList) == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pStack, Data data) {
	LInsertHead(pStack->pList, data);
}

Data SPop(Stack* pStack) {
	Data rData;

	LFirst(pStack->pList, &rData);
	LRemove(pStack->pList);
	return rData;
}

Data sPeek(Stack* pStack) {
	Data rData;

	LFirst(pStack->pList, &rData);
	return rData;
}

void SFree(Stack* pStack) {
	Data tData;

	if (LFirst(pStack->pList, &tData) == TRUE) {
		LRemove(pStack->pList);
		while(LNext(pStack->pList, &tData) == TRUE)
			LRemove(pStack->pList);
	}
	free(pStack->pList);
}