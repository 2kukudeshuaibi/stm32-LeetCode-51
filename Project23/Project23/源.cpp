#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include<assert.h>
int my_strlen(const char* arr)
{
	assert(*arr != NULL);
	int count = 0;
	while (*(arr++) != '\0')
	{
		count++;
	}
	return count;
}
int main()
{
	const char arr[] = "abcdadas";
	const int ret = my_strlen(arr);
	printf("%d", ret);
	return 0;
}