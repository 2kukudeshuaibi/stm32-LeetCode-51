#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void leftxuan(char arr[], int len, int k)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++)
	{
		//1.ÿ������һ���ַ�
		char tmp = arr[0];
		//2.�����n-1���ַ���ǰŲ��
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		//3.���������ַ������
		arr[len - 1] = tmp;
	}
}
int main()
{
	int k = 0;
	char arr[] = "ABCD";
	scanf("%d", &k);

	int sz = strlen(arr);

	leftxuan(arr, sz, k);
	printf("%s", arr);
	return 0;
}