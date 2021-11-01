#ifndef GLOBALS
#define GLOBALS

const int SERVO_DELAY = 9; // fixed servo delay
const int STEPPER_DELAY = 50;   // fixed stepper delay
const int STEPPER_HORIZONTAL_MOVE = 5; // horizontal move for the stepper (0.026mm)
const int GRADUAL_ACCELERATION_INDEX = 8; // this index affect the acceleration of the servo motor
const unsigned long DEBOUNCE_DELAY = 30; // delay for pressing the starter button
const int COIL_STARTER_POSITION = 1530;  // pos 0 of the coil
const int SERVO_ROTATION = 400; // 360° servo rotation
const int LAYER_TURNS = 436; // spire for each layer (LAYER_TURNS * 0.026 = coil_lenght)
const int COIL_LAYERS = 4; // layers of the coil (old 34 * 4)

#endif
