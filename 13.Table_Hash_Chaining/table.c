#include <stdio.h>
#include "Table.h"

void TBLInit(Table* pt, HashFunc* f) {
	int i;

	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	pt->hf = f;
}

void TBLInsert(Table* pt, Key key, Value val) {
	int hv = pt->hf(key);
	Slot ns = { key, val };

	if (TBLSearch(pt, ns.key) != NULL) {
		printf("Error\n");
		return;
	}
	else
		LInsert(&(pt->tbl[hv]), ns);
}

Value TBLDelete(Table* pt, Key key) {
	int hv = pt->hf(key);
	Slot ds;

	if (LFirst(&(pt->tbl[hv]), &ds) == TRUE) {
		if (ds.key == key) {
			LRemove(&(pt->tbl[hv]));
			return ds.val;
		}
		else {
			while (LNext(&(pt->tbl[hv]), &ds) == TRUE) {
				if (ds.key == key) {
					LRemove(&(pt->tbl[hv]));
					return ds.val;
				}
			}
		}
	}
	return NULL;
}

Value TBLSearch(Table* pt, Key key) {
	int hv = pt->hf(key);
	Slot ss;

	if (LFirst(&(pt->tbl[hv]), &ss) == TRUE) {
		if (ss.key == key)
			return ss.val;
		else {
			while (LNext(&(pt->tbl[hv]), &ss) == TRUE) {
				if (ss.key == key)
					return ss.val;
			}
		}
	}
	return NULL;
}