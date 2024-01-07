#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#define DEFAULT_DUTY_CYCLE	0x01FF

void initPWM(void);
uint16_t getDutyCycle(void);
uint16_t getFrequency(void);
void setDutyCycle(const int16_t);
void setFrequency(const int16_t);
void adjustPWM(const int8_t);

#endif