#ifndef _usart_H
#define _usart_H

#include "system.h"
#include "stdio.h"

#define USART1_REC_LEN 200

extern u8 USART1_RX_BUF[USART1_REC_LEN];
extern u16 USART1_RX_STA;

void USART1_Init(u32 baud);
int fputc(int ch,FILE* P);
#endif
