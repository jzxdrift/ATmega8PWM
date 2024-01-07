#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>

#define LONG_BOUNCE					      200
#define SHORT_BOUNCE				      35

#define NO_BUTTON					        (-1)
#define DUTY_CYCLE_INC_BUTTON		  0
#define DUTY_CYCLE_DEC_BUTTON		  1
#define FREQUENCY_INC_BUTTON		  2
#define FREQUENCY_DEC_BUTTON		  3

void initButtons(void);
int8_t buttonPressed(void);

#endif
