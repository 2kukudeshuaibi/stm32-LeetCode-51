#ifndef _LED_H
#define _LED_H

#include "system.h"

#define LED1_PORT_RCC   RCC_APB2Periph_GPIOB
#define LED1_Pin        GPIO_Pin_5
#define LED1_PORT       GPIOB

#define LED2_PORT_RCC   RCC_APB2Periph_GPIOE
#define LED2_Pin        GPIO_Pin_5
#define LED2_PORT       GPIOE


#define LED11     PBout(5)
#define LED21     PEout(5)

void LED1_Init();

#endif
