/*
LCD display  is used in 4bit mode

PC4-PC7 -> Data line
PB5 -> RS
PB7 -> EN
GND -> RW

*/
#include "stm32f4xx.h"                  // Device header

int  main(void){
	
	
}

void GpioInit(void){
	RCC->AHB1ENR|=
}