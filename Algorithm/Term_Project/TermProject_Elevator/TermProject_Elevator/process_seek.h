#ifndef __PROCESS_SEEK_H__
#define __PROCESS_SEEK_H__

#include "elevator.h"
#include "passenger.h"

/* 
탑승자 위치 기준 각도 사용해서 먼저 올 엘리베이터 찾음 (Jarvis)
시간 체크
*/

float up_computingAngle(Point p1, Point p2); // 올라갈 때 각도
float down_computingAngle(Point p1, Point p2); // 내려갈 때 각도

void seek(Elevator* elevators, Passenger* psgr); 
int seek_elevator(Point psgr_p, Point* ele_p, int up_down); // 먼저 오는 엘리베이터 찾기

#endif