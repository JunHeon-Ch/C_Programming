#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
}Node;

typedef struct queue {
	Node* front;
	Node* rear;
}Queue;

void QueueInit(Queue*);
int QIsEmpty(Queue*);

void Enqueue(Queue*, Data);
Data Dequeue(Queue*);
Data QPeek(Queue*);

#endif 
