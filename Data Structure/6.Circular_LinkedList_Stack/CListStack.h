#ifndef __C_LIST_STACK_H__
#define __C_LIST_STACK_H__

#include "CLinkedList.h"

typedef struct stack {
	CList* pList;
}Stack;

void StackInit(Stack*);
int SEmpty(Stack*);
void SPush(Stack*, Data);
Data SPop(Stack*);
Data SPeek(Stack*);
void SFree(Stack*);

#endif