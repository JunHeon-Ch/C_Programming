#include <stdio.h>
#include <math.h>
#include "process_seek.h"
#include "process_run.h"

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

int seek(Elevator* elevators, Passenger* psgr) {
	Point psgr_p;
	Point ele_p[3];
	int i, ele, estTime;

	psgr_p = psgr->p;
	for (i = 0; i < ELEVATOR_NUM; i++) {
		ele_p[i] = elevators[i].p;
	}

	ele = seek_elevator(elevators, psgr_p, ele_p, psgr->direction);
	estTime = extimateTime(elevators[ele], psgr);

	elevators[ele].state = RUN;
	printf("Seek %d\n", ele);

	return estTime;
}

int seek_elevator(Elevator* elevators, Point psgr_p, Point* ele_p, int up_down) {
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
					if (compAngle == 1 && min_p.x < ele_p[i].x) {
						if (checkStop(elevators) == TRUE) {
							min_p = ele_p[i];
							mini = i;
						}
						else {
							if (ele_p[i].x < psgr_p.x) {
								min_p = ele_p[i];
								mini = i;
							}
						}
					}
					else if (compAngle == 2 && min_p.y < ele_p[i].y) {
						min_p = ele_p[i];
						mini = i;
					}
				}
				else if(psgr_p.y > 1 && psgr_p.y < FLOOR_NUM) {
					if (compAngle == 0 && min_p.y < ele_p[i].y) {
						if (checkStop(elevators) == TRUE) {
							min_p = ele_p[i];
							mini = i;
						}
						else {
							if (ele_p[i].y < psgr_p.y) {
								min_p = ele_p[i];
								mini = i;
							}
						}
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
					if (compAngle == 1 && min_p.x > ele_p[i].x) {
						if (checkStop(elevators) == TRUE) {
							min_p = ele_p[i];
							mini = i;
						}
						else {
							if (ele_p[i].x > psgr_p.x) {
								min_p = ele_p[i];
								mini = i;
							}
						}
					}
					else if (compAngle == 2 && min_p.y < ele_p[i].y) {
						mini = i;
						min_p = ele_p[i];
					}
				}
				else if (psgr_p.y > 1 && psgr_p.y < FLOOR_NUM) {
					if (compAngle == 0 && min_p.y > ele_p[i].y) {
						if (checkStop(elevators) == TRUE) {
							min_p = ele_p[i];
							mini = i;
						}
						else {
							if (ele_p[i].y > psgr_p.y) {
								min_p = ele_p[i];
								mini = i;
							}
						}
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

int extimateTime(Elevator elevator, Passenger* psgr) {
	Point ele_p = elevator.p;
	Point start_p = psgr->p;
	Point end_p;
	
	int time = 0;

	end_p.x = start_p.x;
	end_p.y = psgr->endF;

	if (psgr->direction == UP) {
		if (elevator.direction == UP) {
			if (ele_p.y <= start_p.y) {
				time += start_p.y - ele_p.y;
			}
			else
				time += (FLOOR_NUM - ele_p.y) + (FLOOR_NUM - 1) + (start_p.y - 1) + 4;
		}
		else if (elevator.direction == LEFT) {
			time += (FLOOR_NUM - 1) + (start_p.y - 1) + (ele_p.x - 1) + 2;
		}
		else if (elevator.direction == DOWN) {
			time += (ele_p.y - 1) + 2 + (start_p.y - 1);
		}
		else if (elevator.direction == RIGHT) {
			time += (3 - ele_p.x) + (start_p.y - 1);
		}

		time += end_p.y - start_p.y;
	}

	else if (psgr->direction == DOWN) {
		printf("!!\n");
		if (elevator.direction == DOWN) {
			if (ele_p.y >= start_p.y) {
				time += ele_p.y - start_p.y;
			}
			else
				time += (ele_p.y - 1) + (FLOOR_NUM - 1) + (FLOOR_NUM - start_p.y) + 4;
		}
		else if (elevator.direction == RIGHT) {
			time += (FLOOR_NUM - 1) + (FLOOR_NUM - start_p.y) + (3 - ele_p.x) + 2;
		}
		else if (elevator.direction == UP) {
			time += (FLOOR_NUM - ele_p.y) + 2 + (FLOOR_NUM - start_p.y);
		}
		else if (elevator.direction == LEFT) {
			time += (ele_p.x - 1) + (FLOOR_NUM - start_p.y);
		}

		time += start_p.y - end_p.y;
	}

	return time * PER_TIME;
}