#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include<string.h>
#include<ctype.h>
int main()
{
	int ch = 0;
	while (scanf("%c", &ch) != EOF)
	{
		if (isalpha(ch) > 0)
		{
			printf("%c is an alphabet\n", ch);
		}
		else
		{
			printf("%c is not an alphabet\n", ch);
		}
		getchar();
	}
	return 0;
}