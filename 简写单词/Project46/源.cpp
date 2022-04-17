#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int main()
{
    char arr[1000] = "0";
    scanf("%[^\n]", arr);
    int i = 0;
    int sz = strlen(arr);
    char* play = arr;
    char* end = arr;
    while (*play)
    {
        char a = toupper(*play);
        printf("%c", a);
        while (*end != ' ' && *end != '\0')
        {
            end++;
        }
        if (*end == ' ')
        {
            *play = *(end + 1);
        }
        else
        {
            *play = *end;
        }
        end++;
    }
    return 0;
}

