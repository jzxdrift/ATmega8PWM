#ifndef SEG7_DISPLAY_H
#define SEG7_DISPLAY_H

#include <stdint.h>

#define PORT_DIG_1_4	PORTC
	  
#define DIG_1			2
#define DIG_2			3
#define DIG_3			4
#define DIG_4			5

#define DIG_THOUSANDS	0
#define DIG_HUNDREDS	1
#define DIG_TENS		2
#define DIG_ONES		3

void initSegDisplay(void);
void fillDigits(uint16_t);

#endif