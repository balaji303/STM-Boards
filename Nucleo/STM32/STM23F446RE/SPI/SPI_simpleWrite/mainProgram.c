/*
SPI write fundation program

PA7-SPI1_MOSI
PA6-SPI1_MISO
PA5-SPI1_SCK
PA4-SPI1_NSS

*/
#include "stm32f4xx.h"                  // Device header

int main(void){
	
	
}

void  spiInit(void){
	RCC->AHB1ENR|=1; //Enable clock for port A
	RCC->APB2ENR|=0x1000; //Enable clock for SPI1
	
	
	
	
}

