#include "PQueue.h"
#include "Heap.h"

void PQueueInit(PQueue* ppq, PriorityComp comp) {
	ppq->numOfData = 0;
	ppq->comp = comp;
}

int PQIsEmpty(PQueue* ppq) {
	HIsEmpty(ppq);
}

void PEnqueue(PQueue* ppq, PQData data) {
	HInsert(ppq, data);
}
PQData PDequeue(PQueue* ppq) {
	return HDelete(ppq);
}
