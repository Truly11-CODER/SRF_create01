#ifndef  __LED_H__
#define  __LED_H__
#define LEDPORT GPIOC
#define LED     GPIO_Pin_13 
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
void LED_Init(void);
void LED_OFF(void);
void LED_ON(void);
#endif
