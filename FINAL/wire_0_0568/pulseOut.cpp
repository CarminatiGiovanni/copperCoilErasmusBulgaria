#include "pulseOut.h"

// stepper pulse
void pulseOutStep(bool dir,int delayMicro){
  digitalWrite(DIRSTEP, dir); // set the direction
  digitalWrite(PULSTEP, HIGH); // start pulse
  delayMicroseconds(delayMicro); // delay
  digitalWrite(PULSTEP, LOW); // end pulse
  delayMicroseconds(delayMicro); // delay
}

// servo pulse
void pulseOutServo(bool dir,int delayMicro){
  digitalWrite(DIRSERVO, dir); // set the direction (clockwise | counterclockwise)
  digitalWrite(ENASERVO, HIGH); // enable the servo
  digitalWrite(PULSERVO, HIGH); // start pulse
  delayMicroseconds(delayMicro); // delay
  digitalWrite(PULSERVO, LOW); // end pulse
  delayMicroseconds(delayMicro); // delay
}
