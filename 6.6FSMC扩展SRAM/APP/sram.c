#include "sram.h"


static void SRAM_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOF,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);
	
	
	
	/*---GPIO配置-------------------------------------------*/
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Pin=FSMC_A0_PIN;
	GPIO_Init(FSMC_A0_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A1_PIN;
	GPIO_Init(FSMC_A1_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A2_PIN;
	GPIO_Init(FSMC_A2_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A3_PIN;
	GPIO_Init(FSMC_A3_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A4_PIN;
	GPIO_Init(FSMC_A4_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A5_PIN;
	GPIO_Init(FSMC_A5_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A6_PIN;
	GPIO_Init(FSMC_A6_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A7_PIN;
	GPIO_Init(FSMC_A7_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A8_PIN;
	GPIO_Init(FSMC_A8_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A9_PIN;
	GPIO_Init(FSMC_A9_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A10_PIN;
	GPIO_Init(FSMC_A10_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A11_PIN;
	GPIO_Init(FSMC_A11_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A12_PIN;
	GPIO_Init(FSMC_A12_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A13_PIN;
	GPIO_Init(FSMC_A13_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A14_PIN;
	GPIO_Init(FSMC_A14_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A15_PIN;
	GPIO_Init(FSMC_A15_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A16_PIN;
	GPIO_Init(FSMC_A16_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A17_PIN;
	GPIO_Init(FSMC_A17_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_A18_PIN;
	GPIO_Init(FSMC_A18_GPIO_PORT,&GPIO_Initstruct);
	
	/*DQ数据信号线引脚配置*/
	GPIO_Initstruct.GPIO_Pin=FSMC_D0_PIN;
	GPIO_Init(FSMC_D0_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D1_PIN;
	GPIO_Init(FSMC_D1_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D2_PIN;
	GPIO_Init(FSMC_D2_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D3_PIN;
	GPIO_Init(FSMC_D3_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D4_PIN;
	GPIO_Init(FSMC_D4_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D5_PIN;
	GPIO_Init(FSMC_D5_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D6_PIN;
	GPIO_Init(FSMC_D6_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D7_PIN;
	GPIO_Init(FSMC_D7_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D8_PIN;
	GPIO_Init(FSMC_D8_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D9_PIN;
	GPIO_Init(FSMC_D9_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D10_PIN;
	GPIO_Init(FSMC_D10_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D11_PIN;
	GPIO_Init(FSMC_D11_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D12_PIN;
	GPIO_Init(FSMC_D12_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D13_PIN;
	GPIO_Init(FSMC_D13_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D14_PIN;
	GPIO_Init(FSMC_D14_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_D15_PIN;
	GPIO_Init(FSMC_D15_GPIO_PORT,&GPIO_Initstruct);
	
	/*控制信号线*/
	GPIO_Initstruct.GPIO_Pin=FSMC_CS_GPIO_PIN;
	GPIO_Init(FSMC_CS_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_WE_GPIO_PIN;
	GPIO_Init(FSMC_WE_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_OE_GPIO_PIN;
	GPIO_Init(FSMC_OE_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_UDQM_GPIO_PIN;
	GPIO_Init(FSMC_UDQM_GPIO_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=FSMC_LDQM_GPIO_PIN;
	GPIO_Init(FSMC_LDQM_GPIO_PORT,&GPIO_Initstruct);
}

static void FSMC_Mode_Config()
{
	FSMC_NORSRAMTimingInitTypeDef ReadTimingInitstruct;
	FSMC_NORSRAMTimingInitTypeDef WriteTimingInitstruct;
	FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitstruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);
	//读时序
	ReadTimingInitstruct.FSMC_AccessMode=FSMC_AccessMode_A;
	ReadTimingInitstruct.FSMC_AddressHoldTime=0;//SRAM用不到
	ReadTimingInitstruct.FSMC_AddressSetupTime=0;
	ReadTimingInitstruct.FSMC_BusTurnAroundDuration=0;//SRAM用不到
	ReadTimingInitstruct.FSMC_CLKDivision=0;//SRAM用不到
	ReadTimingInitstruct.FSMC_DataLatency=0;//SRAM用不到
	ReadTimingInitstruct.FSMC_DataSetupTime=2;
	
	//写时序
	WriteTimingInitstruct.FSMC_AccessMode=FSMC_AccessMode_A;
	WriteTimingInitstruct.FSMC_AddressHoldTime=0;//SRAM用不到
	WriteTimingInitstruct.FSMC_AddressSetupTime=0;
	WriteTimingInitstruct.FSMC_BusTurnAroundDuration=0;//SRAM用不到
	WriteTimingInitstruct.FSMC_CLKDivision=0;//SRAM用不到
	WriteTimingInitstruct.FSMC_DataLatency=0;//SRAM用不到
	WriteTimingInitstruct.FSMC_DataSetupTime=2;
	
	
	FSMC_NORSRAMInitstruct.FSMC_WriteOperation=FSMC_WriteOperation_Enable;
	FSMC_NORSRAMInitstruct.FSMC_Bank=FSMC_Bank1_NORSRAM3;
	FSMC_NORSRAMInitstruct.FSMC_ExtendedMode=FSMC_ExtendedMode_Enable;
	FSMC_NORSRAMInitstruct.FSMC_MemoryDataWidth=FSMC_MemoryDataWidth_16b;
	FSMC_NORSRAMInitstruct.FSMC_MemoryType=FSMC_MemoryType_SRAM;
	
	
	FSMC_NORSRAMInitstruct.FSMC_BurstAccessMode=FSMC_BurstAccessMode_Disable;
	FSMC_NORSRAMInitstruct.FSMC_DataAddressMux=FSMC_DataAddressMux_Disable;
	FSMC_NORSRAMInitstruct.FSMC_WaitSignal=FSMC_WaitSignal_Disable;
	FSMC_NORSRAMInitstruct.FSMC_WaitSignalActive=FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_NORSRAMInitstruct.FSMC_WaitSignalPolarity=FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitstruct.FSMC_WrapMode=FSMC_WrapMode_Disable;
	FSMC_NORSRAMInitstruct.FSMC_WriteBurst=FSMC_WriteBurst_Disable;
	FSMC_NORSRAMInitstruct.FSMC_AsynchronousWait=FSMC_AsynchronousWait_Disable;
	
	
	FSMC_NORSRAMInitstruct.FSMC_WriteTimingStruct=&WriteTimingInitstruct;
	FSMC_NORSRAMInitstruct.FSMC_ReadWriteTimingStruct=&ReadTimingInitstruct;
	FSMC_NORSRAMInit(&FSMC_NORSRAMInitstruct);
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3,ENABLE);
}


void SRAM_Init()
{
	SRAM_GPIO_Config();
	FSMC_Mode_Config();
}
