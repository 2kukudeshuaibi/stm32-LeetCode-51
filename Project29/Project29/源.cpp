#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int sum = 0;
    int num;
    cin >> num;//输入学生人数
    while (num)//while循环计算每个学生的平均成绩
    {
        int a, b, c;
        cin >> a >> b >> c;//输入三科成绩
        double avg = (a + b + c) / 3;//求平均成绩
        if (avg < 60)
            sum++;//如果小于60则sum加1，表示需要被请家长的人数
        num--;
    }
    cout << sum << endl;
    return 0;
}