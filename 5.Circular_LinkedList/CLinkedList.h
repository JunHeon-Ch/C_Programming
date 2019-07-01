#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {
	Data data;
	struct node* next;
}Node;

typedef struct CLL {
	Node* cur;
	Node* before;
	Node* tail;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List*);

void LInsertTail(List*, Data);
void LInsertHead(List*, Data);

int LFirst(List*, Data*);
int LNext(List*, Data*);

Data LRemove(List*);
int LCount(List*);
#endif
