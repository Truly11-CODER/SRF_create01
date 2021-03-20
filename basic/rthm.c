#include "rthm.h"
#include "delay.h"
#include "led.h"
void RTHM_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure2;
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  
	GPIO_InitStructure2.GPIO_Pin= RTHM;
	GPIO_InitStructure2.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_InitStructure2.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(RTHMPORT,&GPIO_InitStructure2);
	
}

void Putout(uint8_t a){
	uint32_t i;
	if(a==1)	
		for(i=100;i>=1;i--){	
			GPIO_SetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(954);
		  GPIO_ResetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(954);
		}
	if(a==2)	
		for(i=100;i>=1;i--){	
			GPIO_SetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(901);
		  GPIO_ResetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(901);
		}
	if(a==3)
		for(i=100;i>=1;i--){	
			GPIO_SetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(850);
		  GPIO_ResetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(850);
		}
	if(a==4)
		for(i=100;i>=1;i--){	
			GPIO_SetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(803);
		  GPIO_ResetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(803);
		}
	if(a==5)	
		for(i=100;i>=1;i--){	
			GPIO_SetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(758);
		  GPIO_ResetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(758);
		}
	if(a==6)
		for(i=100;i>=1;i--){	
			GPIO_SetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(715);
		  GPIO_ResetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(715);
		}
	if(a==7)
		for(i=100;i>=1;i--){	
			GPIO_SetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(675);
		  GPIO_ResetBits (LEDPORT,RTHM);
			//Delay_us(1000);
			Delay_us(675);
		}

}

/* 3823us
3405us
3040us
2864us
2551us
2273us
2025us

*/
