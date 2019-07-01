#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"
typedef BTData BSTData;

void BSTMakeAndInit(BTNode**);
BSTData BSTGetNodeData(BTNode*);
void BSTInsert(BTNode**, BSTData);
BTNode* BSTSearch(BTNode*, BSTData);
BTNode* BSTRemove(BTNode**, BSTData);
void BSTShowAll(BTNode*);

#endif // !__BINARY_SEARCH_TREE_H_B_
