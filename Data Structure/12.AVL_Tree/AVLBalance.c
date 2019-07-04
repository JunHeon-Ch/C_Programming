#include <stdio.h>
#include "BinaryTree.h"

BTNode* RotateLL(BTNode* bst) {
	BTNode* pNode;
	BTNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}

BTNode* RotateRR(BTNode* bst) {
	BTNode* pNode;
	BTNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

BTNode* RotateLR(BTNode* bst) {
	BTNode* pNode;
	BTNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}

BTNode* RotateRL(BTNode* bst) {
	BTNode* pNode;
	BTNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

int GetHeight(BTNode* bst) {
	int leftH, rightH;

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTNode* bst) {
	int lsh, rsh;

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
}

BTNode* Rebalance(BTNode** pRoot) {
	int hDiff = GetHeightDiff(*pRoot);

	if (hDiff > 1) {
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	if (hDiff < -1) {
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;
}