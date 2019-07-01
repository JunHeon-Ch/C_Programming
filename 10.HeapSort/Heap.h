#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef int HData;
typedef int PriorityComp(HData, HData);

typedef struct heap {
	int numOfData;
	PriorityComp* comp;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap*, PriorityComp);
int HIsEmpty(Heap*);

void HInsert(Heap*, HData);
HData HDelete(Heap*);
#endif