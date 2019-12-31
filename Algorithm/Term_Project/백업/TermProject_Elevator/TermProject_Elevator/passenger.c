#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"
#include "elevator.h"

Passenger* makePassenger(int startFloor, int endFloor) {
	Passenger* p = (Passenger*)malloc(sizeof(Passenger));

	p->weight = (rand() % WEIGHT_MAX) + 51;
	printf("weight %d\n", p->weight);
	p->startF = startFloor;
	p->endF = endFloor;

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