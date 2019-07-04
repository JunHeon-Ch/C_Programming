#ifndef __P_QUEUE_H__
#define __P_QUEUE_H__

#include "Heap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue*, PriorityComp);
int PQIsEmpty(PQueue*);

void PEnqueue(PQueue*, PQData);
PQData PDequeue(PQueue*);

#endif
