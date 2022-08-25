#ifndef _touch_H
#define _touch_H

#include "system.h"
#include "tftlcd.h"
#include "systick.h"


extern u16 arrx[10];
extern u16 arry[10];



#define TP_PRES_DOWN 0x80  //触屏被按下	  
#define TP_CATH_PRES 0x40  //有按键按下了 
#define CT_MAX_TOUCH 10 

#define PEN     PFin(10)    //T_PEN
#define DOUT    PBin(2)    	//T_MISO
#define TDIN    PFout(9)   	//T_MOSI
#define TCLK    PBout(1)   	//T_SCK
#define TCS     PFout(11)   //T_CS  

void TP_Init(void);
void TP_ADjust();
u8 TP_Scan(u8 tp);


#endif
