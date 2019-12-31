#define HAVE_STRUCT_TIMESPEC

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "process_run.h"	
#include "process_seek.h"
#include "process_boarding.h"

typedef struct multiArg {
	Elevator* elevators;
	Floor* floors;
}MultiArg;

void* running(void* a);

void main() {
	MultiArg* arg = (MultiArg*)malloc(sizeof(MultiArg));
	pthread_t thread;
	Passenger* p;
	int thr_id, status;
	int i, j;

	srand(time(NULL));

	arg->elevators = (Elevator*)malloc(sizeof(Elevator) * ELEVATOR_NUM);
	arg->floors = (Floor*)malloc(sizeof(Floor) * (FLOOR_NUM + 1));

	initElevator(arg->elevators);
	floorInit(arg->floors);
	
	thr_id = pthread_create(&thread, NULL, running, (void*)arg);
	
	if (thr_id != 0) {
		printf("thread create error\n");
		exit(-1);
	}

	i = 0;
	while (i < 10) {	
		p = makePassenger();
		
		if (p == NULL)
			continue;

		if (p->direction == UP) {
			waitingElevator(&arg->floors[p->startF].upQ, p);
		}
		else if (p->direction == DOWN) {
			waitingElevator(&arg->floors[p->startF].downQ, p);
		}

		seek(arg->elevators, p);

		
		printf("\n\n");

		printf("��� %d�� (��� %d ���� %d)\n", p->startF, p->startF, p->endF);
		
		for (j = 0; j < ELEVATOR_NUM; j++) {
			printf("elevate state\n");
			printf("%d\n", arg->elevators[i].state);
		}

		Sleep(2000);
		
		i++;
	}

	pthread_join(thread, (void **)&status);
}

void* running(void* a) {
	MultiArg* arg = (MultiArg*)a;
	int i;

	i = 0;
	while (i<30) {
		printf("%d\n", checkRun(arg->elevators));

		if (checkRun(arg->elevators) == TRUE) {
			getInElevator(arg->elevators, arg->floors);
			getOutElevator(arg->elevators);
			runElevator(arg->elevators);
			printElevator(arg->elevators);
			printFloor(arg->floors);
			printf("===========================================\n");
		}
		i++;
	}	
}

/*
floor(queue) ������Ʈ
passenger ���� �Ҵ�
���������� ����
������ ť�� ����ִ��� Ȯ���ؼ� �Ⱥ�������� �¿�
����������(list) ������Ʈ
������ Ȯ���ؼ� ������
*/
