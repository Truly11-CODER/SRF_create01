 /*sys.h   �����������������ͷ�ļ�*/
#ifndef __SYS_H   //ͷ�����е�#ifndef������һ���ܹؼ��Ķ�����������������C�ļ���������C�ļ���include��ͬһ��ͷ�ļ���������ʱ��������C�ļ�Ҫһͬ�����һ���������ļ��������������ˣ�������������ͻ�����ǰ�ͷ�ļ������ݶ�����#ifndef��#endif�аɡ��������ͷ�ļ��᲻�ᱻ����ļ����ã��㶼Ҫ�������
#define __SYS_H      
#include "stm32f10x.h"//����������ʲ�Core Peripheral Access Layer��CPAL����ͷ�ļ������������������Ҫ�õ���ͷ�ļ���Ϣ�����������ǻὲ��ġ�
         


//0,��֧��ucos
//1,֧��ucos
#define SYSTEM_SUPPORT_UCOS                0                //����ϵͳ�ļ����Ƿ�֧��UCOS��SYSTEM_SUPPORT_UCOS������궨���������� SYSTEM �ļ����Ƿ�֧�� ucos������� ucos ����ʹ�� SYSTEM �ļ��У���ô�������ֵΪ 1 ���ɣ���������Ϊ 0��Ĭ�ϣ���                                                                                                                                          
         
//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//IO�ڲ����궨�壬 �������ģ��ǵ�MCS51�� MCS51������λ��������һλ��BIT��Ϊ���ݶ���Ĳ����� 
//      MCS51���Լ򵥵Ľ�P1�ڵĵ�2λ���������� P1.2=0;P1.2=1 ; ����������P1�ڵĵ������ţ�BIT2����0�á� 
//      ������STM32��λ�Ρ�λ����������Ϊ��ʵ�������Ĺ��ܡ�      
//      ���������SRAM,I/O����ռ䡣ʵ�ֶ���Щ�ط���ĳһλ�Ĳ����� 
//      ���������ġ���Ѱַ�ռ䣨32λ��ַ�� 4GB ����һ�ط���ȡ���������ռ䣬�����ַ��ʼ����ÿһ���֣�32BIT�� 
//      �Ͷ�ӦSRAM��I/O��һλ�� 
//      �����أ�1MB SRAM�� ������32MB�Ķ�Ӧ�������ռ䣬����1λ���͵�32λ��1BIT ��Ϊ1���֣� 
 //     ���Ƕ�����������ռ俪ʼ��ĳһ�ֲ�������0����1���͵�����ӳ���SRAM��I/O��Ӧ��ĳ��ַ��ĳһλ�Ĳ���������˵�����԰Ѵ�����С�� �ٶȸ��죬Ч�ʸ��ߣ�����ȫ�� 
 //     һ�����Ҫ6��ָ���ʹ��λ��������ֻҪ4��ָ�   
 //     һ������Ƕ����ģ�д�ķ�ʽ�� ��λ����������д��������ֹ�ж϶Զ����ģ�д�ķ�ʽ��Ӱ�졣STM32��ÿ��GPIO�ڶ����Ա�̣���51һ����������λѰַ��STM32��ÿ��IO�˿ڶ���7���Ĵ��������ơ����Ƿֱ��ǣ�����ģʽ��2��32λ�Ķ˿����üĴ���CRL��CRH��2��32λ�����ݼĴ���IDR��ODR��1��32λ����λ/��λ�Ĵ���BSRR��һ��16λ�ĸ�λ�Ĵ���BRR��1��32λ������Ĵ���LCKRĿǰ����ʹ��ģʽ�Ĵ��������ݼĴ����Ϳ���ʵ�ּ򵥵�GPIO�ڿ��ƹ��ܡ����ȣ���ϵͳʱ�ӺͶ�Ӧ������ʱ�ӣ�Ȼ��λ�����IO�ڵ�ģʽ���ã���λ����֮�������λ������Ҫ�ᵽһ����ǣ������ݼĴ����Ĳ�������ֱ�Ӹ�ֵ�Ĵ�����������ʹ��һ�ֽ���λ�������ķ�ʽ��������λѰַ������ȽϷ��㡣/*��ʼ��GPIO���ã�Ϊ����Ҫ��ģʽ*/GPIOC->CRL&=0XFFFFFFF0;//Clear PORTC.0 SetingGPIOC->CRL|=0X0000003;//����Ϊ�������GPIOC->ODR=1<0; //PC.0��ʼ��Ϊ�߼�1 /*λ�������궨��*/#define LED0 PCout(0)// PC0#define LED1 PDout(2)// PD2#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF )<<5)+(bitnum<<2))
#define MEM_ADDR(addr)*((volatile unsigned long*)(addr)) //ǿ��ת��Ϊָ��
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) //����һ����������һ��



//IO�ڵ�ַӳ��
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C �궨���ַ������Ĵ�����
//GPIO->ODR��32λ��������ݼĴ�������16λ��������16Ϊ���ζ�Ӧĳ��GPIO�ڵ�16�����ţ�����ODR��ֵ��һ�β���16λ�ģ�Ҳ����ͬʱ������16�����ŵ������ƽ����GPIO_PIN��ָĳ���˿ڵľ���ĳһ�����ţ���λ����������ͨ������BSRR��BRR�Ĵ���������ĳһ�ض����ŵ������ƽ����������������������䣬�ٶȿ죬Ч�ʸߡ�������Կ���stm32�ο��ֲ����GPIO�Ĵ�����˵����
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C �궨���ַ������Ĵ����� 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C �궨���ַ������Ĵ����� 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C�궨���ַ������Ĵ����� 


#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 GPIO->IDR��32λ���������ݼĴ���
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 �궨���ַ������Ĵ����� 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 �궨���ַ������Ĵ����� 

//IO�ڲ���,ֻ�Ե�һ��IO��!
//ȷ��n��ֵС��16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)//��� ���͵�λ��������
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)//���� 


#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)//��� 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)//���� 


#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)//��� 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)//���� 


#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)//��� 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)//���� 


#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)//��� 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)//����


#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)//��� 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)//����


#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)//��� 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)//����

void NVIC_Configuration(void);//����ӳ���жϵĴ�����, 

#endif
