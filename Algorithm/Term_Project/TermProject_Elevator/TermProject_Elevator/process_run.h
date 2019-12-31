#ifndef __PROCESS_RUN_H__
#define __PROCESS_RUN_H__

#include "elevator.h"

/*
엘리베이터 간격 유지하면서 시계반대방향으로 돌아감
*/

void upward(Elevator* elevator); // 올라감
void downward(Elevator* elevator); // 내려감
void rightward(Elevator* elevator); // 오른
void leftward(Elevator* elevator); // 왼

void stop(Elevator* elevators); // 멈춤
int checkStop(Elevator* elevators); // 멈춰있는지 확인
int checkRun(Elevator* elevators); // 엘베가 돌아가야하는지

void runElevator(Elevator* elevators); // 엘베 운행
void printElevator(Elevator* elevators);

#endif
