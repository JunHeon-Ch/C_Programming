#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"
#include "elevator.h"

Passenger* makePassenger() {
	Passenger* p = (Passenger*)malloc(sizeof(Passenger));

	p->weight = (rand() % WEIGHT_MAX) + 1;
	p->startF = (rand() % FLOOR_NUM) + 1;
	p->endF = (rand() % FLOOR_NUM) + 1;

	if (p->startF > p->endF) {
		p->direction = DOWN;
		(p->p).x = 1;
	}
	else if (p->startF < p->endF) {
		p->direction = UP;
		(p->p).x = 3;
	}
	else
		return NULL;

	(p->p).y = p->startF;

	return p;
}