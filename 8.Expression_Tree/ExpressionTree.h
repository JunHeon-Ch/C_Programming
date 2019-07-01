#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTNode* MakeExpTree(char[]);
int EvaluateExpTree(BTNode*);

void ShowPrefixExp(BTNode*);
void ShowInfixExp(BTNode*);
void ShowPostfixExp(BTNode*);

#endif
