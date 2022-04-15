#include <reg51.h>

sbit lsa = P2 ^ 2;
sbit lsb = P2 ^ 3;
sbit lsc = P2 ^ 4;

unsigned char arr[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f };
int key = 0;
unsigned char tmp = 0;
void delay(unsigned int i);//延时函数
int key_sm();//键盘扫描函数

void main()
{
    lsc = 1; lsb = 1; lsa = 1;
    while (1)
    {
        key = key_sm();
        if (key != 0)
        {
            switch (key)
            {
            case 1:P0 = arr[1]; break;
            case 2:P0 = arr[2]; break;
            case 3:P0 = arr[3]; break;
            case 4:P0 = arr[4]; break;
            case 5:P0 = arr[5]; break;
            case 6:P0 = arr[6]; break;
            case 7:P0 = arr[7]; break;
            case 8:P0 = arr[8]; break;
            case 9:P0 = arr[9]; break;
            default:break;
            }
        }
    }
}

void delay(unsigned int i)
{
    unsigned int k;
    for (k = 0; k < i; k++);
}

int key_sm()
{
    int a = 0;
    //检测第一行
    P1 = 0x7f;
    if ((P1 == 0x77) || (P1 == 0x7b) || (P1 == 0x7d) || (P1 == 0x7e))
    {
        tmp = P1;
        tmp = tmp & 0x0f;
        if (tmp != 0x0f)//说明有键按下
        {
            delay(500);
            tmp = P1;
            tmp = tmp & 0x0f;
            if (tmp != 0x0f)
            {
                switch (tmp)
                {
                case 0x07:a = 1; break;
                case 0x0b:a = 2; break;
                case 0x0d:a = 3; break;
                case 0x0e:a = 4; break;
                default:break;
                }
            }
            return a;
        }
        else
        {
            return 0;
        }
    }
    //检测第二行
    P1 = 0xbf;
    if ((P1 == 0xb7) || (P1 == 0xbb) || (P1 == 0xbd) || (P1 == 0xbe))
    {
        tmp = P1;
        tmp = tmp & 0x0f;
        if (tmp != 0x0f)//说明有键按下
        {
            delay(500);
            tmp = P1;
            tmp = tmp & 0x0f;
            if (tmp != 0x0f)
            {
                switch (tmp)
                {
                case 0x07:a = 5; break;
                case 0x0b:a = 6; break;
                case 0x0d:a = 7; break;
                case 0x0e:a = 8; break;
                default:break;
                }
            }
            return a;


        }
        else
        {
            return 0;
        }
    }
    //检测第三行
    P1 = 0xdf;
    if (P1 == 0xd7)
    {
        tmp = P1;
        tmp = tmp & 0x0f;
        if (tmp != 0x0f)//说明有键按下
        {
            delay(500);
            tmp = P1;
            tmp = tmp & 0x0f;
            if (tmp != 0x0f)
            {
                switch (tmp)
                {
                case 0x07:a = 9; break;
                default:break;
                }
            }
            return a;
        }
        else
        {
            return 0;
        }
    }
}