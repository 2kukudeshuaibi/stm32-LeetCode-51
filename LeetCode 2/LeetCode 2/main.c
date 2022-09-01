#include <stdio.h>
#include <string.h>



int next_n(int n)
{
	int r = 0;
	while (n)
	{
		int d = n % 10;
		n /= 10;
		r = r + d * d;
	}
	return r;
}

int isHappy(int n)
{
	int slow = n;
	int fast = n;
	do
	{
		slow = next_n(slow);
		fast = next_n(next_n(fast));
	} while (slow != fast);

	return fast == 1;
}


int main()
{
	int a = isHappy(567);
	if (a)
	{
		printf("是快乐数字\n");
	}
	else
	{
		printf("不是快乐数字\n");
	}
	return 0;
}