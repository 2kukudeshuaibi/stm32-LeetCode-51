#include "SeqList.h"


void Testseqlist()
{
	sl s;
	seqlistinit(&s);
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		seqlistPushBack(&s,i);
	}

	seqlistprint(&s);
	//seqlistdeletePront(&s);
	seqlistinsert(&s,10,5);
	seqlisterase(&s,0);
	seqlistprint(&s);
	seqlistdestory(&s);
}

int main()
{
	Testseqlist();
	return 0;
}