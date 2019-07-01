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

	printf("��Ʈ���: %d\n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����1: %d ������1: %d\n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����2: %d ������2: %d\n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(crNode);
	crNode = GetRightSubTree(crNode);
	printf("����3: %d ������3: %d\n", GetData(clNode), GetData(crNode));

	DeleteBinaryTree(avlRoot);
}