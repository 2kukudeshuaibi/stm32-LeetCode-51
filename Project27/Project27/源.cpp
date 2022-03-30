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
		if (isupper(ch))
		{
			printf("%c\n", tolower(ch));
		}
		else if (islower(ch))
		{
			printf("%c\n", toupper(ch));
		}
	}
	return 0;
}