#include <stdio.h>
#include <math.h>
#include "process_seek.h"

float up_computingAngle(Point p1, Point p2) {
	float dx, dy;
	float angle;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	if (dx == 0 && dy <= 0)
		angle = 0;
	else {
		angle = (float)abs(dy) / (abs(dx) + abs(dy));
		if (dx < 0 && dy <= 0)
			angle = 1 - angle;
		else if (dx <= 0 && dy > 0)
			angle = 1 + angle;
		else if (dx > 0 && dy >= 0)
			angle = 3 - angle;
		else if (dx > 0 && dy < 0)
			angle = 3 + angle;
	}

	return angle;
}

float down_computingAngle(Point p1, Point p2) {
	float dx, dy;
	float angle;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	if (dx == 0 && dy >= 0)
		angle = 0;
	else {
		angle = (float)abs(dy) / (abs(dx) + abs(dy));
		if (dx > 0 && dy >= 0)
			angle = 1 - angle;
		else if (dx >= 0 && dy < 0)
			angle = 1 + angle;
		else if (dx < 0 && dy <= 0)
			angle = 3 - angle;
		else if (dx < 0 && dy > 0)
			angle = 3 + angle;
	}

	return angle;
}

void seek(Elevator* elevators, Passenger* psgr) {
	Point psgr_p;
	Point ele_p[3];
	int i, ele;

	psgr_p = psgr->p;
	for (i = 0; i < ELEVATOR_NUM; i++) {
		ele_p[i] = elevators[i].p;
	}

	ele = seek_elevator(psgr_p, ele_p, psgr->direction);
	elevators[ele].state = RUN;
}

int seek_elevator(Point psgr_p, Point* ele_p, int up_down) {
	int i, mini;
	float minAngle = 4, compAngle;
	Point min_p;

	if (up_down == UP) {
		for (i = 0; i < ELEVATOR_NUM; i++) {
			compAngle = up_computingAngle(psgr_p, ele_p[i]);
			if (minAngle > compAngle) {
				minAngle = compAngle;
				mini = i;
				min_p = ele_p[i];
			}
			else if (minAngle == compAngle) {
				if (psgr_p.y == 1) {
					if (compAngle == 1 && min_p.x < ele_p[i].x && ele_p[i].x < psgr_p.x) {
						min_p = ele_p[i];
						mini = i;
					}
					else if (compAngle == 2 && min_p.y < ele_p[i].y) {
						min_p = ele_p[i];
						mini = i;
					}
				}
				else if(psgr_p.y > 1 && psgr_p.y < FLOOR_NUM) {
					if (compAngle == 0 && min_p.y < ele_p[i].y && ele_p[i].y < psgr_p.y) {
						min_p = ele_p[i];
						mini = i;
					}
					else if (compAngle == 2 && min_p.y < ele_p[i].y) {
						min_p = ele_p[i];
						mini = i;
					}
				}
			}
		}
	}

	else if (up_down == DOWN) {
		for (i = 0; i < ELEVATOR_NUM; i++) {
			compAngle = down_computingAngle(psgr_p, ele_p[i]);
			if (minAngle > compAngle) {
				minAngle = compAngle;
				mini = i;
				min_p = ele_p[i];
			}
			else if (minAngle == compAngle) {
				if (psgr_p.y == FLOOR_NUM) {
					if (compAngle == 1 && min_p.x > ele_p[i].x && ele_p[i].x != psgr_p.x) {
						mini = i;
						min_p = ele_p[i];
					}
					else if (compAngle == 2 && min_p.y < ele_p[i].y) {
						mini = i;
						min_p = ele_p[i];
					}
				}
				else if (psgr_p.y > 1 && psgr_p.y < FLOOR_NUM) {
					if (compAngle == 0 && min_p.y > ele_p[i].y && ele_p[i].y != psgr_p.y) {
						mini = i;
						min_p = ele_p[i];
					}
					else if (compAngle == 2 && min_p.y > ele_p[i].y) {
						mini = i;
						min_p = ele_p[i];
					}
				}
			}
		}
	}

	return mini;
}