 /*sys.h   今天我们来讲讲这个头文件*/
#ifndef __SYS_H   //头件的中的#ifndef，这是一个很关键的东西。比如你有两个C文件，这两个C文件都include了同一个头文件。而编译时，这两个C文件要一同编译成一个可运行文件，于是问题来了，大量的声明冲突。还是把头文件的内容都放在#ifndef和#endif中吧。不管你的头文件会不会被多个文件引用，你都要加上这个
#define __SYS_H      
#include "stm32f10x.h"//核内外设访问层Core Peripheral Access Layer（CPAL）的头文件，它定义了许多外设要用到的头文件信息，接下来我们会讲解的。
         


//0,不支持ucos
//1,支持ucos
#define SYSTEM_SUPPORT_UCOS                0                //定义系统文件夹是否支持UCOS，SYSTEM_SUPPORT_UCOS，这个宏定义用来定义 SYSTEM 文件夹是否支持 ucos，如果在 ucos 下面使用 SYSTEM 文件夹，那么设置这个值为 1 即可，否则设置为 0（默认）。                                                                                                                                          
         
//位带操作,实现51类似的GPIO控制功能
//IO口操作宏定义， 是这样的，记得MCS51吗？ MCS51就是有位操作，以一位（BIT）为数据对象的操作， 
//      MCS51可以简单的将P1口的第2位独立操作： P1.2=0;P1.2=1 ; 就是这样把P1口的第三个脚（BIT2）置0置。 
//      而现在STM32的位段、位带别名区就为了实现这样的功能。      
//      对象可以是SRAM,I/O外设空间。实现对这些地方的某一位的操作。 
//      它是这样的。在寻址空间（32位地址是 4GB ）另一地方，取个别名区空间，从这地址开始处，每一个字（32BIT） 
//      就对应SRAM或I/O的一位。 
//      这样呢，1MB SRAM就 可以有32MB的对应别名区空间，就是1位膨胀到32位（1BIT 变为1个字） 
 //     我们对这个别名区空间开始的某一字操作，置0或置1，就等于它映射的SRAM或I/O相应的某地址的某一位的操作。简单来说，可以把代码缩小， 速度更快，效率更高，更安全。 
 //     一般操作要6条指令，而使用位带别名区只要4条指令。   
 //     一般操作是读－改－写的方式， 而位带别名区是写操作。防止中断对读－改－写的方式的影响。STM32的每个GPIO口都可以编程，和51一样，都不能位寻址；STM32的每个IO端口都有7个寄存器来控制。他们分别是：配置模式的2个32位的端口配置寄存器CRL和CRH；2个32位的数据寄存器IDR和ODR；1个32位的置位/复位寄存器BSRR；一个16位的复位寄存器BRR；1个32位的锁存寄存器LCKR目前我们使用模式寄存器和数据寄存器就可以实现简单的GPIO口控制功能。首先，开系统时钟和对应的外设时钟，然后复位所需的IO口的模式配置，复位结束之后进行置位，这里要提到一点的是，对数据寄存器的操作可以直接赋值寄存器，还可以使用一种叫做位带操作的方式，类似于位寻址；这个比较方便。/*初始化GPIO设置，为所需要的模式*/GPIOC->CRL&=0XFFFFFFF0;//Clear PORTC.0 SetingGPIOC->CRL|=0X0000003;//设置为推挽输出GPIOC->ODR=1<0; //PC.0初始化为逻辑1 /*位带操作宏定义*/#define LED0 PCout(0)// PC0#define LED1 PDout(2)// PD2#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF )<<5)+(bitnum<<2))
#define MEM_ADDR(addr)*((volatile unsigned long*)(addr)) //强制转换为指针
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) //再来一个宏重命名一下



//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 宏定义地址，输出寄存器。
//GPIO->ODR是32位的输出数据寄存器（高16位保留，低16为依次对应某个GPIO口的16个引脚）。对ODR赋值是一次操作16位的，也就是同时设置了16个引脚的输出电平；而GPIO_PIN是指某个端口的具体某一个引脚，是位操作，可以通过设置BSRR或BRR寄存器来设置某一特定引脚的输出电平，而保持其他引脚输出不变，速度快，效率高。具体可以看看stm32参考手册关于GPIO寄存器的说明。
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 宏定义地址，输出寄存器。 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 宏定义地址，输出寄存器。 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C宏定义地址，输出寄存器。 


#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 GPIO->IDR是32位的输入数据寄存器
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 宏定义地址，输入寄存器。 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 宏定义地址，输入寄存器。 

//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)//输出 典型的位操作定义
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)//输入 


#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)//输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)//输入 


#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)//输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)//输入 


#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)//输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)//输入 


#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)//输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)//输入


#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)//输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)//输入


#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)//输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)//输入

void NVIC_Configuration(void);//用于映射中断的处理函数, 

#endif
