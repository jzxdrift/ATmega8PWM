#include <avr/io.h>

void initADC(void)
{
	ADCSRA |= _BV(ADEN);					/*ADC enable*/
	ADCSRA |= _BV(ADPS1) | _BV(ADPS0);		/*8 prescaler*/
	
	ADMUX |= _BV(REFS0);					/*AVcc voltage reference*/
	ADMUX |= _BV(MUX0);						/*ADC1 channel*/
}

void startADC(void)
{
	ADCSRA |= _BV(ADSC);
}

uint16_t readADC(void)
{
	loop_until_bit_is_set(ADCSRA, ADIF);
	return ADC;
}