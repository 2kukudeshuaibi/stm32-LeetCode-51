#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>



int main()
{
	//打开文件
	FILE* pf = fopen("ttt.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//读文件
	int ret = fgetc(pf);
	printf("%c\n", ret);

	ret = fgetc(pf);
	printf("%c\n", ret);

	ret = fgetc(pf);
	printf("%c\n", ret);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}