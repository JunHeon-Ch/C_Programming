#include <stdio.h>
#include "Table.h"

void TBLInit(Table* pt, HashFunc* f) {
	int i;

	for (i = 0; i < MAX_TBL; i++)
		pt->tbl[i].status = EMPTY;

	pt->hf = f;
}

void TBLInsert(Table* pt, Key key, Value val) {
	int hv = pt->hf(key);
	pt->tbl[hv].key = key;
	pt->tbl[hv].val = val;
	pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table* pt, Key key) {
	int hv = pt->hf(key);

	if (pt->tbl[hv].status != INUSE)
		return NULL;
	else {
		pt->tbl[hv].status = DELETED;
		return pt->tbl[hv].val;
	}
}

Value TBLSearch(Table* pt, Key key) {
	int hv = pt->hf(key);

	if (pt->tbl[hv].status != INUSE)
		return NULL;
	else
		return pt->tbl[hv].val;
}