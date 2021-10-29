#include "header.h"

bool lastButtonState = LOW; //old button state
bool reading = LOW, // read the value of the button
unsigned long lastDebounceTime = 0; // last time the button has been pressed
bool LR = LOW; //  stepper motor direction,  HIGH = right | LOW = left
unsigned long timeNow = 0; //used for the millis

void setup() {
  
  pinMode(DIRSTEP, OUTPUT);
  pinMode(PULSTEP, OUTPUT);
  pinMode(PULSERVO, OUTPUT);
  pinMode(DIRSERVO, OUTPUT);
  pinMode(ENASERVO, OUTPUT);
  pinMode(HOME, INPUT);
  pinMode(BUTTON, INPUT);

  starterPosition();  //more details in functions.h
}

void loop()
{
  reading = digitalRead(BUTTON);  // read the button to start
  if (reading != lastButtonState) lastDebounceTime = millis(); // if the button change state the lastDebounceTime is resetted
  timeNow = millis();

  //18446744073709551615 is the maximum number for unsigned long, then millis() restart from 0
  //FIXME: the autonomy of the program is about 50days, then it gets stuck without restarting

  if (timeNow - lastDebounceTime) > DEBOUNCE_DELAY) { //IF DEBOUNCE_DELAY has passed
    LR = LOW; //first go on right
    int speedModifier = 1;
    int layerTurnsModifier = 0;
    for(int layer = 0; layer < COIL_LAYERS; layer++){
      layerTurnsModifier = calculateTheLayerTurnsModifier(layer);
      for(int turn = 0; turn < LAYER_TURNS + layerTurnsModifier; turn++){
        speedModifier = calculateTheSpeedModifier(layer,turn);
        rotateServo(SERVO_DELAY * speedModifier);
        moveStepper(LR, STEPPER_DELAY * speedModifier);
        LR = !LR;
      }
    }
     starterPosition();
  }
  lastButtonState = reading;
}