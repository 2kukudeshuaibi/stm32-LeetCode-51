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
    cin >> num;//����ѧ������
    while (num)//whileѭ������ÿ��ѧ����ƽ���ɼ�
    {
        int a, b, c;
        cin >> a >> b >> c;//�������Ƴɼ�
        double avg = (a + b + c) / 3;//��ƽ���ɼ�
        if (avg < 60)
            sum++;//���С��60��sum��1����ʾ��Ҫ����ҳ�������
        num--;
    }
    cout << sum << endl;
    return 0;
}