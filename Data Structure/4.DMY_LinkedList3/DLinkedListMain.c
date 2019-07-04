#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int WhoIsPrecede(LData d1, LData d2) {
	if (d1.xpos < d2.xpos)
		return 0;
	else
		return 1;
}

void main(){
	List list;
	LData pData;
	int x, y;

	ListInit(&list);

//	SetSortRule(&list, WhoIsPrecede);

	while (1) {
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
			break;

		SetPointPos(&pData, x, y);
		LInsert(&list, pData);
	}

	printf("현재 데이터 수: %d\n", LCount(&list));

	if (LFirst(&list, &pData) == TRUE) {
		ShowPointPos(pData);
		while (LNext(&list, &pData) == TRUE) {
			ShowPointPos(pData);
		}
	}
	printf("\n\n");

	if (LFirst(&list, &pData) == TRUE) {
		if (pData.xpos == 2)
			LRemove(&list);
		while (LNext(&list, &pData) == TRUE) {
			if (pData.xpos == 2)
				LRemove(&list);
		}
	}
	printf("\n\n");

	printf("현재 데이터 수: %d\n", LCount(&list));

	if (LFirst(&list, &pData) == TRUE) {
		ShowPointPos(pData);
		while (LNext(&list, &pData) == TRUE) {
			ShowPointPos(pData);
		}
	}
\\\\\}