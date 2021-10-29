#include "pulseOut.h"

void pulseOutStep(bool dir,int delayMicro){
  digitalWrite(DIRSTEP, dir);
  digitalWrite(PULSTEP, HIGH);
  delayMicroseconds(delayMicro);
  digitalWrite(PULSTEP, LOW);
  delayMicroseconds(delayMicro);
}

void pulseOutServo(bool dir,int delayMicro){
  digitalWrite(DIRSERVO, dir);
  digitalWrite(ENASERVO, HIGH);
  digitalWrite(PULSERVO, HIGH);
  delayMicroseconds(delayMicro);
  digitalWrite(PULSERVO, LOW);
  delayMicroseconds(delayMicro);
}
