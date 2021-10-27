int HOME = 9;
int BUTTON = 8;
int DIRSTEP = 7;
int PULSTEP = 6;
int PULSERVO = 5; //define Pulse pin
int DIRSERVO = 4; //define Direction pin
int ENASERVO = 3; //define Enable Pin
int val = 0;
int buttonState;
int lastButtonState = LOW;
const int delayServo = 9;
const int delayStep = 50;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 30;

void setup() {
  {
    pinMode(DIRSTEP, OUTPUT);
    pinMode(PULSTEP, OUTPUT);
    pinMode(PULSERVO, OUTPUT);
    pinMode(DIRSERVO, OUTPUT);
    pinMode(ENASERVO, OUTPUT);
    pinMode(HOME, INPUT);
    pinMode(BUTTON, INPUT);
  } {
    for (int i = 0; i < 30000; i++) {
      val = digitalRead(HOME);
      if (val == LOW)

      {
        digitalWrite(DIRSTEP, HIGH);
        digitalWrite(PULSTEP, HIGH);
        delay(1);
        digitalWrite(PULSTEP, LOW);
        delay(1);
      }
    }
  } {
    for (int i = 0; i < 1530; i++) { //starter position for the coil
      digitalWrite(DIRSTEP, LOW);
      digitalWrite(PULSTEP, HIGH);
      delay(1);
      digitalWrite(PULSTEP, LOW);
      delay(1);
    }

  } {
    for (int i = 0; i < 400; i++) { //400 servo revolution (bottom)
      digitalWrite(DIRSERVO, HIGH);
      digitalWrite(ENASERVO, HIGH);
      digitalWrite(PULSERVO, HIGH);
      delayMicroseconds(1000);
      digitalWrite(PULSERVO, LOW);
      delayMicroseconds(1000);
    }
  }
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
              for (int g = 436; g > 0; g--) { //layer length

                if(layer == 0){ //SMOOOTH ACCELLERATION
                  

                  for (int i = 0; i < 400; i++) { //1 turn revolutionTime = delayServo * 2 * 400 * (g / 8)
                      digitalWrite(DIRSERVO, LOW);
                      digitalWrite(ENASERVO, HIGH);
                      digitalWrite(PULSERVO, HIGH);
                      delayMicroseconds(delayServo * int(g / 8));
                      digitalWrite(PULSERVO, LOW);
                      delayMicroseconds(delayServo* int(g / 8));
                    }

                  for (int i = 0; i < 5; i++) { //0.026 mm
                    digitalWrite(DIRSTEP, LOW); //DX
                    digitalWrite(PULSTEP, HIGH);
                    delayMicroseconds(delayStep* int(g / 8));
                    digitalWrite(PULSTEP, LOW);
                    delayMicroseconds(delayStep* int(g / 8));
                  }
                }

                else{
                    {
                    for (int i = 0; i < 400; i++) {
                      digitalWrite(DIRSERVO, LOW);
                      digitalWrite(ENASERVO, HIGH);
                      digitalWrite(PULSERVO, HIGH);
                      delayMicroseconds(9);
                      digitalWrite(PULSERVO, LOW);
                      delayMicroseconds(9);
                    }
                  }
                  for (int i = 0; i < 5; i++) { //0.026 mm
                    digitalWrite(DIRSTEP, LOW); //DX
                    digitalWrite(PULSTEP, HIGH);
                    delayMicroseconds(50);
                    digitalWrite(PULSTEP, LOW);
                    delayMicroseconds(50);
                  }

                }
              }
            }
            //LEFT
            {
              for (int i = 0; i < 436; i++) {
                {
                  for (int i = 0; i < 400; i++) {
                    digitalWrite(DIRSERVO, LOW);
                    digitalWrite(ENASERVO, HIGH);
                    digitalWrite(PULSERVO, HIGH);
                    delayMicroseconds(9);
                    digitalWrite(PULSERVO, LOW);
                    delayMicroseconds(9);
                  }
                }
                for (int i = 0; i < 5; i++) {
                  digitalWrite(DIRSTEP, HIGH); //SX
                  digitalWrite(PULSTEP, HIGH);
                  delayMicroseconds(50);
                  digitalWrite(PULSTEP, LOW);
                  delayMicroseconds(50);
                }
              }
            }
            //RIGHT
            {
              for (int i = 0; i < 436; i++) {
                {
                  for (int i = 0; i < 400; i++) {
                    digitalWrite(DIRSERVO, LOW);
                    digitalWrite(ENASERVO, HIGH);
                    digitalWrite(PULSERVO, HIGH);
                    delayMicroseconds(9);
                    digitalWrite(PULSERVO, LOW);
                    delayMicroseconds(9);
                  }
                }
                for (int i = 0; i < 5; i++) {
                  digitalWrite(DIRSTEP, LOW);
                  digitalWrite(PULSTEP, HIGH);
                  delayMicroseconds(50);
                  digitalWrite(PULSTEP, LOW);
                  delayMicroseconds(50);
                }
              }
            }
            //LEFT + 1 TURN
            {
              for (int i = 0; i < 437; i++) {
                {
                  for (int i = 0; i < 400; i++) {
                    digitalWrite(DIRSERVO, LOW);
                    digitalWrite(ENASERVO, HIGH);
                    digitalWrite(PULSERVO, HIGH);
                    delayMicroseconds(9);
                    digitalWrite(PULSERVO, LOW);
                    delayMicroseconds(9);
                  }
                }
                for (int i = 0; i < 5; i++) {
                  digitalWrite(DIRSTEP, HIGH);
                  digitalWrite(PULSTEP, HIGH);
                  delayMicroseconds(50);
                  digitalWrite(PULSTEP, LOW);
                  delayMicroseconds(50);
                }
              }
            }
          }
        }

      }
    }
  }
  lastButtonState = reading;
}