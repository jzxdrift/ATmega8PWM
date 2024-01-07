#include "adc.h"
#include "buttons.h"
#include "encoder.h"
#include "local_interrupts.h"
#include "pwm.h"
#include "seg7_display.h"
#include "timers.h"

int main(void)
{
	initADC();
	initButtons();
	initEncoder();
	initPWM();
	initSegDisplay();
	initTimer0();
	initTimer2();
	
	initExternalInterrupts();
	enableGlobalInterrupts();
	
	startTimer0();
	
#ifdef ADC_PWM
	int8_t button = NO_BUTTON;
#endif
	
	while(1)
	{
#ifdef ADC_PWM
		startADC();
		setDutyCycle(readADC());
		fillDigits(getDutyCycle());
		
		while((button = buttonPressed()) != NO_BUTTON)
		{
			startTimer2();
			adjustPWM(button);
		}
		stopTimer2();
#endif
		
		fillDigits(getDutyCycle());
	}
}
