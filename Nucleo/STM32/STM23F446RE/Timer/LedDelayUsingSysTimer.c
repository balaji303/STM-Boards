/*
Blink the LED using the timer
LED->PA5
PA5->GPIOA
GPIOA->AHB1 bus
*/

#include "stm32f4xx.h"                  // Device header
#include "delay.h"
int main(void){
	RCC->AHB1ENR |=0x1;                   //GPIOA enable
	GPIOA->MODER |=0X400;                 //Enable PA5 output mode
	
	//SysTick timer
	SysTick->LOAD = 6400000-1;            //Changing  load value changes delay
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	
	while(1){
		if(SysTick->CTRL & 0x10000){
		GPIOA->ODR ^=0x20;
		}
	}
}

