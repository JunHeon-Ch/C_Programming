#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
	struct node* prev;
}Node;

typedef struct dlDeque {
	Node* front;
	Node* tail;
}DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque*);
int DQIsEmpty(Deque*);

void DQAddFirst(Deque*, Data);
void DQAddLast(Deque*, Data);

Data DQRemoveFirst(Deque*);
Data DQRemoveLast(Deque*);

Data DQGetFirst(Deque*);
Data DQGetLast(Deque*);

#endif