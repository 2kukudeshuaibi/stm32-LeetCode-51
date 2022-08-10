#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Position
{
	int row;
	int col;
}PT;

typedef struct Stack
{
	PT* a;
	int top;
	int capa;
}ST;


void StackInit(ST* ps);
void StackPush(ST* ps, PT x);
PT StackTop(ST* ps);
void StackPop(ST* ps);
void StackDestory(ST* ps);
int StackEmpty(ST* ps);

