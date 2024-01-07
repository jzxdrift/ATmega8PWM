#include <avr/io.h>

#include "buttons.h"

void initButtons(void)
{
	PORTB |= _BV(PB3) | _BV(PB2);
	PORTD |= _BV(PD1) | _BV(PD0);
}

int8_t buttonPressed(void)
{
	if(bit_is_clear(PIND, DUTY_CYCLE_INC_BUTTON))
		return DUTY_CYCLE_INC_BUTTON;
	
	if(bit_is_clear(PIND, DUTY_CYCLE_DEC_BUTTON))
		return DUTY_CYCLE_DEC_BUTTON;
	
	if(bit_is_clear(PINB, FREQUENCY_INC_BUTTON))
		return FREQUENCY_INC_BUTTON;
	
	if(bit_is_clear(PINB, FREQUENCY_DEC_BUTTON))
		return FREQUENCY_DEC_BUTTON;
	
	return NO_BUTTON;
}
