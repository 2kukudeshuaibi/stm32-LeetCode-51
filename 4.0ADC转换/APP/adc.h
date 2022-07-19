#ifndef _adc_H
#define _adc_H

#include "system.h"
#include "systick.h"
void adc_Init();

u16 Get_ADC_VAL(u8 ch,u8 n);


#endif