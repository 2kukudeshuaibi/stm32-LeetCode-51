#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
void reverse(char* left, char* right)
{

	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[100] = { 0 };
	gets_s(arr);
	int len = strlen(arr);
	reverse(arr, arr + len - 1);
	char* end = arr;
	char* play = arr;
	while (*play)
	{
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		reverse(play, end - 1);
		if (*end == ' ')
		{
			play = end + 1;
		}
		else
		{
			play = end;
		}
		end++;
	}
	printf("%s\n", arr);
	return 0;
}