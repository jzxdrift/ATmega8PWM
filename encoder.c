#include <avr/io.h>
#include <avr/interrupt.h>

#include "pwm.h"

ISR(INT0_vect)
{
	if(bit_is_clear(PINC, PC0))
		setDutyCycle(getDutyCycle() + 1);
	else
		setDutyCycle(getDutyCycle() - 1);
}

ISR(INT1_vect)
{
	setDutyCycle(DEFAULT_DUTY_CYCLE);
}

void initEncoder(void)
{
	PORTD |= _BV(PD3) | _BV(PD2);		/*SW, CLK*/
	PORTC |= _BV(PC0);					/*DT*/
}