#include <avr/io.h>

#include "seg7_display.h"

#define DDR_SEG_A_D		DDRB
#define DDR_SEG_E_DP		DDRD

#define PORT_SEG_A_D		PORTB
#define PORT_SEG_E_DP		PORTD

#define DDR_DIG_1_4		DDRC

#define SEG_A			4
#define SEG_B			5
#define SEG_C			6
#define SEG_D			7
#define SEG_E			4
#define SEG_F			5
#define SEG_G			6
#define SEG_DP			7

uint8_t digits[] = { 0, 0, 0, 0 };
const uint8_t DIGITS_SIZE = sizeof digits / sizeof digits[0];

void clearDigits(void);

static void clearSegments(void);

void initSegDisplay(void)
{
	DDR_SEG_A_D |= _BV(SEG_D) | _BV(SEG_C) | _BV(SEG_B) | _BV(SEG_A);
	DDR_SEG_E_DP |= _BV(SEG_DP) | _BV(SEG_G) | _BV(SEG_F) | _BV(SEG_E);
	
	DDR_DIG_1_4 |= _BV(DIG_4) | _BV(DIG_3) | _BV(DIG_2) | _BV(DIG_1);
	clearDigits();
}

void clearDigits(void)
{
	PORT_DIG_1_4 |= _BV(DIG_4) | _BV(DIG_3) | _BV(DIG_2) | _BV(DIG_1);
}

void fillDigits(uint16_t num)
{
	for(int8_t i = DIGITS_SIZE - 1; i >= 0; --i)
	{
		digits[i] = num % 10;
		num /= 10;
	}
}

void showDigit(const uint8_t num)
{
	clearSegments();
	
	switch(num)
	{
		case 0:
			PORT_SEG_A_D |= _BV(SEG_D) | _BV(SEG_C) | _BV(SEG_B) | _BV(SEG_A);
			PORT_SEG_E_DP |= _BV(SEG_F) | _BV(SEG_E);
			break;
		case 1:
			PORT_SEG_A_D |= _BV(SEG_C) | _BV(SEG_B);
			break;
		case 2:
			PORT_SEG_A_D |= _BV(SEG_D) | _BV(SEG_B) | _BV(SEG_A);
			PORT_SEG_E_DP |= _BV(SEG_G) | _BV(SEG_E);
			break;
		case 3:
			PORT_SEG_A_D |= _BV(SEG_D) | _BV(SEG_C) | _BV(SEG_B) | _BV(SEG_A);
			PORT_SEG_E_DP |= _BV(SEG_G);
			break;
		case 4:
			PORT_SEG_A_D |= _BV(SEG_C) | _BV(SEG_B);
			PORT_SEG_E_DP |= _BV(SEG_G) | _BV(SEG_F);
			break;
		case 5:
			PORT_SEG_A_D |= _BV(SEG_D) | _BV(SEG_C) | _BV(SEG_A);
			PORT_SEG_E_DP |= _BV(SEG_G) | _BV(SEG_F);
			break;
		case 6:
			PORT_SEG_A_D |= _BV(SEG_D) | _BV(SEG_C) | _BV(SEG_A);
			PORT_SEG_E_DP |= _BV(SEG_G) | _BV(SEG_F) | _BV(SEG_E);
			break;
		case 7:
			PORT_SEG_A_D |= _BV(SEG_C) | _BV(SEG_B) | _BV(SEG_A);
			break;
		case 8:
			PORT_SEG_A_D |= _BV(SEG_D) | _BV(SEG_C) | _BV(SEG_B) | _BV(SEG_A);
			PORT_SEG_E_DP |= _BV(SEG_G) | _BV(SEG_F) | _BV(SEG_E);
			break;
		case 9:
			PORT_SEG_A_D |= _BV(SEG_D) | _BV(SEG_C) | _BV(SEG_B) | _BV(SEG_A);
			PORT_SEG_E_DP |= _BV(SEG_G) | _BV(SEG_F);
			break;
	}
}

static void clearSegments(void)
{
	PORT_SEG_A_D &= ~(_BV(SEG_D) | _BV(SEG_C) | _BV(SEG_B) | _BV(SEG_A));
	PORT_SEG_E_DP &= ~(_BV(SEG_DP) | _BV(SEG_G) | _BV(SEG_F) | _BV(SEG_E));
}
