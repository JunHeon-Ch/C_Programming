#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTNode** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTNode* bst) {
	return GetData(bst);
}

void BSTInsert(BTNode** pRoot, BSTData data) {
	if (*pRoot == NULL) {
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (GetData(*pRoot) < data) {
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (GetData(*pRoot) > data) {
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else
		return NULL;

	return *pRoot;
}

BTNode* BSTSearch(BTNode* bst, BSTData target) {
	BTNode* cNode = bst;
	BSTData cd;

	while (cNode != NULL) {
		cd = GetData(cNode);

		if (cd == target)
			return cNode;
		else if (cd > target)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

BTNode* BSTRemove(BTNode** pRoot, BSTData target) {
	BTNode* pVRoot = *pRoot;
	BTNode* pNode = pVRoot;
	BTNode* cNode = *pRoot;
	BTNode* dNode;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;

		if (GetData(cNode) > target)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)
		return NULL;

	dNode = cNode;

	if (GetLeftSubTree(cNode) == NULL && GetRightSubTree(cNode) == NULL) {
		if (GetLeftSubTree(pNode) == cNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	else if (GetLeftSubTree(cNode) == NULL || GetRightSubTree(cNode) == NULL) {
		BTNode* dcNode;

		if (GetLeftSubTree(cNode) != NULL)
			dcNode = GetLeftSubTree(cNode);
		else
			dcNode = GetRightSubTree(cNode);
		
		if (GetLeftSubTree(pNode) == cNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	else {
		BTNode* mNode = GetRightSubTree(dNode);
		BTNode* mpNode = dNode;
		BSTData delData;

		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	*pRoot = Rebalance(pRoot);
	return dNode;
}

void ShowIntAll(int data) {
	printf("%d ", data);
}

void BSTShowAll(BTNode* bt) {
	InorderTraverse(bt, ShowIntAll);
	printf("\n\n");
}