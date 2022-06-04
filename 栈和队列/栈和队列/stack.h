#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct Stack
{
	int* a;
	int top;
	int capacity;
}typedef ST;

void Stackinit(ST* ps);
void StackDestory(ST* ps);


//»Î’ª
void Stackpush(ST* ps, int x);
//≥ˆ’ª
void Stackpop(ST* ps);

int Stacktop(ST* ps);
int Stackszie(ST* ps);
int StackEmpty(ST* ps);


