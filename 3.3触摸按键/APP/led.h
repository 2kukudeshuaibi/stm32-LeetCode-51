#ifndef _led_H
#define _led_H

#include "system.h"

void LED_Init();

#define LED0 PBout(5)
#define LED1 PEout(5)

#endif