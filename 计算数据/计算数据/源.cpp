#include <stdio.h>
#include <string.h>
#include <ctype.h>
int fun(char* p)
{
	int flag = 1;
	int i = 0;
	for (i = 0; i < strlen(p)-1; i++)
	{
		char tmp1 = tolower(p[i]);
		char tmp2 = tolower(p[i+1]);
		if ((tmp1+1) != (tmp2))
		{
			flag = 0;
			break;
		}
	}

	return flag;
}

int main()
{
	char arr[] = "ABCdef";
	int a = fun(arr);
	if (a == 1)
	{
		printf("是连续字符串\n");
	}
	else
	{
		printf("不是连续字符串\n");
	}


	

	return 0;
}