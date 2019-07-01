#include <stdio.h>
#include "BinarySearchTree.h"
#include "BinaryTree.h"

void main() {
	BTNode* avlRoot;
	BTNode* clNode;
	BTNode* crNode;
	BSTData data;

	BSTMakeAndInit(&avlRoot);

	while (1) {
		scanf("%d", &data);
		if (data < 1)
			break;

		BSTInsert(&avlRoot, data);
	}

	printf("루트노드: %d\n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d 오른쪽1: %d\n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽2: %d 오른쪽2: %d\n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(crNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽3: %d 오른쪽3: %d\n", GetData(clNode), GetData(crNode));

	DeleteBinaryTree(avlRoot);
}