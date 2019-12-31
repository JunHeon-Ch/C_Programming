#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define MAX_PSGR 100

#include "passenger.h"

typedef Passenger* Data;

typedef struct queue {
	int front;
	int rear;
	Data queArr[MAX_PSGR];
}Queue;

void QueueInit(Queue* queue); // queue �ʱ�ȭ
int QIsEmpty(Queue* queue); // queue ������� Ȯ��

void Enqueue(Queue* queue, Data data); // insert
Data Dequeue(Queue* queue); // delete
Data QPeek(Queue* queue); // peek
#endif
