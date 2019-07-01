#ifndef __TABLE_H__
#define __TABLE_H__

#include "DLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key);

typedef struct table {
	List tbl[MAX_TBL];
	HashFunc* hf;
}Table;

void TBLInit(Table*, HashFunc*);
void TBLInsert(Table*, Key, Value);
Value TBLDelete(Table*, Key);
Value TBLSearch(Table*, Key);

#endif
