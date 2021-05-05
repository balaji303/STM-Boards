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
	Timer raises a flag and the counter rstarts automatically when counter value reaches the value in the auto-reload register. The counter is an up counter by default but can also be configured to be an down counter.

Timer Prescalar Register (TIMx_PSC)
	The prescalar slows down the counting speed of the timer by dividing the input clock of the timer.

