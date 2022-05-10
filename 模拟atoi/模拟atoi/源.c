#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

enum STate
{
	INVALID,
	VALID
};

enum STate state = INVALID;

int my_atoi(const char* p)
{
	int flag = 0;

	if (NULL == *p)
	{
		return 0;
	}
	if (*p == '\0')
	{
		return 0;
	}
	while (isspace(*p))
	{
		p++;
	}
	if (*p == '-')
	{
		flag = -1;
		p++;
	}
	else if (*p == '+')
	{
		flag = 1;
		p++;
	}
	long long sum = 0;
	while (isdigit(*p))
	{
		sum = sum * 10 + flag * (*p - '0');

		if (sum > INT_MAX || sum < INT_MIN)
		{
			return 0;
		}
		p++;
	}
	if (*p == '\0')
	{
		state = VALID;
		return (int)sum;
	}
	else
	{
		return (int)sum;
	}

}

int main()
{
	char* p = "  saa  12";
	int ret = my_atoi(p);
	if (state == VALID)
	{
		printf("正常转换：%d", ret);
	}
	else
	{
		printf("非法转换：%d", ret);
	}
	return 0;
}