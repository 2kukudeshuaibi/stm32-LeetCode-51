#ifndef _SRAM_H
#define _SRAM_H

#include "system.h"
#include "systick.h"
#include "usart.h"
//ʹ��NOR_SRAM�� Bank1.setor3,��ַλHADDR[27,26]=10

#define Bank1_SRAM_ADDR						(0x68000000)
#define IS62WV51216_SIZE					(0x100000)                 //1M�ֽ�
#define SRAM_END_ADDR						(Bank1_SRAM_ADDR+IS62WV51216_SIZE)

/*A��ַ�ź���*/
#define FSMC_A0_GPIO_PORT					GPIOF
#define FSMC_A0_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A0_PIN							GPIO_Pin_0

#define FSMC_A1_GPIO_PORT					GPIOF
#define FSMC_A1_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A1_PIN							GPIO_Pin_1

#define FSMC_A2_GPIO_PORT					GPIOF
#define FSMC_A2_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A2_PIN							GPIO_Pin_2

#define FSMC_A3_GPIO_PORT					GPIOF
#define FSMC_A3_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A3_PIN							GPIO_Pin_3

#define FSMC_A4_GPIO_PORT					GPIOF
#define FSMC_A4_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A4_PIN							GPIO_Pin_4

#define FSMC_A5_GPIO_PORT					GPIOF
#define FSMC_A5_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A5_PIN							GPIO_Pin_5

#define FSMC_A6_GPIO_PORT					GPIOF
#define FSMC_A6_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A6_PIN							GPIO_Pin_12

#define FSMC_A7_GPIO_PORT					GPIOF
#define FSMC_A7_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A7_PIN							GPIO_Pin_13

#define FSMC_A8_GPIO_PORT					GPIOF
#define FSMC_A8_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A8_PIN							GPIO_Pin_14

#define FSMC_A9_GPIO_PORT					GPIOF
#define FSMC_A9_CLK							RCC_APB2Periph_GPIOF
#define FSMC_A9_PIN							GPIO_Pin_15

#define FSMC_A10_GPIO_PORT					GPIOG
#define FSMC_A10_CLK						RCC_APB2Periph_GPIOG
#define FSMC_A10_PIN						GPIO_Pin_0

#define FSMC_A11_GPIO_PORT					GPIOG
#define FSMC_A11_CLK						RCC_APB2Periph_GPIOG
#define FSMC_A11_PIN						GPIO_Pin_1

#define FSMC_A12_GPIO_PORT					GPIOG
#define FSMC_A12_CLK						RCC_APB2Periph_GPIOG
#define FSMC_A12_PIN						GPIO_Pin_2

#define FSMC_A13_GPIO_PORT					GPIOG
#define FSMC_A13_CLK						RCC_APB2Periph_GPIOG
#define FSMC_A13_PIN						GPIO_Pin_3

#define FSMC_A14_GPIO_PORT					GPIOG
#define FSMC_A14_CLK						RCC_APB2Periph_GPIOG
#define FSMC_A14_PIN						GPIO_Pin_4

#define FSMC_A15_GPIO_PORT					GPIOG
#define FSMC_A15_CLK						RCC_APB2Periph_GPIOG
#define FSMC_A15_PIN						GPIO_Pin_5

#define FSMC_A16_GPIO_PORT					GPIOD
#define FSMC_A16_CLK						RCC_APB2Periph_GPIOD
#define FSMC_A16_PIN						GPIO_Pin_11

#define FSMC_A17_GPIO_PORT					GPIOD
#define FSMC_A17_CLK						RCC_APB2Periph_GPIOD
#define FSMC_A17_PIN						GPIO_Pin_12

#define FSMC_A18_GPIO_PORT					GPIOD
#define FSMC_A18_CLK						RCC_APB2Periph_GPIOD
#define FSMC_A18_PIN						GPIO_Pin_13

/*D�����ź���*/
#define FSMC_D0_GPIO_PORT					GPIOD
#define FSMC_D0_CLK						    RCC_APB2Periph_GPIOD
#define FSMC_D0_PIN						    GPIO_Pin_14

#define FSMC_D1_GPIO_PORT					GPIOD
#define FSMC_D1_CLK						    RCC_APB2Periph_GPIOD
#define FSMC_D1_PIN						    GPIO_Pin_15

