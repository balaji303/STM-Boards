/*
Led Blink using General Purpose Timer Output Capture in TIM2
*/
#include "stm32f4xx.h"                  // Device header

int main(void){
	RCC->AHB1ENR |=0x1;
	GPIOA->MODER |=0x800;
	GPIOA->AFR[0]|=0x100000;
	
	RCC->APB1ENR |=0X1;
	TIM2->PSC  =1600-1;
	TIM2->ARR  =10000-1;
	TIM2->CCMR1 =0x30;
	TIM2->CCR1 = 0;
	TIM2->CCER |=1; 
	TIM2->CNT  = 0;
	TIM2->CR1  = 1;
	
	while(1){}
}

