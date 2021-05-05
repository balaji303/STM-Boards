Systick Current Value Register (STCVR)
	This register contains the current count value

Systick Control & Status Register (STCSR)
	This register allows us to configure the system clock source, enable/disable interrupts and enable/disable the systick counter

Systick Reload Value Register (STRVR)
	This is where the intital value is placed
/**************************************/

Timer Count Register (TIMx_CNT)
	Shows the current counter value. Size could be 32-ibt or 16-bit depending on timer module used.

Timer Auto-Reload Register (TIMx_ARR)
	Timer raises a flag and the counter rstarts automatically when counter value reaches the value in the auto-reload register. The counter is an up counter by default but can also be configured to be an down counter.TIM2->ARR = 10000;

Timer Prescalar Register (TIMx_PSC)
	The prescalar slows down the counting speed of the timer by dividing the input clock of the timer. TIM2->PSC = 1600-1;

Timer Control Register 1 (TIMx_CR1)
	The Timmer Enabling and Disabling register. TIM2->CR1 = 1;

Timer Control Register 2 (ADCx_CR2)
	Enable/disable the ADC
ADC1->CR2 = 1;

Timer Status Register (TIMx_SR)
	Checking, setting and clearing the flags of the timer.
TIM2->SR & 1; //Check update interrupt flag
TIM2->SR&= ~1; //Clear the interrupt flag

Capture Compare Register (CCR1, CCR2, CCR4, CCR3)
	One capture/compare register for each of the 4 channels
timestamp = TIM2->CCR1; //read capture value

Capture Compare Mode Register 1(CCMR1)
	Configure capture/compare functinality for CH1 and CH2
Capture Compare Mode Register 2(CCMR2)
	Configure capture compare functinality for CH3 and CH4
TIM2->CCMR1 = 0x41; //Set CH1 to capture at every edge

Capture Compare Enable  Register (CCER)
	Used to enable any of  the timer channels either as input capture or output compare
TIM2->CCER = 1; //Enable CH1



/**************************************/

Update Event = (Timer clock)/((Prescalar+1)(Period+1))

Example:

Timer Clock = APB1 clock = 48MHz
Prescalar     = TIM_PSC   = 47999+1
Period         = TIM_ARR   = 499+1

UpdateEvent = 0.5s Which means interrupt occurs twice for every second.

/**************************************/
