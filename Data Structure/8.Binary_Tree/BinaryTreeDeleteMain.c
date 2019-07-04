#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(BTData data);

int main(void)
{
	BTNode * bt1 = MakeBTreeNode();
	BTNode * bt2 = MakeBTreeNode();
	BTNode * bt3 = MakeBTreeNode();
	BTNode * bt4 = MakeBTreeNode();
	BTNode * bt5 = MakeBTreeNode();
	BTNode * bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	PreorderTraverse(bt1, ShowIntData);
	printf("\n");
	InorderTraverse(bt1, ShowIntData);
	printf("\n");
	PostorderTraverse(bt1, ShowIntData);
	printf("\n");

	DeleteTree(bt1);
	return 0;
}

void ShowIntData(BTData data)
{
	printf("%d ", data);
}
