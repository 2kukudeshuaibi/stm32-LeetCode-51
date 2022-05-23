#include "SeqList.h"
#include <stdlib.h>
void seqlistinit(sl* a)
{

	a->a = NULL;
	a->city = 0;
	a->size = 0;
	
}


//头插 尾插
void seqlistPushBack(sl* a, datetype x)
{
	
	seqlistcheck(a);
	a->a[a->size] = x;
	a->size++;
}


void seqlistcheck(sl* a)
{
	if (a->size == a->city)
	{
		int new = a->city == 0 ? 1 : a->city * 2;

		datetype* tmp = (datetype*)realloc(a->a, new * sizeof(datetype));
		if (tmp == NULL)
		{
			printf("失败\n");
			return;
		}
		else
		{
			a->a = tmp;
			a->city = new;
			printf("增加成功\n");
		}
	}
}
void seqlistPushPront(sl* a, datetype x)
{
	
	seqlistcheck(a);
	int end = a->size - 1;
	while (end >= 0)
	{
		a->a[end+1] = a->a[end];
		end--;
	}
	a->a[0] = x;
	a->size++;
}
//头删 尾删
void seqlistdeleteback(sl* a)
{
	if (a->size == 0)
	{
		printf("删完了\n");
		return;
	}
	a->size--;
}
void seqlistdeletePront(sl* a)
{
	int i = 0;
	if (a->size == 0)
	{
		printf("删完了\n");
		return;
	}
	for (i = 0; i < a->size-1; i++)
	{
		a->a[i] = a->a[i + 1];
	}
	a->size--;
}

void seqlistprint(sl* a)
{
	int i = 0;
	for (i = 0; i < a->size; i++)
	{
		printf("%d ", a->a[i]);
	}
	printf("\n");
}


void seqlistinsert(sl* a, int pos, datetype x)
{
	seqlistcheck(a);
	a->size++;
	int end = a->size - 1;
	while (end >= pos)
	{
		a->a[end + 1] = a->a[end];
		end--;
	}
	a->a[pos] = x;
}
void seqlisterase(sl* a, int pos)
{
	int end = pos;
	while (end < a->size)
	{
		a->a[end] = a->a[end + 1];
		end++;
	}
	a->size--;
}

void seqlistdestory(sl* a)
{
	free(a->a);
	a->a = NULL;
	a->size = 0;
	a->city = 0;
}

int seqlistfind(sl* a, datetype x)
{
	for (int i = 0; i < a->size; i++)
	{
		if (a->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void seqlistmod(sl* a, int pos, datetype x)
{
	a->a[pos] = x;
}