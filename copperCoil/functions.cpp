#include "functions.h"

// this function rotate the coil of 360°
void rotateServo(int delays){ // 1st argument is the delay of the rotation
  for (int i = 0; i < SERVO_ROTATION; i++) pulseOutServo(LOW,delays); // a 360° rotation is made by SERVO_ROTATION pulseOut
}

// this function moves horizontally the stepper for the width of the copper wire 
void moveStepper(bool dir,int delays){ // dir -> LEFT or RIGHT move, delays -> delay for the pulseOut
  for (int i = 0; i < STEPPER_HORIZONTAL_MOVE; i++) pulseOutStep(dir,delays); // a horizzontal move is made by STEPPER_HORIZONTAL_MOVE pulseOut
}

// this function bring back the motors to the starter position
void starterPosition(){
  while(digitalRead(HOME) == LOW) pulseOutStep(HIGH,1000); // move the stepper back to point 0
  for (int i = 0; i < COIL_STARTER_POSITION; i++) pulseOutStep(LOW,1000); // starter position for the coil
  for (int i = 0; i < SERVO_ROTATION; i++) pulseOutServo(HIGH,1000); // 1 rotation of bottom servo
}
