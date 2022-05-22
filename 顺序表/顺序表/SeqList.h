#pragma once

#include <stdio.h>
#include <string.h>

#define MAX 100
typedef int datetype;

typedef struct seqlist
{
	datetype a[MAX];
	datetype size;
}sl;

void seqlistinit(sl *a);

//Í·²å Î²²å
void seqlistPushBack(sl* a,datetype x);
void seqlistPushPront(sl* a, datetype x);
//Í·É¾ Î²É¾
void seqlistdeleteback(sl* a);
void seqlistdeletePront(sl* a);


