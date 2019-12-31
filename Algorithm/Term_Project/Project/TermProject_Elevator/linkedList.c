#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//초기화
void ListInit(List * plist) {
	plist->before = NULL;
	plist->cur = NULL;
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

//노드삽입
void LInsert(List * plist, LData data) {
	Node* pred = plist->head;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

//첫노드 참조
int LFirst(List * plist, LData * pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

//첫노드 이후 노드 참조
int LNext(List * plist, LData * pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

//노드삭제
LData LRemove(List * plist) {
	Node* Rpos = plist->cur;
	LData Rdata = Rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(Rpos);
	(plist->numOfData)--;
	return Rdata;
}

//노드수 반환
int LCount(List * plist) {
	return plist->numOfData;
}

//정렬방법 초기화
void SetSortRule(List * plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}