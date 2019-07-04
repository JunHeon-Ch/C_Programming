#include <stdio.h>
#include "AlGraphDFS.h"

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


	DFSShowGRaphVertex(&graph, A); printf("\n");
	DFSShowGRaphVertex(&graph, C); printf("\n");
	DFSShowGRaphVertex(&graph, E); printf("\n");
	DFSShowGRaphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
}