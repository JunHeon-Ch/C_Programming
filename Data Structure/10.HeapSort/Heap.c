#include "Heap.h"

void HeapInit(Heap* hp, PriorityComp comp) {
	hp->numOfData = 0;
	hp->comp = comp;
}

int HIsEmpty(Heap* hp) {
	if (hp->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIdx(int idx) {
	return idx / 2;
}

int GetLChildIdx(int idx) {
	return idx * 2;
}

int GetRChildIdx(int idx) {
	return idx * 2 + 1;
}

int GetHiPriChildIdx(Heap* hp, int idx) {
	if (hp->numOfData < GetLChildIdx(idx))
		return 0;
	else if (hp->numOfData == GetLChildIdx(idx))
		return GetLChildIdx(idx);
	else {
		if (hp->comp(hp->heapArr[GetLChildIdx(idx)], hp->heapArr[GetRChildIdx(idx)]) > 0)
			return GetLChildIdx(idx);
		else
			return GetRChildIdx(idx);
	}
}

void HInsert(Heap* hp, HData data) {
	int idx = hp->numOfData + 1;

	while (idx != 1) {
		if (hp->comp(data, hp->heapArr[GetParentIdx(idx)]) > 0) {
			hp->heapArr[idx] = hp->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}
	hp->heapArr[idx] = data;
	(hp->numOfData)++;
}

HData HDelete(Heap* hp) {
	HData delData = hp->heapArr[1];
	HData lastElem = hp->heapArr[hp->numOfData];

	int parentIdx = 1, childIdx;

	while (childIdx = GetHiPriChildIdx(hp, parentIdx)) {
		if (hp->comp(lastElem, hp->heapArr[childIdx]) < 0) {
			hp->heapArr[parentIdx] = hp->heapArr[childIdx];
			parentIdx = childIdx;
		}
		else
			break;
	}
	hp->heapArr[parentIdx] = lastElem;
	(hp->numOfData)--;
	return delData;
}
