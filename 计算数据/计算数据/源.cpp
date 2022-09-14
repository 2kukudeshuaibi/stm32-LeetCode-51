#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int fun(int n)
{
	static int tmp = 0;
	tmp = tmp + n % 10;
	
	if (n > 9)
	{
		tmp *= 10;
		fun(n / 10);
	}
	return tmp;
}



int main()
{
	printf("%d", fun(1234));
	return 0;
}