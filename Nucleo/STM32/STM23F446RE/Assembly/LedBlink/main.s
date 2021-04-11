 ; This is a Assembly File
 ; |.text| means program callable by the C
 ; CODE means this is stored in RAM memory i.e, Programm memory 
 ; THUMB says the program is written in THUMB
 ;
				AREA |.text|,CODE, READONLY, ALIGN=2
				THUMB
				EXPORT Main
					
Main
		BL GPIO_Init
		
Loop
		BL Led_On
		B  Loop
		
GPIO_Init
		LDR R1, = RCC_AHB1ENR ;Manipulate this register
		LDR R0,[R1]           ;Stored that into another register
		ORR R0,R0,#0x1        ;Manipulate its value
		STR R0,[R1]           ;Store it back to the register
		
		LDR R1, =GPIOA_MODER
		LDR R0,[R1]
		ORR R0,R0,#0x400
		STR R0,[R1]
		
		LDR R1, =GPIOA_BSRR
		LDR R0,[R1]
		ORR R0,R0,#0x20
		STR R0,[R1]
		