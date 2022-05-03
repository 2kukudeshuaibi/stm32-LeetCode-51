#include "IR.h"
#include "LCD1602.h"
#include "INT0.h"
#include "time0.h"

uint  IR_Time;
uchar IR_state;

uchar IR_date[4];
uchar IR_pdate;


uchar IR_dateflag;
uchar IR_repeatflag;

uchar IR_address;
uchar IR_command;

void IR_Init()
{
   time0_init();
   INT0_init();
}



void Int0_Routine() interrupt 0
{
   if(IR_state==0)
   {
      
      timer_setcounter(0);
      timer_run(1);
      IR_state=1;
   }
   else if(IR_state==1)
   {
      
      IR_Time=timer_getcounter();
      timer_setcounter(0);
      if(IR_Time>13500-500 && IR_Time<13500+500)
      {
          
          IR_state=2;
      }
      else if(IR_Time>11250-500 && IR_Time<11250+500)
      {
         P2=0;
         IR_repeatflag=1;
         timer_run(0);
         IR_state=0;
      }
      else
      {
         IR_state=1;
      }
   }
   else if(IR_state==2)
   {
      IR_Time=timer_getcounter();
      timer_setcounter(0);
      if(IR_Time>1120-500 && IR_Time<1120+500)
      {
          IR_date[IR_pdate/8]&=~(0x01<<(IR_pdate%8));
          IR_pdate++;
      }
      else if(IR_Time>2250-500 && IR_Time<2250+500)
      {
          IR_date[IR_pdate/8]|=(0x01<<(IR_pdate%8));
          IR_pdate++;
      }
      else
      {
          IR_pdate=0;
          IR_state=1;
      }
      if(IR_pdate>=32)
      {
           IR_pdate=0;
           if((IR_date[0]==~IR_date[1]) && (IR_date[2]==~IR_date[3]))
           {
               IR_dateflag=1;
               IR_address=IR_date[0];
               IR_command=IR_date[2];
           }
           timer_run(0);
           IR_state=0;
      }
   }
}  