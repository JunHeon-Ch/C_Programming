#include <stdio.h>
#include <Windows.h>
#include "process_run.h"

/*���� �ö�*/
void upward(Elevator* elevator) {
	SetSortRule(&(elevator->pasList), up_WhoIsPrecede);
	(elevator->p.y)++;
	(elevator->now_f)++;
}

/*�Ʒ��� ������*/
void downward(Elevator* elevator) {
	SetSortRule(&(elevator->pasList), down_WhoIsPrecede);
	(elevator->p.y)--;
	(elevator->now_f)--;
}

/*����������*/
void rightward(Elevator* elevator) {
	(elevator->p.x)++;
}

/*��������*/
void leftward(Elevator* elevator) {
	(elevator->p.x)--;
}

/*���������� ����*/
void runElevator(Elevator* elevators) {
	int i;

	for (i = 0; i < ELEVATOR_NUM; i++) {
		elevators[i].state = RUN;

		if (elevators[i].now_f == 1) {
			if (elevators[i].p.x < 3) {
				if (elevators[i].p.x == 1)
					elevators[i].direction = RIGHT;
				rightward(&elevators[i]);
			}
			else if (elevators[i].p.x == 3) {
				elevators[i].direction = UP;
				upward(&elevators[i]);
			}
		}
		else if (elevators[i].now_f == FLOOR_NUM) {
			if (elevators[i].p.x > 1) {
				if (elevators[i].p.x == 3)
					elevators[i].direction = LEFT;
				leftward(&elevators[i]);
			}
			else if (elevators[i].p.x == 1) {
				elevators[i].direction = DOWN;
				downward(&elevators[i]);
			}
		}
		else {
			if (elevators[i].p.x == 1)
				downward(&elevators[i]);
			else if (elevators[i].p.x == 3)
				upward(&elevators[i]);
		}
	}
}

void printElevator(Elevator* elevators) {
	int i, j, k;
	int flag, mark;

	for (i = FLOOR_NUM; i >= 1; i--) {
		for (j = 1; j <= 3; j++) {
			flag = 0;
			for (k = 0; k < ELEVATOR_NUM; k++) {
				if (elevators[k].p.x == j && elevators[k].p.y == i) {
					flag = 1; mark = k;
				}
			}
			if (flag == 1)
				printf("%d ", mark);
			else
				printf("x ");
		}
		printf("\n");
	}
}

/*����*/
void stop(Elevator* elevators) {
	int i;

	for (i = 0; i < ELEVATOR_NUM; i++)
		elevators[i].state = STOP;

	Sleep(1000);
}

/*�����ִ��� �ƴ��� Ȯ��*/
int checkStop(Elevator* elevators) {
	int i, cnt = 0;

	for (i = 0; i < ELEVATOR_NUM; i++)
		if (elevators[i].state == STOP) {
			cnt++;
		}

	if (cnt == ELEVATOR_NUM)
		return TRUE;
	else
		return FALSE;
}

int checkRun(Elevator* elevators) {
	int i, flag = 0;

	for (i = 0; i < ELEVATOR_NUM; i++) {
		if (elevators[i].state == RUN)
			flag = 1;
	}

	if (flag == 1)
		return TRUE;
	else 
		return FALSE;
}