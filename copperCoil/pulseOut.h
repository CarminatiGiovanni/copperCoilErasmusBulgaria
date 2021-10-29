#ifndef PULSE_OUT_H
#define PULSE_OUT_H
//#include <Arduino.h>
#include "header.h"

void pulseOutServo(bool dir,int delayMicro);
void pulseOutStep(bool dir,int delayMicro);

#endif
