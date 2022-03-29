#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include<assert.h>
#include<stdio.h>
int main()
{
    double x = 0.0;
    char ch = 0;
    double y = 0.0;
    scanf("%lf", &x);
    scanf("%c", &ch);
    scanf("%lf", &y);
    char ah[] = { '+','-','*','/' };
    if (ch != ah[0] && ch != ah[1] && ch != ah[2] && ch != ah[3])
    {
        printf("Invalid operation!\n");
    }
    if (ch == ah[0])
    {
        printf("%.4lf%c%.4lf=%.4lf", x, ah[0], y, x + y);
    }
    if (ch == ah[1])
    {
        printf("%.4lf%c%.4lf=%.4lf", x, ah[1], y, x - y);
    }
    if (ch == ah[2])
    {
        printf("%.4lf%c%.4lf=%.4lf", x, ah[2], y, x * y);
    }
    if (ch == ah[3])
    {
        if (y > 0.0)
        {
            printf("%.4lf%c%.4lf=%.4lf", x, ah[3], y, x / y);
        }
        else
        {
            printf("Wrong!Division by zero!\n");
        }
    }
    return 0;
}