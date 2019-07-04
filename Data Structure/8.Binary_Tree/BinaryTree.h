#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct btnode {
	BTData data;
	struct btnode* left;
	struct btnode* right;
}BTNode;

BTNode* MakeBTreeNode();
BTData GetData(BTNode*);
void SetData(BTNode*, BTData);

BTNode* GetLeftSubTree(BTNode*);
BTNode* GetRightSubTree(BTNode*);

void MakeLeftSubTree(BTNode*, BTNode*);
void MakeRightSubTree(BTNode*, BTNode*);

typedef void (*VisitFuncPtr)(BTData);

void PreorderTraverse(BTNode*, VisitFuncPtr);
void InorderTraverse(BTNode*, VisitFuncPtr);
void PostorderTraverse(BTNode*, VisitFuncPtr);

void DeleteTree(BTNode*);
#endif
