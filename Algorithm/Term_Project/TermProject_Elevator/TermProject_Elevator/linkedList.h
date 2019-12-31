#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "passenger.h"

#define TRUE 1
#define FALSE 0

typedef Passenger* LData;

typedef struct node {
	LData data;
	struct node* next;
}Node;

typedef struct linkedList {
	Node* head;
	Node* cur;
	Node* before;
	int(*comp)(LData d1, LData d2);
	int numOfData;
}LinkedList;

typedef LinkedList List;

void ListInit(List* plist); // 리스트 초기화

void LInsert(List* plist, LData data); // insert

int LFirst(List* plist, LData* pdata); // 첫번째 node 참조
int LNext(List* plist, LData* pdata); // 첫번째 이후 노드 참조

LData LRemove(List* plist); // delete

int LCount(List* plist); // 노드 수 count

#endif // !__LINKED_LIST_H__
