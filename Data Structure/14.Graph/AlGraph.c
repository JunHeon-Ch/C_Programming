#include <stdio.h>
#include "AlGraph.h"

int WhoIsPrecede(int, int);

void GraphInit(Algraph* pg, int nv) {
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numE = 0;
	pg->numV = nv;

	for (i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestroy(Algraph* pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numE; i++) {
		if (LFirst(&(pg->adjList[i]), &vx) == TRUE)
			LRemove(&(pg->adjList[i]));
		while (LNext(&(pg->adjList[i]), &vx) == TRUE)
			LRemove(&(pg->adjList[i]));
	}
	
	if (pg->adjList != NULL)
		free(pg->adjList);
}

void AddEdge(Algraph* pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(Algraph* pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c -> ", i + 65);
		if (LFirst(&(pg->adjList[i]), &vx) == TRUE) {
			printf("%c ", vx + 65);
			while (LNext(&(pg->adjList[i]), &vx) == TRUE)
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}