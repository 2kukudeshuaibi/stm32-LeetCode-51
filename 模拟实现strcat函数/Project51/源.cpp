#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcat(char* str1, const char* str2)
{
    char* ret = str1;
    //1��Ŀ���ַ����е�'\0'
    while (*str1 != '\0')
    {
        str1++;
    }
    //2׷��Դ�ַ���
    strcpy(str1, str2);
    //3����Ŀ��ռ����ʼ��ַ
    return ret;
}
int main()
{
    char arr[20] = "Hello ";
    my_strcat(arr, arr);
    printf("%s", arr);
    return 0;
}