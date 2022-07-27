#ifndef _iic_H
#define _iic_H

#include "system.h"
#include "systick.h"

#define IIC_SCL_PORT 		GPIOB
#define IIC_SCL_Pin   		GPIO_Pin_6
#define IIC_SCL_PORT_RCC 	RCC_APB2Periph_GPIOB

#define IIC_SDA_PORT 		GPIOB
#define IIC_SDA_Pin   		GPIO_Pin_7
#define IIC_SDA_PORT_RCC 	RCC_APB2Periph_GPIOB

#define IIC_SCL		PBout(6)
#define IIC_SDA		PBout(7)
#define READ_SDA 	PBin(7)

void IIC_Init();
void SDA_OUT();
void SDA_IN();
void IIC_STAR();
void IIC_STOP();
void IIC_ACK();
void IIC_NACK();
void IIC_Write_byte(u8 data);
u8 IIC_Read_byte(u8 ack);
u8 IIC_Wait_ACK();



#endif