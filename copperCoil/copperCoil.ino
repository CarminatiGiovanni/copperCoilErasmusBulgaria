#include "header.h"

bool lastButtonState = LOW; //old button state
bool reading = LOW; // read the value of the button
unsigned long lastDebounceTime = 0; // last time the button has been pressed
bool LR = LOW; //  stepper motor direction,  HIGH = right | LOW = left
unsigned long timeNow = 0; //used for the millis
String request;

void setup() {

  Serial.begin(115200); // begin the serial communication
  Serial.setTimeout(1); // set a timeout on the communication port
  
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

  if(Serial.available()){ // if data is written on serial
    request = Serial.readString(); // read as a string
    if(request == "consts")sendInformation(); // the request code "consts" send to the serial all the values of the consts of arduino
    else Serial.println("No action for this request"); // handle other requests
  }
  
  reading = digitalRead(BUTTON);  // read the button to start
  if (reading != lastButtonState) lastDebounceTime = millis(); // if the button change state the lastDebounceTime is resetted
  timeNow = millis(); // get the current time

  //18446744073709551615 is the maximum number for unsigned long, then millis() restart from 0
  //FIXME: the autonomy of the program is about 50days, then it gets stuck without restarting

  if (timeNow - lastDebounceTime > DEBOUNCE_DELAY && reading == HIGH) { //IF DEBOUNCE_DELAY has passed
    LR = LOW; //first go on right
    int speedModifier = 1;  // increment index of the delay of the speed
    int layerTurnsModifier = 0; // index to increment the turns for a layer of the coil
    for(int layer = 0; layer < COIL_LAYERS; layer++){
      layerTurnsModifier = calculateTheLayerTurnsModifier(layer); // if layer % 4 == 0 -> modifier = 1
      for(int turn = 0; turn < LAYER_TURNS + layerTurnsModifier; turn++){ // every 4 layers the coil has 1 turn more
        speedModifier = calculateTheSpeedModifier(layer,turn); // if is the first layer the speed of the rotation gradually decrease to speedModifier = 1
        rotateServo(SERVO_DELAY * speedModifier); // rotate the coil
        moveStepper(LR, STEPPER_DELAY * speedModifier); // horizontal stepper move for the next coil turn
      }
      LR = !LR; // invert the direction of the stepper
    }
    starterPosition(); // after the cicle of the coil, the motors moves to the starter position
  }
  lastButtonState = reading; // update the last button state
}
