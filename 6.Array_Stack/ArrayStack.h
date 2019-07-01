#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct array_stack {
	Data stack[10];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack*);
int SEmpty(Stack*);
void SPush(Stack*, Data);
Data SPop(Stack*);
Data SPeek(Stack*);

#endif
