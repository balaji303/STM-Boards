/*
LED is connected to PC13
Port C PIN 13
PC13 is with AHB2
RCC->APB2ENR Clock enable register
GPIO Registers
    GPIOx_MODER - Mode registers (2bits of data) 
    GPIOx_ODR - Output Data register
*/
#include "stm32f10x.h"                  // Device header
void LedInit(void);
void LedGlow(void);
void DelayMs(int seconds);
int main(void){
  LedInit();
	while(1){
  LedGlow();		
	}
	return 0;
}

void LedInit(void){
  RCC->APB2ENR|=0x10; //Enable clock for Port C;
	GPIOC->CRH|=0x100000;//PC13 as output maxspeed 10Mhz
}
void LedGlow(void){
	GPIOC->BSRR|=0x2000; //Set 1 at PC13
	DelayMs(1000);
	GPIOC->BSRR|=0x20000000; //Set 0 at PC13
	DelayMs(1000);
}
void DelayMs(int seconds){
	for(;seconds>0;seconds--){
		for(int count1=0;count1<3000;count1++);
	}
}
