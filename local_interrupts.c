#include <avr/io.h>
#include <avr/interrupt.h>

void initExternalInterrupts(void)
{
	MCUCR |= _BV(ISC11) | _BV(ISC01);		/*falling edge interrupts*/
	GICR |= _BV(INT1) | _BV(INT0);			/*enable interrupts*/
}

void enableGlobalInterrupts(void)
{
	sei();
}