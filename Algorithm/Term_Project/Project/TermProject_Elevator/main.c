#define HAVE_STRUCT_TIMESPEC

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <WinSock2.h>
#include <Windows.h>
#include "process_run.h"	
#include "process_seek.h"
#include "process_boarding.h"
#include <sys/types.h>

#pragma comment(lib,"ws2_32")

typedef struct multiArg {
	Elevator* elevators;
	Floor* floors;
	SOCKET socket;
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

	WSADATA wsaData;
	SOCKET eSocket;
	SOCKET cSocket;
	SOCKADDR_IN servAddr;
	SOCKADDR_IN cliAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		printf("WSAStartup() error!\n");

	eSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (eSocket == INVALID_SOCKET)
		printf("eSocketet() error!");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(10501);

	bind(eSocket, (struct sockaddr*) & servAddr, sizeof(servAddr));

	listen(eSocket, 10);

	puts("Waiting for a client...");

	int clilen = sizeof(cliAddr);
	cSocket = accept(eSocket, (struct sockaddr*) & cliAddr, &clilen);
	arg->socket = cSocket;

	for (int i = 0; i < ELEVATOR_NUM; i++)
	{
		command_elevator(cSocket, arg->elevators[i]);
	}
	thr_id = pthread_create(&thread, NULL, running, (void*)arg);

	if (thr_id != 0) {
		printf("thread create error\n");
		exit(-1);
	}

	int prevStart = 0, prevEnd = 0;
	int estDestT;
	while (1) {
		char buffer[120];
		int start, end;
		// receive src, dest from client
		recv(cSocket, buffer, 120, 0);
		start = buffer[0] - '0';
		end = buffer[3] - '0';

		if (start == -100)
		{
			exit(0);
		}

		if (start == prevStart && end == prevEnd) {
			continue;
		}

		printf("%d -> %d\n", start, end);

		p = makePassenger(start, end);

		if (p == NULL)
			continue;

		if (p->direction == UP) {
			waitingElevator(&(arg->floors[p->startF].upQ), p);
		}
		else if (p->direction == DOWN) {
			waitingElevator(&(arg->floors[p->startF].downQ), p);
		}

		estDestT = seek(arg->elevators, p);
		int min = estDestT / 60;
		int sec = estDestT % 60;

		printf("대기 %d층 (출발 %d 도착 %d)\n", p->startF, p->startF, p->endF);
		printf("도착 예정 시간: %d분 %d초\n", min, sec);

		command_time(cSocket, min, sec);

		for (j = 0; j < ELEVATOR_NUM; j++) {
			printf("elevate state\n");
			printf("%d\n", arg->elevators[j].state);
		}

		prevStart = start;
		prevEnd = end;

		Sleep(10);
	}

	closesocket(cSocket);
	closesocket(eSocket);
	WSACleanup();

	pthread_join(thread, (void**)&status);
	printf("Thread End %d\n", status);
}

void* running(void* a) {
	MultiArg* arg = (MultiArg*)a;

	while (1) {
		if (checkRun(arg->elevators) == TRUE) {
			getInElevator(arg->elevators, arg->floors, arg->socket);
			runElevator(arg->elevators, arg->socket);
			getOutElevator(arg->elevators, arg->floors, arg->socket);
			printElevator(arg->elevators);
			printFloor(arg->floors);
			printElePasList(arg->elevators);
			printf("===========================================\n");
		}

		Sleep(250);
	}
}

int switch_endian(int value)
{
	int result = 0;
}

/*
floor(queue) 업데이트
passenger 랜덤 할당
엘리베이터 운행
층마다 큐가 비어있는지 확인해서 안비어있으면 태움
엘리베이터(list) 업데이트
도착층 확인해서 내려줌
*/