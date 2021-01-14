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

#define SLAVEADDR 0x68

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
	I2C1->CR1|=0x8000; //I2C1 is connected to PB and PB9, so I2C1 is software reset
	
	I2C1->CR2|=0x10;  //I2C1 is Frequency is set at 10MHz, [XTAL 10MHz]
	
	I2C1->CCR = 80;  //standard mode 100kHz clock
	
	I2C1->TRISE = 17; //Max Trigger Rise edge duration
	
	I2C1->CR1|=0x1; //Enable Peripharals
}


int i2cdata(char saeaddr, char mtraddr, char *data){
	
	volatile int temp;
	
	while(I2C1->SR2 & 2){    //If bus is busy, enters the loop	
		
		I2C1->CR1 |= 0x100;    //Start condition for I2C
	}
	//while(!(I2C1->SR1 & 1)){}		//Start Master mode udemy
	while(I2C1->SR1 ==0){};		//Start Master mode balaji
		
	I2C1->DR = saeaddr <<1;		//slave address is written in Data register 
	while(!(I2C1->SR1 & 2)){}; 	//0-No end of address transmission, 1-End of address tranmission
	
	temp=I2C1->SR2;  					//Copy Status register value to temp variable
		
	while(!(I2C1->SR1 & 80)){};		//wait till data register is empty| 0-not empty | 1-Empty
	/*
1. I2C1->SR1 is 0, so while(!(I2C1->SR1 & 80)) = 1, enters loop
2. after few times I2C1->SR1 is 1, so while(!(I2C1->SR1 & 80)) = 0, exits loop
  */		
}