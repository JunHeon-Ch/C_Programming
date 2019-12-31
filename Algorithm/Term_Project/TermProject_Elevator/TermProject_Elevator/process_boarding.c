#include <stdio.h>
#include <stdlib.h>

#include "process_boarding.h"
#include "process_run.h"
#include "door.h"
#include "floor.h"

void getInElevator(Elevator* elevators, Floor* floors) {
	int i;
	Passenger* p = NULL;

	for (i = 0; i < ELEVATOR_NUM; i++) {
		if (elevators[i].direction == UP) {
			while (isFloorEmpty(&(floors[elevators[i].now_f].upQ)) != TRUE) {
				p = peekData(&(floors[elevators[i].now_f].upQ));

				if (p->weight + elevators[i].now_w >= WEIGHT_MAX) // 엘리베이터 용량 초과
					break;

				else {
					stop(elevators);
					door_open(&elevators[i]);

					p = boardingElevator(&(floors[elevators[i].now_f].upQ));
					elevators[i].now_w += p->weight;
					LInsert(&(elevators[i].pasList), p);
					(elevators[i].pasCnt)++;

					door_close(&elevators[i]);

					printf("탑승 %d %d\n", p->startF, p->endF);
				}
			}
		}

		else if (elevators[i].direction == DOWN) {
			while (isFloorEmpty(&(floors[elevators[i].now_f].downQ)) != TRUE) {
				p = peekData(&(floors[elevators[i].now_f].downQ));

				if (p->weight + elevators[i].now_w >= WEIGHT_MAX)
					break;
				else {
					stop(elevators);
					door_open(&elevators[i]);

					p = boardingElevator(&(floors[elevators[i].now_f].downQ));
					elevators[i].now_w += p->weight;
					LInsert(&(elevators[i].pasList), p);
					(elevators[i].pasCnt)++;

					door_close(&elevators[i]);
				}

				printf("탑승 %d %d\n", p->startF, p->endF);
			}
		}
	}
}

void getOutElevator(Elevator* elevators) {
	Passenger* p;
	int i;

	for (i = 0; i < ELEVATOR_NUM; i++) {
		if (LFirst(&(elevators[i].pasList), &p) == TRUE) {
			if (p->endF == elevators[i].now_f) {
				stop(elevators);
				door_open(&elevators[i]);

				p = LRemove(&(elevators[i].pasList));
				elevators[i].now_w -= p->weight;
				(elevators[i].pasCnt)--;

				door_close(&elevators[i]);

				printf("하강 %d %d\n", p->startF, p->endF);
				free(p);
			}

			while (LNext(&(elevators[i].pasList), &p) == TRUE) {
				if (p->endF == elevators[i].now_f) {
					stop(elevators);
					door_open(&elevators[i]);

					p = LRemove(&(elevators[i].pasList));
					elevators[i].now_w -= p->weight;
					(elevators[i].pasCnt)--;

					door_close(&elevators[i]);

					printf("하강 %d %d\n", p->startF, p->endF);
					free(p);
				}
			}
		}
	}
}