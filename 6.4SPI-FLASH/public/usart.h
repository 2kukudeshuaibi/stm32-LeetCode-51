#ifndef _usart_H
#define _usart_H

#include "system.h"
#include "systick.h"
#include "stdio.h"
#include "oled.h"

extern u8 FLAG_ON_OFF;


void USART1_Init();
int fputc(int ch,FILE* P);

#endif
