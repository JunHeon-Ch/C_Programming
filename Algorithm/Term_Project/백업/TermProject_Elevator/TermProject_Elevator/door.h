#ifndef __DOOR_H__
#define __DOOR_H__

#include "elevator.h"

#define OPEN_TIME 100 // ������ �ð�
#define CLOSE_TIME 100 // ������ �ð�

void door_open(Elevator* elevator); // ����
void door_close(Elevator* elevator); // ����

#endif
