#ifndef __RTHM_H__
#define __RTHM_H__

#define  RTHM    GPIO_Pin_15 
#define RTHMPORT GPIOC

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
void Putout(uint8_t a);
void RTHM_Init(void);

#endif
