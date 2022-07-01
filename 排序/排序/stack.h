#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Stack
{
	int* a;
	int top;
	int capa;
}ST;


void StackInit(ST* ps);
void StackPush(ST* ps, int x);
int StackTop(ST* ps);
void StackPop(ST* ps);
void StackDestory(ST* ps);
int StackEmpty(ST* ps);
