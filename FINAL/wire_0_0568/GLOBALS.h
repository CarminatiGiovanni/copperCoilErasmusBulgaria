#ifndef GLOBALS
#define GLOBALS

const int SERVO_DELAY = 9; // fixed servo delay
const int STEPPER_DELAY = 50;   // fixed stepper delay
const int GRADUAL_INDEX = 16; // this index affect the acceleration and deceleration of the servo motor
const unsigned long DEBOUNCE_DELAY = 30; // delay for pressing the starter button
const int COIL_STARTER_POSITION = 1480;  // pos 0 of the coil
const int SERVO_ROTATION = 400; // 360° servo rotation


/*
  CALCULATION: 
  WIRINGS = 13100
  L = length of the coil = 15.5mm
  W = size of the wire = 0.0056
  SERVO_H_ROTATION = number of tiks for the h_servo rotation = 6400 tiks
  C = 45mm (3mm * 15) [2P] = perimeter of 1 full rotation
  H_step1 = C / SERVO_H_ROTATION = 0.007 = horizontal move for each step
  STEPPER_HORIZONTAL_MOVE = W / H_step1
  LAYER_TURNS = L / W
  COIL_LAYERS = WIRINGS / LAYER_TURNS

  
*/
// VALUES TO CHANGE
const int LAYER_TURNS = 273;
const int COIL_LAYERS = 48 + 2;
const int STEPPER_HORIZONTAL_MOVE = 8;
#endif
