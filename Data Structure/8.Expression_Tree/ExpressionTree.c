#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "ListStack.h"

BTNode* MakeExpTree(char exp[]) {
	BTNode* pnode;
	Stack stack;
	int i, expLen = strlen(exp);

	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		pnode = MakeBTreeNode();
		if (isdigit(exp[i]))
			SetData(pnode, exp[i] - '0');
		else {
			SetData(pnode, exp[i]);
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
		}
		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTNode* bt) {
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
}

void ShowNodeData(BTData data) {
	if (data >= 0 && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixExp(BTNode* bt) {
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixExp(BTNode* bt) {
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	ShowInfixExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixExp(bt->right);
	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}

void ShowPostfixExp(BTNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}