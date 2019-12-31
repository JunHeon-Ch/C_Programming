#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//�ʱ�ȭ
void ListInit(List * plist) {
	plist->before = NULL;
	plist->cur = NULL;
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

//������
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

//ù��� ����
int LFirst(List * plist, LData * pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

//ù��� ���� ��� ����
int LNext(List * plist, LData * pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

//������
LData LRemove(List * plist) {
	Node* Rpos = plist->cur;
	LData Rdata = Rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(Rpos);
	(plist->numOfData)--;
	return Rdata;
}

//���� ��ȯ
int LCount(List * plist) {
	return plist->numOfData;
}

//���Ĺ�� �ʱ�ȭ
void SetSortRule(List * plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}