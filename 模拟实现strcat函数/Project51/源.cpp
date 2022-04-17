#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcat(char* str1, const char* str2)
{
    char* ret = str1;
    //1找目标字符串中的'\0'
    while (*str1 != '\0')
    {
        str1++;
    }
    //2追加源字符串
    strcpy(str1, str2);
    //3返回目标空间的起始地址
    return ret;
}
int main()
{
    char arr[20] = "Hello ";
    my_strcat(arr, arr);
    printf("%s", arr);
    return 0;
}