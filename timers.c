#include <avr/io.h>
#include <avr/interrupt.h>

#include "seg7_display.h"

uint8_t timeElapsed = 0;

extern void clearDigits(void);
extern void showDigit(const uint8_t);

ISR(TIMER0_OVF_vect)
{
	extern uint8_t digits[];
	extern const uint8_t DIGITS_SIZE;
	
	static uint8_t digit = 0;
	
	if(digit > DIGITS_SIZE - 1)
		digit = 0;
	
	clearDigits();
	
	switch(digit)
	{
		case DIG_THOUSANDS:
			PORT_DIG_1_4 ^=	_BV(DIG_1);
			break;
		case DIG_HUNDREDS:
			PORT_DIG_1_4 ^= _BV(DIG_2);
			break;
		case DIG_TENS:
			PORT_DIG_1_4 ^= _BV(DIG_3);
			break;
		case DIG_ONES:
			PORT_DIG_1_4 ^= _BV(DIG_4);
			break;
	}
	
	showDigit(digits[digit]);
	++digit;
}

ISR(TIMER2_OVF_vect)
{
	++timeElapsed;
}

void initTimer0(void)
{
	TCCR0 |= _BV(CS01);		/*8 prescaler*/
	TIMSK |= _BV(TOIE0);	/*overflow interrupt enable*/
}

void startTimer0(void)
{
	TCNT0 = 0x00;
}

void initTimer2(void)
{
	TIMSK |= _BV(TOIE2);							/*overflow interrupt enable*/
	TCNT2 = 0x00;
}

void startTimer2(void)
{
	TCCR2 |= _BV(CS22) | _BV(CS21) | _BV(CS20);		/*1024 prescaler*/
}

void stopTimer2(void)
{
	TCCR2 &= ~(_BV(CS22) | _BV(CS21) | _BV(CS20));
	TCNT2 = 0x00;
	
	timeElapsed = 0;
}