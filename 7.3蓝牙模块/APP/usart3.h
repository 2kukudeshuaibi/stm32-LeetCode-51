#ifndef _USART3_H
#define _USART3_H

#include "system.h"
#include "systick.h"
#include "Time.h"

#define USART3_MAX_RECV_LEN  600
#define USART3_MAX_SEND_LEN  600

extern u8 USART3_RX_BUFF[600];
extern u8 USART3_TX_BUFF[600];

extern vu16 USART3_RX_STA;

void USART3_Init(u32 baud);
void u3_printf(char* fmt,...);

#endif