#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void fun1(char** str)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		while (*str[i])
		{
			printf("%c", *str[i]);
			str[i]++;
		}
		printf("\n");
	}
}


void fun2(char*** arr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
}


char* fun3()
{
	static char arr[] = "abcdef";
	return arr;
}

int main()
{
	
	char* arr1[3] = { "era","bta","stc" };

	char* arr2[3] = { "abc","sda","egf" };
	char* arr3[3] = { "asd","rts","sfg" };

	char** brr[3] = { };
	

	char* p = fun3();
	printf("%s", p);
	return 0;
}