#include "adc.h"

void adc_Init()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	ADC_InitTypeDef ADC_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	
	ADC_Initstruct.ADC_ContinuousConvMode=DISABLE;
	ADC_Initstruct.ADC_DataAlign=ADC_DataAlign_Right;
	ADC_Initstruct.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	ADC_Initstruct.ADC_Mode=ADC_Mode_Independent;
	ADC_Initstruct.ADC_NbrOfChannel=1;
	ADC_Initstruct.ADC_ScanConvMode=DISABLE;
	ADC_Init(ADC1,&ADC_Initstruct);
	
	ADC_Cmd(ADC1,ENABLE);
	
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
}

u16 Get_ADC_VAL(u8 ch,u8 n)
{
	u8 i=0;
	u32 temp=0;
	ADC_RegularChannelConfig(ADC1,ch,1,ADC_SampleTime_239Cycles5);
	
	for(i=0;i<n;i++)
	{
		ADC_SoftwareStartConvCmd(ADC1,ENABLE);
		
		while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
		
		temp+=ADC_GetConversionValue(ADC1);
		
		delay_ms(1);
	}
	return temp/n;
}
