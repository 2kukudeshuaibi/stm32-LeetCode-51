#include "SeqList.h"

void seqlistinit(sl* a)
{
	memset(a->a, 0, sizeof(datetype) * MAX);
	a->size = 0;
}


//ͷ�� β��
void seqlistPushBack(sl* a, datetype x)
{
	if (x == MAX)
	{
		printf("����\n");
		return;
	}

	a->a[a->size] = x;
	a->size++;

}

void seqlistPushPront(sl* a, datetype x)
{

}
//ͷɾ βɾ
void seqlistdeleteback(sl* a);
void seqlistdeletePront(sl* a);