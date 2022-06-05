#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Queue
{
	struct Queue* next;
	int date;
}q;

typedef struct Q
{
	q* head;
	q* tail;
}queue;


void QueueInit(queue* pq);
void Queuedestory(queue* pq);

//队尾入
void Queuepush(queue* pq, int x);

//队头出
void Queuepop(queue* pq);

int Queuefront(queue* pq);
int Queueback(queue* pq);

int Queuesize(queue* pq);
int QueueEmpty(queue* pq);
void print(queue* pq);