#define FSMC_D2_GPIO_PORT					GPIOD
#define FSMC_D2_CLK						    RCC_APB2Periph_GPIOD
#define FSMC_D2_PIN						    GPIO_Pin_0

#define FSMC_D3_GPIO_PORT					GPIOD
#define FSMC_D3_CLK						    RCC_APB2Periph_GPIOD
#define FSMC_D3_PIN						    GPIO_Pin_1

#define FSMC_D4_GPIO_PORT					GPIOE
#define FSMC_D4_CLK						    RCC_APB2Periph_GPIOE
#define FSMC_D4_PIN						    GPIO_Pin_7

#define FSMC_D5_GPIO_PORT					GPIOE
#define FSMC_D5_CLK						    RCC_APB2Periph_GPIOE
#define FSMC_D5_PIN						    GPIO_Pin_8

#define FSMC_D6_GPIO_PORT					GPIOE
#define FSMC_D6_CLK						    RCC_APB2Periph_GPIOE
#define FSMC_D6_PIN						    GPIO_Pin_9

#define FSMC_D7_GPIO_PORT					GPIOE
#define FSMC_D7_CLK						    RCC_APB2Periph_GPIOE
#define FSMC_D7_PIN						    GPIO_Pin_10

#define FSMC_D8_GPIO_PORT					GPIOE
#define FSMC_D8_CLK						    RCC_APB2Periph_GPIOE
#define FSMC_D8_PIN						    GPIO_Pin_11

#define FSMC_D9_GPIO_PORT					GPIOE
#define FSMC_D9_CLK						    RCC_APB2Periph_GPIOE
#define FSMC_D9_PIN						    GPIO_Pin_12

#define FSMC_D10_GPIO_PORT					GPIOE
#define FSMC_D10_CLK						RCC_APB2Periph_GPIOE
#define FSMC_D10_PIN						GPIO_Pin_13

#define FSMC_D11_GPIO_PORT					GPIOE
#define FSMC_D11_CLK						RCC_APB2Periph_GPIOE
#define FSMC_D11_PIN						GPIO_Pin_14

#define FSMC_D12_GPIO_PORT					GPIOE
#define FSMC_D12_CLK						RCC_APB2Periph_GPIOE
#define FSMC_D12_PIN						GPIO_Pin_15

#define FSMC_D13_GPIO_PORT					GPIOD
#define FSMC_D13_CLK						RCC_APB2Periph_GPIOD
#define FSMC_D13_PIN						GPIO_Pin_8

#define FSMC_D14_GPIO_PORT					GPIOD
#define FSMC_D14_CLK						RCC_APB2Periph_GPIOD
#define FSMC_D14_PIN						GPIO_Pin_9

#define FSMC_D15_GPIO_PORT					GPIOD
#define FSMC_D15_CLK						RCC_APB2Periph_GPIOD
#define FSMC_D15_PIN						GPIO_Pin_10

/*�����ź���*/
/*CSƬѡ*/
/*NE3 ��Ӧ�Ļ���ַ0x68000000*/
#define FSMC_CS_GPIO_PORT					GPIOG
#define FSMC_CS_GPIO_CLK                    RCC_APB2Periph_GPIOG
#define FSMC_CS_GPIO_PIN   					GPIO_Pin_10


/*WEдʹ��*/
#define FSMC_WE_GPIO_PORT					GPIOD
#define FSMC_WE_GPIO_CLK                    RCC_APB2Periph_GPIOD
#define FSMC_WE_GPIO_PIN   					GPIO_Pin_5

/*OE��ʹ��*/
#define FSMC_OE_GPIO_PORT					GPIOD
#define FSMC_OE_GPIO_CLK                    RCC_APB2Periph_GPIOD
#define FSMC_OE_GPIO_PIN   					GPIO_Pin_4

/*LB��������*/
#define FSMC_UDQM_GPIO_PORT					GPIOE
#define FSMC_UDQM_GPIO_CLK                  RCC_APB2Periph_GPIOE
#define FSMC_UDQM_GPIO_PIN   				GPIO_Pin_1


#define FSMC_LDQM_GPIO_PORT					GPIOE
#define FSMC_LDQM_GPIO_CLK                  RCC_APB2Periph_GPIOE
#define FSMC_LDQM_GPIO_PIN   				GPIO_Pin_0

void SRAM_Init();

#endif
