#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100

typedef int Data;

typedef struct queue {
	int front;
	int rear;
	Data queArr[QUE_LEN];
}Queue;

void QueueInit(Queue*);
int QIsEmpty(Queue*);

void Enqueue(Queue*, Data);
Data Dequeue(Queue*);
Data QPeek(Queue*);
#endif
