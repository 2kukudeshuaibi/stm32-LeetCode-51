#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct st
{
	struct st* next;
	struct st* prev;
	int date;
}typedef tt;


tt* listinit();
void listdestory(tt* phead);
void listprint(tt* phead);

void listpushback(tt* phead, int x);
void listpushfront(tt* phead, int x);

void listpopfront(tt* phead);
void listpopback(tt* phead);

tt* listfind(tt* phead, int x);

void listinsert(tt* pos, int x);
void listdele(tt* pos);