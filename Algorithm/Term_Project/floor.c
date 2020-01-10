#include <stdio.h>
#include "floor.h"
#include "elevator.h"
#include "passenger.h"

void floorInit(Floor* floors) {
	int i;

	for (i = 1; i <= FLOOR_NUM; i++) {
		QueueInit(&floors[i].upQ);
		QueueInit(&floors[i].downQ);
	}
}

void waitingElevator(Queue* queue, Data psgr) {
	Enqueue(queue, psgr);
}

Data boardingElevator(Queue* queue) {
	return Dequeue(queue);
}

Data peekData(Queue* queue) {
	return QPeek(queue);
}

int isFloorEmpty(Queue* queue) {
	if (QIsEmpty(queue) == TRUE) {
		return TRUE;
	}
	else
		return FALSE;
}

int wholeFloorEmpty(Floor* floors) {
	int i;

	for (i = 1; i <= FLOOR_NUM; i++) {
		if (isFloorEmpty(&floors[i].upQ) == FALSE)
			return FALSE;
		if (isFloorEmpty(&floors[i].downQ) == FALSE)
			return FALSE;
	}

	return TRUE;
}

void printFloor(Floor* floors) {
	int i, j;

	printf("Floor\n");
	for (i = FLOOR_NUM; i > 0; i--) {
		if (isFloorEmpty(&floors[i].downQ) == TRUE)
			printf("0\t");
		else
			printf("1\t");

		if (isFloorEmpty(&floors[i].upQ) == TRUE)
			printf("0\t");
		else
			printf("1\t");
		printf("\n");
	}
}