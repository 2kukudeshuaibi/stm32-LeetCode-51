#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"


int main()
{
	tt* a = NULL;
	pushback(&a, 1);
	pushback(&a, 2);
	pushback(&a, 3);
	pushback(&a, 4);
	pushback(&a, 5);
	pushback(&a, 6);


	print(a);
	
	tt* c = find(a, 1);
	if (c)
	{
		slisterase(&a,c);
	}
	c = find(a, 2);
	if (c)
	{
		slisterase(&a, c);
	}
	c = find(a, 3);
	if (c)
	{
		slisterase(&a, c);
	}
	c = find(a, 4);
	if (c)
	{
		slisterase(&a, c);
	}
	c = find(a, 5);
	if (c)
	{
		slisterase(&a, c);
	}
	c = find(a, 6);
	if (c)
	{
		slisterase(&a, c);
	}
	print(a);

	/*suijidelete(&a,1);
	print(a);

	cuihui(&a);
	print(a);*/


	return 0;
}