#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>


typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	char date;
}BT;



typedef BT* Qdate;

typedef struct Queue
{
	struct Queue* next;
	Qdate date;
}q;


typedef struct Q
{
	q* head;
	q* tail;
}queue;


void QueueInit(queue* pq);
void Queuedestory(queue* pq);
void Queuepush(queue* pq,Qdate x);
void Queuepop(queue* pq);
Qdate Queuefront(queue* pq);
Qdate Queueback(queue* pq);

int Queuesize(queue* pq);
int QueueEmpty(queue* pq);
