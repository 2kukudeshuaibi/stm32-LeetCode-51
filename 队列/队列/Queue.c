#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"


void QueueInit(queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
}

void Queuedestory(queue* pq)
{
	assert(pq);
	q* cur = pq->head;
	while (pq->head)
	{
		q* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void Queuepush(queue* pq, int x)
{
	assert(pq);
	q* new = (q*)malloc(sizeof(q));
	if (new == NULL)
	{
		printf("malloc fail\n");
		return;
	}
	new->date = x;
	new->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = new;
		pq->tail = new;
	}
	else
	{
		pq->tail->next = new;
		pq->tail = pq->tail->next;
	}
}

void Queuepop(queue* pq)
{
	assert(pq);
	assert(pq->head);

	q* cur = pq->head;
	pq->head = pq->head->next;
	if (pq->head == NULL)
	{
		pq->tail = pq->head;
	}
	free(cur);
	cur = NULL;
}
void print(queue* pq)
{
	q* cur = pq->head;
	while (cur)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
int Queuefront(queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->date;
}
int Queueback(queue* pq)
{
	assert(pq);
	assert(pq->head);
	assert(pq->tail);

	return pq->tail->date;
}
int Queuesize(queue* pq)
{
	q* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
int QueueEmpty(queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}