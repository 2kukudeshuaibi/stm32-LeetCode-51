#include "stack.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void StackInit(ST* ps)
{
	ps->a = (PT*)malloc(sizeof(PT) * 4);
	ps->top = 0;
	ps->capa = 4;
}
void StackPush(ST* ps, PT x)
{
	if (ps->top == ps->capa)
	{
		PT* new = (PT*)realloc(ps->a, sizeof(PT) * ps->capa * 2);
		ps->a = new;
		ps->capa *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
PT StackTop(ST* ps)
{
	return ps->a[ps->top - 1];
}
void StackPop(ST* ps)
{
	ps->top--;
}
void StackDestory(ST* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capa = 0;
}
int StackEmpty(ST* ps)
{
	return ps->top == 0;
}