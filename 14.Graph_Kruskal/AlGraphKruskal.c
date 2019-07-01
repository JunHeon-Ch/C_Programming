#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AlGraphKruskal.h"
#include "ArrayStack.h"

int WhoIsPrecede(int, int);
int VisitVertex(Algraph*, int);
int PQWeightComp(Edge, Edge);
void RemoveEdge(Algraph*, int, int);
void RemoveWayEdge(Algraph*, int, int);
void RecoveryEdge(Algraph*, int, int);
int IsConnVertex(Algraph*, int, int);

void GraphInit(Algraph* pg, int nv) {
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	pg->numE = 0;
	pg->numV = nv;
	PQueueInit(&(pg->pqueue), PQWeightComp);

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

void AddEdge(Algraph* pg, int fromV, int toV, int weight) {
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	PEnqueue(&(pg->pqueue), edge);
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
//		printf("%c ", visitV + 65);
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

void ConKruskalMST(Algraph* pg) {
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;
	int i;

	while (pg->numE + 1 > pg->numV) {
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);
		if (IsConnVertex(pg, edge.v1, edge.v2) == FALSE) {
			RecoveryEdge(pg, edge.v1, edge.v2);
			recvEdge[eidx++] = edge;
		}
	}

	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(Algraph* pg) {
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (PQIsEmpty(&copyPQ) != TRUE) {
		edge = PDequeue(&copyPQ);
		printf("(%c - %c), w: %d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int PQWeightComp(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
}

void RemoveEdge(Algraph* pg, int fromV, int toV) {
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RemoveWayEdge(Algraph* pg, int fromV, int toV) {
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge) == TRUE) {
		if (edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}
		while (LNext(&(pg->adjList[fromV]), &edge) == TRUE) {
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

void RecoveryEdge(Algraph* pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

int IsConnVertex(Algraph* pg, int v1, int v2) {
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		int visitFlag = FALSE;

		if (nextV == v2)
			return TRUE;
		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, nextV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				if (nextV == v2)
					return TRUE;
				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, nextV);
					visitV = nextV;
					visitFlag = TRUE;
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

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;
}
