/*
Master Device -> STM32F446RE
Slave Device -> DS1307
Since It is a RTC, it got SEC
min, hour, day, month Year,

we are going to read the sec
and use that to toggle the LED

PIN's used
SCL-PB8
SDA-PB9
*/
#include "stm32f4xx.h"                  // Device header

int main(void){
	
}

void i2cInit(void){
	//GPIO config
	RCC->AHB1ENR|=0x2; //Enable BUS for GPIOB as PB8 and PB9 are GPIOB
	RCC->APB1ENR|=0x200000; //Enable I2C1 as PB8 and PB9 are connected
	
	GPIOB->MODER|=0xA0000; //Enable Alternate Mode at PB8 and PB9
	
	GPIOB->AFR[1]|=0x44;   //Enable I2C as alternate function for PB8 and PB9
	
	GPIOB->OTYPER|=0x300;  //Making Both as Open-Drain (HIGH-> 0v; LOW-> Floating value)
	
	GPIOB->PUPDR|=0x50000; //Pull-up PB8 and PB9
	//I2C config
	
}