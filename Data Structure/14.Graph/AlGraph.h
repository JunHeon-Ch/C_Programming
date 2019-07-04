#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct algraph {
	int numV;
	int numE;
	List* adjList;
}Algraph;

void GraphInit(Algraph*, int);
void GraphDestroy(Algraph*);
void AddEdge(Algraph*, int, int);
void ShowGraphEdgeInfo(Algraph*);

#endif