#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>



int main()
{
	//���ļ�
	FILE* pf = fopen("ttt.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//���ļ�
	int ret = fgetc(pf);
	printf("%c\n", ret);

	ret = fgetc(pf);
	printf("%c\n", ret);

	ret = fgetc(pf);
	printf("%c\n", ret);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}