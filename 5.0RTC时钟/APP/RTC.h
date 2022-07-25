#ifndef _RTC_H
#define _RTC_H
#include "system.h"
#include "systick.h"
#include "usart.h"


//时间结构体
typedef struct 
{
	u8 hour;
	u8 min;
	u8 sec;	
	
	//公历日月年周
	u16 w_year;
	u8  w_month;
	u8  w_date;
	u8  week;		 
}_calendar;					 
extern _calendar calendar;	//日历结构体


u8 Is_Leap_Year(u16 year);
u8 RTC_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
u8 RTC_Init();
u8 RTC_Get(void);
u8 RTC_Get_Week(u16 year,u8 month,u8 day);
u8 RTC_Alarm_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
static void RTC_NVIC_Config(void);

#endif