#include <reg51.h>
#include <intrins.h>

sbit dja=P2^0;
sbit djb=P2^1;
sbit s1=P3^1;
sbit s2=P3^0;
bit  flag;
char num;
void delay(unsigned int k);//ÑÓÊ±º¯Êý
void fengshan(bit a,bit b,unsigned int b1,unsigned int b2);

void main()
{
   dja=0;
   djb=0;
   flag=0;
   num=0;
   while(1)
   {
     if(s1==0)
     {
        while(!s1);
        flag=~flag;
     }
     if(s2==0)
     {
        while(!s2);
        if(num<=3)
        {
           num++;
        }
        else
        {
           num=0;
        }
     }
     if(!flag)
     {
        switch(num)
        {
           case 0:fengshan(0,0,0,0);break;
           case 1:fengshan(0,1,100,2000);break;
           case 2:fengshan(0,1,500,2000);break;
           case 3:fengshan(0,1,1500,2000);break;
        } 
     }
     else
     {
        switch(num)
        {
           case 0:fengshan(0,0,0,0);break;
           case 1:fengshan(1,0,100,2000);break;
           case 2:fengshan(1,0,500,2000);break;
           case 3:fengshan(1,0,1500,2000);break;
        }
     }
   }
}
void delay(unsigned int k)
{
   unsigned int kk;
   for(kk=0;kk<k;kk++);
}
void fengshan(bit a,bit b,unsigned int b1,unsigned int b2)
{
    dja=a;
    djb=b;
    delay(b1);
    dja=0;
    djb=0;
    delay(b2);
}