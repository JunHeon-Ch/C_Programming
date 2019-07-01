#include <stdio.h>
#include "ExpressionTree.h"

void main() {
	char exp[] = "12+8*";
	BTNode* eTree = MakeExpTree(exp);
	
	ShowPrefixExp(eTree); printf("\n\n");
	ShowInfixExp(eTree); printf("\n\n");
	ShowPostfixExp(eTree); printf("\n\n");
	printf("%d\n", EvaluateExpTree(eTree));
}