#include <stdio.h>
int add(int x, int y)
{
	return x + y;
}
int calc(int (*pa)(int, int))
{
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
	return pa(x, y);
}
int main()
{
	int ret = calc(add);
	printf("%d", ret);
	return 0;
}