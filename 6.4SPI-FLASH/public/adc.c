#include "adc.h"


void ADC1_Init()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	ADC_InitTypeDef ADC_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_8;
	GPIO_Init(GPIOF,&GPIO_Initstruct);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	ADC_Initstruct.ADC_ContinuousConvMode=DISABLE;
	ADC_Initstruct.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_Initstruct.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	ADC_Initstruct.ADC_Mode=ADC_Mode_Independent;
	ADC_Initstruct.ADC_NbrOfChannel=1;
	ADC_Initstruct.ADC_ScanConvMode=DISABLE;
	ADC_Init(ADC3,&ADC_Initstruct);
	
	ADC_Cmd(ADC3,ENABLE);
	
	ADC_ResetCalibration(ADC3);
	while(ADC_GetResetCalibrationStatus(ADC3));
	
	ADC_StartCalibration(ADC3);
	while(ADC_GetCalibrationStatus(ADC3));
	
	ADC_SoftwareStartConvCmd(ADC3,ENABLE);
}

u16 Get_Val()
{
	u8 i=5;
	u16 tmp=0;
	ADC_RegularChannelConfig(ADC3,ADC_Channel_6,1,ADC_SampleTime_239Cycles5);
	while(i--)
	{
		ADC_SoftwareStartConvCmd(ADC3,ENABLE);
		while(!ADC_GetFlagStatus(ADC3,ADC_FLAG_EOC));
		tmp+=ADC_GetConversionValue(ADC3);
		delay_ms(1);
	}
	return tmp/5;
}