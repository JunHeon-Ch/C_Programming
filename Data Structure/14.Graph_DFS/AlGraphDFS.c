#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AlGraphDFS.h"
#include "ArrayStack.h"

int WhoIsPrecede(int, int);
int VisitVertex(Algraph*, int);

void GraphInit(Algraph* pg, int nv) {
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	pg->numE = 0;
	pg->numV = nv;

	for (i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
	memset(pg->visitInfo, 0, sizeof(int) * nv);
}

void GraphDestroy(Algraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
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


int VisitVertex(Algraph* pg, int visitV) {
	if(pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

void DFSShowGRaphVertex(Algraph* pg, int startV) {
	Stack stack;
	int nextV, visitV = startV;

	StackInit(&stack);
	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		if (visitFlag == FALSE) {
			if (SEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int ) * pg->numV);
}

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}
