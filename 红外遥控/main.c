#include "LCD1602.h"
#include <reg52.h>
#include "INT0.h"
#include "time0.h"
#include "IR.h"




uchar num=0;
uint time=0;

void main()
{
   LCD_Init();

   IR_Init();

   while(1)
   {
      
   }
}

