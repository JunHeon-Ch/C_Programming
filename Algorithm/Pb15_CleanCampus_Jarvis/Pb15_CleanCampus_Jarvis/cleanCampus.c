#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

#define TRUE 1
#define FALSE 0

typedef struct point {
	float x, y;
	int check;
}Point;

typedef struct stack {
	int pIdx[100];
	int top;
}Stack;

void jarvis(Point* p, Stack* stack, int pNum);
float computingAngle(Point p1, Point p2);
float calculateSilk(Stack* stack, Point* p);
float calculatePtoP(Point p1, Point p2);
void stackInit(Stack* stack);
void push(Stack* stack, int p);
int pop(Stack* stack);
int isEmpty(Stack* stack);

void main() {
	FILE* fp;

	int n, pNum;
	int i;
	Point* p;
	Stack stack;
	float lenSilk;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		printf("Error: file is not founded\n");

	fscanf(fp, "%d", &n);

	while (n > 0) {
		fscanf(fp, "%d", &pNum);

		p = (Point*)malloc(sizeof(Point));
		stackInit(&stack);
		
		p[0].x = p[0].y = p[0].check = 0;
		for (i = 1; i <= pNum; i++) {
			fscanf(fp, "%f %f", &p[i].x, &p[i].y);
			p[i].check = 0;
		}

		jarvis(p, &stack, i);
		lenSilk = calculateSilk(&stack, p) + 2;

		printf("Length of slik: %.2f\n", lenSilk);	

		n--;
	}

	fclose(fp);

	Sleep(1000);
}

void stackInit(Stack* stack) {
	stack->top = -1;
}

int isEmpty(Stack* stack) {
	if (stack->top == -1)
		return TRUE;
	else
		return FALSE;
}

void push(Stack* stack, int pIdx) {
	stack->pIdx[++(stack->top)] = pIdx;
}

int pop(Stack* stack) {
	if (isEmpty(stack) == TRUE)
		exit(-1);

	return stack->pIdx[(stack->top)--];
}

float computingAngle(Point p1, Point p2) {
	float dx, dy;
	float angle;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	if (dx == 0 && dy <= 0)
		angle = 0;
	else {
		angle = (float)abs(dy) / (abs(dx) + abs(dy));
		if (dx > 0 && dy <= 0)
			angle = 1 - angle;
		else if (dx >= 0 && dy > 0)
			angle = 1 + angle;
		else if (dx < 0 && dy >= 0)
			angle = 3 - angle;
		else if (dx < 0 && dy < 0)
			angle = 3 + angle;
	}

	return angle;
}

void jarvis(Point* p, Stack* stack, int pNum) {
	int i;
	int spIdx, dpIdx;
	float minAngle, cAngle;

	spIdx = 0;
	dpIdx = spIdx;
	while (TRUE) {
		push(stack, dpIdx);
		p[dpIdx].check = 1;

		spIdx = dpIdx;
		minAngle = 4;

		for (i = 0; i < pNum; i++) {
			if (spIdx == i || p[i].check == 1)
				continue;

			cAngle = computingAngle(p[spIdx], p[i]);
			if (cAngle < minAngle) {
				minAngle = cAngle;
				dpIdx = i;
			}
		}

		if (p[dpIdx].check == 1)
			break;
	}
	push(stack, 0);
}

float calculateSilk(Stack* stack, Point* p) {
	float lenSilk = 0;
	int idx1, idx2;
	
	while (1) {
		idx1 = pop(stack);
		idx2 = pop(stack);

		lenSilk += calculatePtoP(p[idx1], p[idx2]);
		
		if (isEmpty(stack))
			break;

		push(stack, idx2);
	}

	return lenSilk;
}

float calculatePtoP(Point p1, Point p2) {
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}