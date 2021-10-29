#include "header.h"

int val = 0;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
bool LR = LOW; //  stepper motor direction,  HIGH = right | LOW = left

void setup() {
  
  pinMode(DIRSTEP, OUTPUT);
  pinMode(PULSTEP, OUTPUT);
  pinMode(PULSERVO, OUTPUT);
  pinMode(DIRSERVO, OUTPUT);
  pinMode(ENASERVO, OUTPUT);
  pinMode(HOME, INPUT);
  pinMode(BUTTON, INPUT);

  starterPosition();
}

void loop()
{
  int reading = digitalRead(BUTTON);
  if (reading != lastButtonState) lastDebounceTime = millis();

  if ((unsigned long)(millis() - lastDebounceTime) > DEBOUNCE_DELAY) { //IF DEBOUNCE_DELAY has passed
   
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