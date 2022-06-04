#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

int main()
{
	ST st;
	Stackinit(&st);
	Stackpush(&st, 1);
	Stackpush(&st, 2);
	Stackpush(&st, 3);
	Stackpush(&st, 4);
	Stackpush(&st, 5);


	while (!StackEmpty(&st))
	{
		printf("%d ", Stacktop(&st));
		Stackpop(&st);
	}
	printf("\n");
	StackDestory(&st);


	return 0;
}