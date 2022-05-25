#define _CRT_SECURE_NO_WARNINGS 1

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tt
{
	int a;
	struct tt* next;
}typedef tt;

void print(tt* phead);//打印
void pushback(tt** phead, int num);//尾插
void pushfront(tt** phead, int num);//头插
void deletefront(tt** phead);//头删
void deleteback(tt** phead);//尾删

void suijicharu(tt** phead, int x);
void suijidelete(tt** phead, int x);//随机删除
void cuihui(tt** phead);//销毁链表

tt* find(tt* phead, int x);

//在pos前面插入x
void slistinsert(tt** phead, tt* pos, int x);
//删除pos位置的值
void slisterase(tt** phead, tt* pos);



