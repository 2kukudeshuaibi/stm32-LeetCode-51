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
	while (cur)
	{
		q* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = NULL;
	pq->tail = NULL;
}
void Queuepush(queue* pq, Qdate x)
{
	assert(pq);
	q* new = (q*)malloc(sizeof(q));
	new->next = NULL;
	new->date = x;
	if (pq->head == NULL)
	{
		pq->head = new;
		pq->tail = new;
	}
	else
	{
		pq->tail->next = new;
		pq->tail = new;
	}
}
void Queuepop(queue* pq)
{
	assert(pq);
	assert(pq->head);
	q* prev = pq->head;
	pq->head = pq->head->next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
	free(prev);
	prev = NULL;
}
Qdate Queuefront(queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->date;
}
Qdate Queueback(queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->tail->date;
}

int Queuesize(queue* pq)
{
	assert(pq);
	int size = 0;
	q* cur = pq->head;
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
