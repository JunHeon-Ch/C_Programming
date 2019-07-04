#ifndef __LISTSTACK_H__
#define __LISTSTACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
}Node;

typedef struct stack {
	Node* head;
}Stack;

void StackInit(Stack*);
int SEmpty(Stack*);
void SPush(Stack*, Data);
Data SPop(Stack*);
Data SPeek(Stack*);
void SFree(Stack*);
#endif