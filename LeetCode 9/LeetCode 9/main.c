#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	char* data;
	int size;
	int capa;
}stack;


void stackInit(stack* ps)
{
	ps->data = (char*)malloc(sizeof(char) * 4);
	ps->size = -1;
	ps->capa = 4;
}

void stackPush(stack* ps, char a)
{
	if (ps->size == ps->capa)
	{
		ps->data = (char*)realloc(ps->data, sizeof(char) * 2 * ps->capa);
		ps->capa *= 2;
	}
	ps->size++;
	ps->data[ps->size] = a;
	
}


void stackPrint(stack* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%c", ps->data[i]);
	}
	printf("\n");
}

void stackPop(stack* ps)
{
	if (ps->size == -1)
		return;
	ps->size--;
}

char stackTop(stack* ps)
{
	return ps->data[ps->size];
}


int backspaceCompare(char* s, char* t)
{
	stack ss;
	stack tt;
	stackInit(&ss);
	stackInit(&tt);
	int flag = 1;
	while (*s)
	{
		if (*s != '#')
		{
			stackPush(&ss, *s);
			s++;
		}
		if (*s == '#')
		{
			stackPop(&ss);
			s++;
		}
	}

	while (*t)
	{
		if (*t != '#')
		{
			stackPush(&tt, *t);
			t++;
		}
		if (*t == '#')
		{
			stackPop(&tt);
			t++;
		}
	}

	if (ss.size == tt.size)
	{
		int i = 0;
		for (i = 0; i <= ss.size; i++)
		{
			if (ss.data[i] != tt.data[i])
			{
				flag = 0;
				break;
			}
		}

	}
	else
	{
		flag = 0;
	}

	
	return flag;
}

int main()
{
	char arr1[] = "a##c";
	char arr2[] = "#a#c";
	int a = backspaceCompare(arr1, arr2);
	if (a)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	
	return 0;
}