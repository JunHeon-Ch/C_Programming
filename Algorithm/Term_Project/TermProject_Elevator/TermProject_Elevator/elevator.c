#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"

int up_WhoIsPrecede(LData d1, LData d2) {
	if (d1->endF > d2->endF)
		return 0;
	else
		return 1;
}

int down_WhoIsPrecede(LData d1, LData d2) {
	if (d1->endF < d2->endF)
		return 0;
	else
		return 1;
}

/*엘리베이터 간격 초기화*/
void initInterval(Elevator* elevators) {
	int n = FLOOR_NUM * 2 - 1;

	switch (n % ELEVATOR_NUM) {
	case 0:
		elevators[0].interval = elevators[1].interval = elevators[2].interval = n / ELEVATOR_NUM;
		break;
	case 1:
		elevators[0].interval = elevators[2].interval = n / ELEVATOR_NUM + 1;
		elevators[1].interval = n / ELEVATOR_NUM;
		break;
	case 2:
		elevators[0].interval = n / ELEVATOR_NUM + 1;
		elevators[1].interval = elevators[2].interval = n / ELEVATOR_NUM;
	}
}

/*엘리베이터 초기화*/
void initElevator(Elevator* elevators) {
	int i;
	
	for (i = 0; i < ELEVATOR_NUM; i++) {
		switch (i) {
		case 0:
			elevators[i].now_f = 1;
			elevators[i].p.x = 3;
			elevators[i].direction = UP;
			break;
		case 1:
			elevators[i].now_f = FLOOR_NUM;
			elevators[i].p.x = 3;
			elevators[i].direction = LEFT;
			break;
		case 2:
			elevators[i].now_f = FLOOR_NUM / 2 + 1;
			elevators[i].p.x = 1;
			elevators[i].direction = DOWN;
			break;
		}
		elevators[i].now_w = elevators[i].pasCnt = 0;
		elevators[i].state = STOP;
		elevators[i].p.y = elevators[i].now_f;

		ListInit(&elevators[i].pasList);
		if (elevators[i].direction == UP)
			SetSortRule(&elevators[i].pasList, up_WhoIsPrecede);
		else if(elevators[i].direction == DOWN)
			SetSortRule(&elevators[i].pasList, down_WhoIsPrecede);
	}

	initInterval(elevators);
}