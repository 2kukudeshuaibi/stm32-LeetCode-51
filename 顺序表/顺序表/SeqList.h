#pragma once

#include <stdio.h>
#include <string.h>

#define MAX 100
typedef int datetype;

typedef struct seqlist
{
	datetype* a;
	datetype size;
	datetype city;
}sl;

void seqlistinit(sl *a);
void seqlistprint(sl* a);
void seqlistcheck(sl* a);
void seqlistdestory(sl* a);
//ͷ�� β��
void seqlistPushBack(sl* a,datetype x);
void seqlistPushPront(sl* a, datetype x);
//ͷɾ βɾ
void seqlistdeleteback(sl* a);
void seqlistdeletePront(sl* a);


void seqlistinsert(sl*a,int pos,datetype x);
void seqlisterase(sl* a, int pos);


int seqlistfind(sl* a, datetype x);
void seqlistmod(sl* a, int pos, datetype x);



