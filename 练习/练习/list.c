#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


void seqlisttest()//À≥–Ú±Ì≤‚ ‘
{
	sl s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);
}

void slisttest()
{
	slist* a = NULL;
	slistpushback(&a, 1);
	slistpushback(&a, 2);
	slistpushback(&a, 3);
	slistpushfront(&a,0);

	slistpushback(&a, 4);
	slistpushback(&a, 5);
	slistpushback(&a, 6);
	slistpushback(&a, 7);


	slist* pos=find(a,5);
	slistErase(&a,pos);
	slistprint(a);
}

void sttest()
{
	st p;
	StackInit(&p);
	StackPush(&p, 1);
	StackPush(&p, 2);
	StackPush(&p, 3);
	StackPush(&p, 4);
	StackPush(&p, 5);

	printf("%d ", StackTop(&p));
	StackPop(&p);
	printf("\n");


	printf("%d ", StackTop(&p));
}


void Queuetest()
{
	Queue tmp;
	QueueInit(&tmp);
	QueuePush(&tmp, 1);
	QueuePush(&tmp, 2);
	QueuePush(&tmp, 3);
	QueuePush(&tmp, 4);
	QueuePush(&tmp, 5);
	QueuePush(&tmp, 6);

	printqueue(&tmp);


	QueuePop(&tmp);

	printqueue(&tmp);

	printf("%d ", QueueBack(&tmp));

}

int main()
{
	//seqlisttest();//À≥–Ú±Ì≤‚ ‘
	//slisttest();//¡¥±Ì≤‚ ‘
	//sttest();//’ª≤‚ ‘
	//Queuetest();//∂”¡–≤‚ ‘
	return 0;
}