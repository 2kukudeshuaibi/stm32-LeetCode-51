#include "adc.h"

void AD1_Init()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	ADC_InitTypeDef ADC_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3,ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_8;
	GPIO_Init(GPIOF,&GPIO_Initstruct);
	
	ADC_Initstruct.ADC_ContinuousConvMode=DISABLE;
	ADC_Initstruct.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_Initstruct.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	ADC_Initstruct.ADC_Mode=ADC_Mode_Independent;
	ADC_Initstruct.ADC_NbrOfChannel=1;
	ADC_Initstruct.ADC_ScanConvMode=DISABLE;
	ADC_Init(ADC1,&ADC_Initstruct);
	
	
	ADC_Initstruct.ADC_ContinuousConvMode=DISABLE;
	ADC_Initstruct.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_Initstruct.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	ADC_Initstruct.ADC_Mode=ADC_Mode_Independent;
	ADC_Initstruct.ADC_NbrOfChannel=6;
	ADC_Initstruct.ADC_ScanConvMode=DISABLE;
	ADC_Init(ADC3,&ADC_Initstruct);
	
	ADC_Cmd(ADC1,ENABLE);
	ADC_Cmd(ADC3,ENABLE);
	
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	
	ADC_ResetCalibration(ADC3);
	while(ADC_GetResetCalibrationStatus(ADC3));
	
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	
	ADC_StartCalibration(ADC3);
	while(ADC_GetCalibrationStatus(ADC3));
}

u16 GAT_ADC_VAL_R(u8 n)
{
	u8 i=0;
	u32 temp=0;
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,1,ADC_SampleTime_239Cycles5);
	for(i=0;i<n;i++)
	{
		ADC_SoftwareStartConvCmd(ADC1,ENABLE);
		while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
		temp+=ADC_GetConversionValue(ADC1);
		delay_ms(1);
	}
	return temp/n;
}

u16 GAT_ADC_VAL_LIGHT(u8 n)
{
	u8 i=0;
	u32 temp=0;
	ADC_RegularChannelConfig(ADC3,ADC_Channel_6,1,ADC_SampleTime_239Cycles5);
	for(i=0;i<n;i++)
	{
		ADC_SoftwareStartConvCmd(ADC3,ENABLE);
		while(!ADC_GetFlagStatus(ADC3,ADC_FLAG_EOC));
		temp+=ADC_GetConversionValue(ADC3);
		delay_ms(1);
	}
	return temp/n;
}