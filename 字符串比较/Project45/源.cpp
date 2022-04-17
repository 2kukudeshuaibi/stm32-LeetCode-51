#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    char zh[5] = "0";
    char mm[5] = "0";
    int i = 0;
    while (scanf("%s", &zh) != EOF && scanf("%s", &mm) != EOF)
    {
        if (strcmp(zh, "admin") == 0 && strcmp(mm, "admin") == 0)
        {
            printf("Login Success!\n");
        }
        else
        {
            printf("Login Fail!\n");
        }

    }
    return 0;
}