#include "delay.h"

void Delay_us(uint32_t s){
	SysTick->LOAD=72*s;
	SysTick->CTRL=0x00000005;
	while(!(SysTick->CTRL&0x00010000));
	SysTick->CTRL=0x00000004;
}

void Delay_ms(uint32_t s){
		int i;
    i=s;	
		while(i-- !=0){
			Delay_us(1000);
		}
}
