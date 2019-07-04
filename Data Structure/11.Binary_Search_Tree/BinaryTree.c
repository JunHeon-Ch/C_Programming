#include <stdlib.h>
#include "BinaryTree.h"

BTNode* MakeBTreeNode() {
	BTNode* nd = (BTNode*)malloc(sizeof(BTNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTNode* bt) {
	return bt->data;
}

void SetData(BTNode* bt, BTData data) {
	bt->data = data;
}

BTNode* GetLeftSubTree(BTNode* bt) {
	return bt->left;
}

BTNode* GetRightSubTree(BTNode* bt) {
	return bt->right;
}

void MakeLeftSubTree(BTNode* main, BTNode* sub) {
	if (main->left != NULL)
		DeleteBinaryTree(main->left);
	
	main->left = sub;
}
void MakeRightSubTree(BTNode* main, BTNode* sub) {
	if (main->right != NULL)
		DeleteBinaryTree(main->right);

	main->right = sub;
}

void ChangeLeftSubTree(BTNode* main, BTNode* sub) {
	main->left = sub;
}

void ChangeRightSubTree(BTNode* main, BTNode* sub) {
	main->right = sub;
}

BTNode* RemoveLeftSubTree(BTNode* bt) {
	BTNode* delNode;

	if (bt->left != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	
	return delNode;
}

BTNode* RemoveRightSubTree(BTNode* bt) {
	BTNode* delNode;

	if (bt->right != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}

	return delNode;
}

void PreorderTraverse(BTNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void DeleteBinaryTree(BTNode* bt) {
	if (bt == NULL)
		return;

	DeleteBinaryTree(bt->left);
	DeleteBinaryTree(bt->right);
	free(bt);
}