#ifndef PULSE_OUT_H
#define PULSE_OUT_H
#include "header.h"

/****** pulseOutServo ********************
 * pulse out for the servo move
 * ARGS:
 *  dir -> the direction of the rotation of the servo (HIGH | LOW)
 *  delayMicro -> delay of the pulse in microseconds
 ****************************************/
void pulseOutServo(bool dir,int delayMicro);

/****** pulseOutServo ********************
 * pulse out for the stepper move
 * ARGS:
 *  dir -> the direction of the rotation of the stepper (HIGH | LOW) [left,right]
 *  delayMicro -> delay of the pulse in microseconds
 ****************************************/
void pulseOutStep(bool dir,int delayMicro);

#endif
