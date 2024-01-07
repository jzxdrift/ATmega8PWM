#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "buttons.h"
#include "timers.h"
#include "pwm.h"

#define DUTY_FREQ_STEP		2
#define MAX_FREQ		0x270F

void initPWM(void)
{
	DDRB |= _BV(DDB1);			/*OC1A pin output*/
	
	TCCR1A |= _BV(COM1A1);			/*clear OC1A on Compare Match when up-counting, set OC1A when down-counting*/
	TCCR1B |= _BV(WGM13);			/*define PWM resolution by ICR1*/
	TCCR1B |= _BV(CS10);			/*no prescaler*/
	
	ICR1 = 0x03FF;				/*PWM resolution*/
	OCR1A = DEFAULT_DUTY_CYCLE;		/*duty cycle based on resolution*/
}

uint16_t getDutyCycle(void)
{
	return OCR1A;
}

uint16_t getFrequency(void)
{
	return ICR1;
}

void setDutyCycle(const int16_t dutyCycle)
{
	if(dutyCycle <= 0)
		OCR1A = 0x0000;
	else if(dutyCycle >= ICR1)
		OCR1A = ICR1;
	else
		OCR1A = dutyCycle;
}

void setFrequency(const int16_t frequency)
{
	if(frequency <= 0)
		ICR1 = 0x0000;
	else if(frequency >= MAX_FREQ)
		ICR1 = MAX_FREQ;
	else
		ICR1 = frequency;
}

void adjustPWM(const int8_t btn)
{
	extern uint8_t timeElapsed;
		
	switch(btn)
	{
		case DUTY_CYCLE_INC_BUTTON:
			setDutyCycle(getDutyCycle() + DUTY_FREQ_STEP);
			break;
		case DUTY_CYCLE_DEC_BUTTON:
			setDutyCycle(getDutyCycle() - DUTY_FREQ_STEP);
			break;
		case FREQUENCY_INC_BUTTON:
			setFrequency(getFrequency() - DUTY_FREQ_STEP);
			setDutyCycle(getDutyCycle() - DUTY_FREQ_STEP / 2);
			break;
		case FREQUENCY_DEC_BUTTON:
			setFrequency(getFrequency() + DUTY_FREQ_STEP);
			setDutyCycle(getDutyCycle() + DUTY_FREQ_STEP / 2);
			break;
	}
	
	timeElapsed > TIME ? _delay_ms(SHORT_BOUNCE) : _delay_ms(LONG_BOUNCE);
}
