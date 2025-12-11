#include "TM4C123GH6PM.h"
#define SW1 (GPIOD->DATA & 0X40)

void delayMs(int n); /* function prototype for delay */

int main(void)
{
/* enable clock to GPIOF at clock gating register */

	SYSCTL->RCGCGPIO |= 0x28;

	
GPIOF->DIR = 0x04;
GPIOD->DIR=0X0;
	
	

GPIOF->DEN = 0X04;
GPIOD->DEN = 0X40;
	

GPIOD->PUR=0X40;


//GPIOD->LOCK = 0x4C4F434B;
////GPIOD->CR = 0X80;

	
	
	
	while(1)
	{
		if(!(GPIOD->DATA & 0X40))
		{
			GPIOF->DATA^=0X4;
			delayMs(1);
		}
		else
		{GPIOF->DATA=0X0;}			
	}

}


/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
	int i, j;
	for(i = 0 ; i< n; i++)
	for(j = 0; j < 3180; j++)
	{} /* do nothing for 1 ms */
}
/* This function is called by the startup assembly code to perform system specific initialization tasks. */
void SystemInit(void)
{
	/* Grant coprocessor access*/
	/* This is required since TM4C123G has a floating point coprocessor */
	SCB->CPACR |= 0x00F00000;
}
