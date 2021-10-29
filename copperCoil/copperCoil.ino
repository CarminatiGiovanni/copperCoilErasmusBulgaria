#define HOME  9 //pin sensor home
#define BUTTON  8 //pin start button
#define DIRSTEP 7 //pin for stepper for the Direction
#define PULSTEP  6 //pin for the stepper pulse
#define PULSERVO 5 //pin for servo pulse
#define DIRSERVO  4 //pin for servo Direction
#define ENASERVO 3 //define Enable Pin SERVO_DELAY

const int SERVO_DELAY = 9;
const int STEPPER_DELAY = 50;
const int STEPPER_HORIZONTAL_MOVE = 5;
const int GRADUAL_ACCELERATION_INDEX = 8;
const unsigned long DEBOUNCE_DELAY = 30;

const int COIL_STARTER_POSITION = 1530;
const int SERVO_ROTATION = 400;
const int LAYER_TURNS = 436;
const int COIL_LAYERS = 4; // change to 34 * 4

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

      if(layer % 4 == 0 && layer != 0) layerTurnsModifier = 1;
      else layerTurnsModifier = 0;

      for(int turn = 0; turn < LAYER_TURNS + layerTurnsModifier; turn++){

        if(layer == 0){
          speedModifier = int((LAYER_TURNS - turn) / GRADUAL_ACCELERATION_INDEX);
          if(speedModifier == 0) speedModifier = 1;
        } else speedModifier = 1;

        rotateServo(SERVO_DELAY * speedModifier);
        moveStepper(LR, STEPPER_DELAY * speedModifier);
        LR = !LR;
      }
    }
     starterPosition();
  }
  lastButtonState = reading;
}


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