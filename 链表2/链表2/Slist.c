#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"


//tt a = { 10,NULL };
void print(tt* phead)
{
	tt* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->a);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}
void pushback(tt** phead, int num)
{
	tt* pn = (tt*)malloc(sizeof(tt));
	pn->a = num;
	pn->next = NULL;
	if (*phead == NULL)
	{
		*phead = pn;
	}
	else
	{
		tt* tail = *phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = pn;
	}

}
void pushfront(tt** phead, int num)
{
	tt* pn = (tt*)malloc(sizeof(tt));
	pn->a = num;
	pn->next = NULL;

	tt* list = *phead;
	*phead = pn;
	(*phead)->next = list;
}

void deletefront(tt** phead)
{
	tt* list = *phead;
	*phead = (*phead)->next;
	free(list);
	list = NULL;
}

void deleteback(tt** phead)
{
	tt* list = *phead;
	tt* tail = NULL;
	if (*phead == NULL)
	{
		return;
	}
	else if (list->next==NULL)
	{
		*phead = NULL;
		free(list);
	}
	else
	{
		while (list->next != NULL)
		{
			tail = list;
			list = list->next;
		}
		tail->next = NULL;
		free(list);
		list = NULL;
	}
}


void suijidelete(tt** phead, int x)
{
	tt* cur = *phead;
	tt* prev = NULL;
	while (cur != NULL)
	{
		if (cur->a == x)
		{
			tt* pd = cur;
			if (cur == *phead)
			{
				*phead = (*phead)->next;
				cur = *phead;
			}
			else
			{
				prev->next = cur->next;
				cur = cur->next;
			}
			free(pd);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void cuihui(tt** phead)
{
	tt* cur = *phead;
	tt* pd = NULL;
	while (cur != NULL)
	{
		pd = cur;
		cur = cur->next;
		free(pd);
	}
	*phead = NULL;
}


tt* find(tt* phead, int x)
{
	tt* list = phead;
	while (list != NULL)
	{
		if (list->a == x)
		{
			return list;
		}
		else
		{
			list = list->next;
		}
	}
	return NULL;
}

//在pos前面插入x
void slistinsert(tt** phead, tt* pos, int x)
{
	tt* pd = (tt*)malloc(sizeof(tt));
	pd->a = x;
	pd->next = NULL;

	tt* list = *phead;
	tt* prev = NULL;
	while (list)
	{

		if (list->a == pos->a)
		{
			
			if (list == *phead)
			{
				*phead = pd;
				(*phead)->next = list;
				break;
			}
			else
			{
				prev->next = pd;
				pd->next = list;
				break;
			}
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}

}
//删除pos位置的值
void slisterase(tt** phead, tt* pos)
{
	tt* list = *phead;
	tt* prev = NULL;
	while (list)
	{
		if (list == pos)
		{
			//tt* pn = list;
			if (list==*phead)
			{
				*phead = (*phead)->next;
				free(list);
				list = NULL;
				break;
			}
			else
			{
				prev->next = list->next;
				free(list);
				list = NULL;
				break;
			}
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}
}

