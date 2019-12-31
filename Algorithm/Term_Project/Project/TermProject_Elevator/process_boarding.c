#include <stdio.h>
#include <stdlib.h>

#include "process_boarding.h"
#include "process_run.h"
#include "door.h"
#include "floor.h"
#include "WinSock2.send.h"

void getInElevator(Elevator* elevators, Floor* floors, SOCKET socket) {
	int i;
	Passenger* p = NULL;

	for (i = 0; i < ELEVATOR_NUM; i++) {
		if (elevators[i].direction == UP) {
			while (isFloorEmpty(&(floors[elevators[i].now_f].upQ)) != TRUE) {
				p = peekData(&(floors[elevators[i].now_f].upQ));

				if (p->weight + elevators[i].now_w > CAPACITY_MAX) // 엘리베이터 용량 초과
					break;

				command_getin(socket, p->startF, p->endF);
				update_icon(socket, elevators[i], ICO_GETIN);

				stop(elevators);
				door_open(&elevators[i]);

				p = boardingElevator(&(floors[elevators[i].now_f].upQ));
				elevators[i].now_w += p->weight;
				LInsert(&(elevators[i].pasList), p);
				(elevators[i].pasCnt)++;

				door_close(&elevators[i]);


				update_icon(socket, elevators[i], elevators[i].now_w < CAPACITY_MAX ? ICO_NORMAL : ICO_OCCUPIED);

				printf("탑승 %d %d\n", p->startF, p->endF);
			}

			elevators[i].state = RUN;
		}

		else if (elevators[i].direction == DOWN) {
			while (isFloorEmpty(&(floors[elevators[i].now_f].downQ)) != TRUE) {
				p = peekData(&(floors[elevators[i].now_f].downQ));

				if (p->weight + elevators[i].now_w > CAPACITY_MAX)
					break;

				command_getin(socket, p->startF, p->endF);
				update_icon(socket, elevators[i], ICO_GETIN);

				stop(elevators);
				door_open(&elevators[i]);

				p = boardingElevator(&(floors[elevators[i].now_f].downQ));
				elevators[i].now_w += p->weight;
				LInsert(&(elevators[i].pasList), p);
				(elevators[i].pasCnt)++;

				door_close(&elevators[i]);


				update_icon(socket, elevators[i], elevators[i].now_w < CAPACITY_MAX ? ICO_NORMAL : ICO_OCCUPIED);

				printf("탑승 %d %d\n", p->startF, p->endF);
			}

			elevators[i].state = RUN;
		}

	}
}


void getOutElevator(Elevator* elevators, Floor* floors, SOCKET socket) {
	Passenger* p;
	int i;

	for (i = 0; i < ELEVATOR_NUM; i++) {
		if (LFirst(&(elevators[i].pasList), &p) == TRUE) {
			if (p->endF == elevators[i].now_f) {
				command_getout(socket, p->endF);
				update_icon(socket, elevators[i], ICO_GETOUT);

				stop(elevators);
				door_open(&elevators[i]);

				p = LRemove(&(elevators[i].pasList));
				elevators[i].now_w -= p->weight;
				(elevators[i].pasCnt)--;

				update_icon(socket, elevators[i], elevators[i].now_w < CAPACITY_MAX ? ICO_NORMAL : ICO_OCCUPIED);

				printf("내림 %d %d\n", p->startF, p->endF);
				free(p);
			}

			else {
				while (LNext(&(elevators[i].pasList), &p) == TRUE) {
					if (p->endF == elevators[i].now_f) {
						command_getout(socket, p->endF);
						update_icon(socket, elevators[i], ICO_GETOUT);

						p = LRemove(&(elevators[i].pasList));
						elevators[i].now_w -= p->weight;
						(elevators[i].pasCnt)--;

						update_icon(socket, elevators[i], elevators[i].now_w < CAPACITY_MAX ? ICO_NORMAL : ICO_OCCUPIED);

						printf("내림 %d %d\n", p->startF, p->endF);
						free(p);
					}
				}
			}

			door_close(&elevators[i]);

			elevators[i].state = checkState(elevators, floors);
		}
	}
}

int checkState(Elevator* elevators, Floor* floors) {
	int i, flag = 0;
	Passenger* p;

	if (wholeFloorEmpty(floors) == FALSE)
		return RUN;

	for (i = 0; i < ELEVATOR_NUM; i++) {
		if (LFirst(&elevators[i].pasList, &p) == TRUE)
			return RUN;
	}

	return STOP;
}