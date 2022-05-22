#include "SeqList.h"

void seqlistinit(sl* a)
{
	memset(a->a, 0, sizeof(datetype) * MAX);
	a->size = 0;
}


//Í·²å Î²²å
void seqlistPushBack(sl* a, datetype x)
{
	if (x == MAX)
	{
		printf("ÂúÁË\n");
		return;
	}

	a->a[a->size] = x;
	a->size++;

}

void seqlistPushPront(sl* a, datetype x)
{

}
//Í·É¾ Î²É¾
void seqlistdeleteback(sl* a);
void seqlistdeletePront(sl* a);