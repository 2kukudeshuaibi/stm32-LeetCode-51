#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define BIT(X) ((X&0xaaaaaaaa)>>1)+((X&0x55555555)<<1)

int main()
{
	int num = 10;
	int ret = BIT(num);
	printf("%d ", ret);
	return 0;
}