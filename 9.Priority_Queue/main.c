#include <stdio.h>
#include "PQueue.h"

int DataPriorityComp(PQata, PQData);

void main() {
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c\n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c\n", PDequeue(&pq));

	while(!PQIsEmpty(&pq))
		printf("%c\n", PDequeue(&pq));
}

int DataPriorityComp(HData d1, HData d2) {
	return d2 - d1;
}