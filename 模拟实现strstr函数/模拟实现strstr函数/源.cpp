#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
char* my_strstr(const char* str1, const char* str2)
{
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	const char* cp = str1;
	const char* s1 = NULL;
	const char* s2 = NULL;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1==*s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cp;
		}
		cp++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "abcde";
	char arr2[] = "bcd";
	char* ret = my_strstr(arr1, arr2);
	if (ret != NULL)
	{
		printf("找到了：%s\n", ret);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}