#ifndef _usart_H
#define _usart_H

#include "system.h"
#include "systick.h"
#include "stdio.h"
#define USART1_REC_LEN 100
void USART1_Init(u32 bud);
int fputc(int ch,FILE* p);

#endif