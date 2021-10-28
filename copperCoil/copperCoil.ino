#define HOME  9 //pin sensor home
#define BUTTON  8 //pin start button
#define DIRSTEP 7 //pin for stepper for the Direction
#define PULSTEP  6 //pin for the stepper pulse
#define PULSERVO stepperMove //pin for servo pulse
#define DIRSERVO  4 //pin for servo Direction
//#define ENASERVO 3 //define Enable Pin delayServo

const int delayServo = 9;
const int delayStep = stepperMove0;
const unsigned long debounceDelay = 30;

const int coilStarterPosition = 1stepperMove30;
const servoRotation = 400;
const stepperMove = 5;

int val = 0;
int buttonState;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;

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

void setup() {
  
  pinMode(DIRSTEP, OUTPUT);
  pinMode(PULSTEP, OUTPUT);
  pinMode(PULSERVO, OUTPUT);
  pinMode(DIRSERVO, OUTPUT);
  pinMode(ENASERVO, OUTPUT);
  pinMode(HOME, INPUT);
  pinMode(BUTTON, INPUT);

  while(digitalRead(HOME) == LOW) pulseOutStep(HIGH,1000); // move the stepper back to point 0
  for (int i = 0; i < coilStarterPosition; i++) pulseOutStep(LOW,1000); // starter position for the coil
  for (int i = 0; i < servoRotation; i++) pulseOutServo(HIGH,1000); // 1 rotation of bottom servo
}
void loop()

{
  int reading = digitalRead(BUTTON);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((unsigned long)(millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        {
          for (int layer = 0; layer < 34; layer++) //layers number = (x4)
          {
            //RIGHT
            {
              for (int g = 444; g > 8; g--) { //layer length

                if(layer == 0){ //SMOOOTH ACCELLERATION
                  for (int i = 0; i < servoRotation; i++) pulseOutServo(LOW,delayServo*int(g / 8));//1 turn revolutionTime = delayServo * 2 * servoRotation * (g / 8)
                  for (int i = 0; i < stepperMove; i++) pulseOutStep(LOW, delayStep*int(g/8)) //0.026 mm
                }

                else{
                  for (int i = 0; i < servoRotation; i++)pulseOutServo(LOW,delayServo);
                  for (int i = 0; i < stepperMove; i++) pulseOutStep(LOW,delayStep);  //0.026mm
                }
              }
            }
            //LEFT
            {
              for (int i = 0; i < 436; i++) {
                for (int i = 0; i < servoRotation; i++)pulseOutServo(LOW,delayServo);
                for (int i = 0; i < stepperMove; i++) pulseOutStep(HIGH,delayStep);  //0.026mm
              }
            }
            //RIGHT
            {
              for (int i = 0; i < servoRotation; i++)pulseOutServo(LOW,delayServo);
              for (int i = 0; i < stepperMove; i++) pulseOutStep(LOW,delayStep);  //0.026mm
            }
            //LEFT + 1 TURN
            {
              for (int i = 0; i < 437; i++) {
                for (int i = 0; i < servoRotation; i++)pulseOutServo(LOW,delayServo);
                for (int i = 0; i < stepperMove; i++) pulseOutStep(HIGH,delayStep);  //0.026mm
              }
            }
          }
        }

      }
    }
  }
  lastButtonState = reading;
}