#include <reg52.h>
#include "INT0.h"


void INT0_init()
{
   IT0=1;
   IE0=0;
   EX0=1;
   EA=1;
   PX0=1;
}

//void Int0_Routine() interrupt 0
//{
//   
//}