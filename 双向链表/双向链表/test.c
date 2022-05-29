#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

void testlist1()
{
	tt* a = listinit();
	listpushfront(a,1);
	listpushfront(a, 2);
	listpushfront(a, 3);
	listpushfront(a, 4);
	listprint(a);
	listpopback(a);
	listprint(a);
	
}
void testlist2()
{
	tt* a = listinit();
	listpushback(a, 1);
	listpushback(a, 2);
	listpushback(a, 3);
	listpushback(a, 4);
	listprint(a);

	listdestory(a);
	listprint(a);

}

int main()
{
	//testlist1();
	testlist2();
	return 0;
}