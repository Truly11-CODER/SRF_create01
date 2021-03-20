#include "led.h"

void LED_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  
	GPIO_InitStructure.GPIO_Pin= LED;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(LEDPORT,&GPIO_InitStructure);
}

void LED_ON(void){
	GPIO_ResetBits (LEDPORT,LED);
	//GPIO_WriteBit(LEDPORT,LED,Bit_RESET);
}

void LED_OFF(void){
	GPIO_SetBits (LEDPORT,LED);
	//GPIO_WriteBit(LEDPORT,LED,Bit_SET);
}


