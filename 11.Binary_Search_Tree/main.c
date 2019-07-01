#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

void main() {
	BTNode* bstRoot;
	BTNode* sNode;
	BSTData data;
	int select;
	
	BSTMakeAndInit(&bstRoot);

	do {
		printf("\nExit -> 0\nInsert -> 1\nDelete -> 2\nPrint -> 3\n");
		scanf("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			scanf("%d", &data);
			BSTInsert(&bstRoot, data);
			break;
		case 2:
			scanf("%d", &data);
			sNode = BSTRemove(&bstRoot, data);
			printf("Delete Data : %d\n", GetData(sNode));
			free(sNode);
			break;
		case 3:
			BSTShowAll(bstRoot);
			break;
		}
	} while (select != 0);

	DeleteBinaryTree(bstRoot);
}