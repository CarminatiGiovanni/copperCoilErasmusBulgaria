#include "functions.h"

// this function rotate the coil of 360°
void rotateServo(int delays){ // 1st argument is the delay of the rotation
  for (int i = 0; i < SERVO_ROTATION; i++) pulseOutServo(HIGH,delays); // a 360° rotation is made by SERVO_ROTATION pulseOut LOW = clockwise | HIGH counterclockwise
}

// this function moves horizontally the stepper for the width of the copper wire 
void moveStepper(bool dir,int delays){ // dir -> LEFT or RIGHT move, delays -> delay for the pulseOut
  for (int i = 0; i < STEPPER_HORIZONTAL_MOVE; i++) pulseOutStep(dir,delays); // a horizzontal move is made by STEPPER_HORIZONTAL_MOVE pulseOut
}

// this function bring back the motors to the starter position
void starterPosition(){
  int n = 0; // if the machine is not connect to the power, after 30000 steps back the program will start
  while(digitalRead(HOME) == LOW && n < 30000) {pulseOutStep(HIGH,1000);n++;} // move the stepper back to point 0
  for (int i = 0; i < COIL_STARTER_POSITION; i++) pulseOutStep(LOW,1000); // starter position for the coil
  for (int i = 0; i < SERVO_ROTATION; i++) pulseOutServo(HIGH,1000); // 1 rotation of bottom servo
}

// it prints on console the constants as json string
void sendInformation(){
  String info =   
"{\"SERVO_DELAY\":" + String(SERVO_DELAY) +
",\"STEPPER_DELAY\":" + String(STEPPER_DELAY)+
",\"STEPPER_HORIZONTAL_MOVE\":" + String(STEPPER_HORIZONTAL_MOVE) +
",\"GRADUAL_INDEX\":" + String(GRADUAL_INDEX)+
",\"DEBOUNCE_DELAY\":" + String(DEBOUNCE_DELAY)+
",\"COIL_STARTER_POSITION\":" + String(COIL_STARTER_POSITION)+
",\"SERVO_ROTATION\":" + String(SERVO_ROTATION)+
",\"LAYER_TURNS\":" + String(LAYER_TURNS)+
",\"COIL_LAYERS\":" + String(COIL_LAYERS) + "}";
  Serial.println(info);
}
