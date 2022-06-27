#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/*
顺序表
功能：头插 尾插
	  头删 尾删
	  打印 销毁
	  随机插入 随机删除
*/
typedef int SLDataType;
typedef struct seqlist
{
	SLDataType* arr;
	int size;
	int capa;
}sl;
void SeqListInit(sl* psl);//初始化
void SeqListDestory(sl* psl);//销毁
void SeqListPrint(sl* psl);//打印
void Check(sl* psl);//检查空间
void SeqListPushBack(sl* psl, SLDataType x);//尾插
void SeqListPopback(sl* psl, SLDataType x);//尾删
void SeqListPushFront(sl* psl, SLDataType x);//头插
void SeqListPopFront(sl* psl, SLDataType x);//头删
int SeqListFind(sl* psl, SLDataType x);//查找
void SeqListInsert(sl* psl, int pos, SLDataType x);//在pos位置插入
void SeqListErase(sl* psl, int pos);//删除pos位置




/*
链表
功能：头插 尾插
	  头删 尾删
	  打印 销毁
	  随机插入 随机删除
*/
typedef int SList;
typedef struct slist
{
	struct slist* next;
	SList val;
}slist;

void slistprint(slist* head);//打印
void slistpushback(slist** head, SList x);//尾插
void slistpushfront(slist** head, SList x);//头插
void slistpopback(slist** head);//尾删
void slistpopfront(slist** head);//头删
slist* find(slist* head, SList x);//查找
void slistInsert(slist** head, slist* pos, SList x);//pos前插入x
void slistErase(slist** head, slist* pos);


/*
双向链表
功能：头插 尾插
	  头删 尾删
	  打印 销毁
	  随机插入 随机删除
*/
typedef int list;
typedef struct sxlist
{
	struct sxlist* next;
	struct sxlist* prev;
	list val;
}sxlist;
sxlist* listinit();
void listdestory(sxlist* phead);
void listprint(sxlist* phead);
void listpushback(sxlist* phead, list date);
void listpushfront(sxlist* phead, list date);
void listpopback(sxlist* phead);
void listpopfront(sxlist* phead);
sxlist* listfind(sxlist* phead, list date);
void listinsert(sxlist* pos, list date);
void listErase(sxlist* pos);



/*
栈
功能：入栈 出栈
      取栈顶元素 获取元素个数
	  判空
*/

typedef int STdate;
struct stack
{
	STdate* a;
	int top;
	int capacity;
}typedef st;


void StackInit(st* ps);
void StackPush(st* ps, STdate date);
void StackPop(st* ps);
STdate StackTop(st* ps);
int StackSize(st* ps);
int StackEmpty(st* ps);
void StackDestory(st* ps);

/*
队列
功能：入队 出队
	  判空
*/

typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* Next;
	QDataType date;
}QNode;
// 队列的结构
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;
// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
