#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void my_strcpy(char* arr1, char* arr2)
{
	while (*(arr1++) = *(arr2++))
	{
		;
	}
	
	
}
int main()
{
	char arr1[20] = "*****************";
	char arr2[] = "hello";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}