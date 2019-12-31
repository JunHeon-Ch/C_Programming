#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__

#define TRUE 1
#define FALSE 0

#define FLOOR_NUM 6 // 층수
#define CAPACITY_MAX 100 // 엘리베이터 용량
#define ELEVATOR_NUM 3 // 엘리베이터 수

/*direction*/
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

/*state*/
#define RUN 1
#define STOP 2
#define OPEN 3
#define CLOSE 4

#include "iconid.h"
#include "linkedList.h"
#include "point.h"

typedef struct elevator {
	int elevator_id; // 엘리베이터 고유번호

	IconId icon_id; // GUI에 띄울 이미지

	int now_f; // 현재 층
	int now_w; // 현재 무게
	Point p; // 좌표
	int interval; // 앞 엘리베이터와 간격
	int state; // 운행 1 멈춤 2 열림3 닫힘 4
	int direction; // 올라감 1 내려감 2 오른 3 왼4
	int pasCnt; // 탑승 승객 수
	List pasList; // 도착 층에 따라 sorting 되어 있음
} Elevator;

int up_WhoIsPrecede(LData d1, LData d2); // 올라갈 때 sorting 방법
int down_WhoIsPrecede(LData d1, LData d2); // 내려갈 때 sorting 방법

void initInterval(Elevator* elevators); // 엘리베이터간 간격 초기화
void initElevator(Elevator* elevators); // 엘리베이터 정보 초기화

#endif // !__ELEVATOR_H__