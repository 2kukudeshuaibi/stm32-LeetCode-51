#include <stdio.h>



float fun(float h)
{
	 return (int)((h * 100)+0.5)/100.0;
}

int main()
{
	float a = 1234.567;
	printf("%f", fun(a));
	return 0;
}