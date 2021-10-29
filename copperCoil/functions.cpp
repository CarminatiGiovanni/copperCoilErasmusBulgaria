#include "functions.h"

void rotateServo(int delays){
  for (int i = 0; i < SERVO_ROTATION; i++) pulseOutServo(LOW,delays);
}

void moveStepper(bool dir,int delays){
  for (int i = 0; i < STEPPER_HORIZONTAL_MOVE; i++) pulseOutStep(dir,delays); //0.026 mm
}

void starterPosition(){
  while(digitalRead(HOME) == LOW) pulseOutStep(HIGH,1000); // move the stepper back to point 0
  for (int i = 0; i < COIL_STARTER_POSITION; i++) pulseOutStep(LOW,1000); // starter position for the coil
  for (int i = 0; i < SERVO_ROTATION; i++) pulseOutServo(HIGH,1000); // 1 rotation of bottom servo
}
