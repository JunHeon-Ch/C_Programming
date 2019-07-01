#include <stdio.h>
#include "AlGraphBFS.h"

void main() {
	Algraph graph;

	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph); printf("\n");

	BFSShowGRaphVertex(&graph, A); printf("\n");
	BFSShowGRaphVertex(&graph, C); printf("\n");
	BFSShowGRaphVertex(&graph, E); printf("\n");
	BFSShowGRaphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
}