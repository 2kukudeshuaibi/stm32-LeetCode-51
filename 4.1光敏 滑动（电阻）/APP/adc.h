#ifndef _adc_H
#define _adc_H

#include "system.h"

#include "systick.h"
void AD1_Init();
u16 GAT_ADC_VAL_R(u8 n);
u16 GAT_ADC_VAL_LIGHT(u8 n);

#endif