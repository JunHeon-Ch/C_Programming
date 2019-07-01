#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node {
	struct node* next;
	struct node* prev;
	Data data;
}Node;

typedef struct D_LinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
}LinkedList;

typedef LinkedList List;

void ListInit(List*);
void LInsert(List*, Data);

int LFirst(List*, Data*);
int LNext(List*, Data*);
int LPrevious(List*, Data*);

Data LRemove(List*);

int LCount(List*);
void LFree(List*);

#endif // !__D_LINKED_LIST_H__
