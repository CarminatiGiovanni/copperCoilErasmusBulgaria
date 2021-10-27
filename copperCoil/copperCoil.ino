int HOME=9;
int BUTTON=8;
int DIRSTEP=7;
int PULSTEP=6;
int PULSERVO=5; //define Pulse pin
int DIRSERVO=4; //define Direction pin
int ENASERVO=3; //define Enable Pin
int val = 0;
int buttonState; 
int lastButtonState = LOW; 
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 30;




void setup() 
{
{
  pinMode (DIRSTEP, OUTPUT);
  pinMode (PULSTEP, OUTPUT);
  pinMode (PULSERVO, OUTPUT);
  pinMode (DIRSERVO, OUTPUT);
  pinMode (ENASERVO, OUTPUT);
  pinMode (HOME, INPUT);
  pinMode (BUTTON, INPUT);
}
{
  for (int i=0; i<30000; i++)
  {val = digitalRead(HOME);
  if (val == LOW)
  
                     {digitalWrite(DIRSTEP,HIGH);
                      digitalWrite(PULSTEP,HIGH);
                      delay(1);
                      digitalWrite(PULSTEP,LOW);
                      delay(1);}}
}
{
         for (int i=0; i<1530; i++)
          {digitalWrite(DIRSTEP,LOW);
           digitalWrite(PULSTEP,HIGH);
           delay(1);
           digitalWrite(PULSTEP,LOW);
           delay(1);}
           
}
{                            for (int i=0; i<400; i++)
                            {digitalWrite(DIRSERVO,HIGH);
                             digitalWrite(ENASERVO,HIGH);
                             digitalWrite(PULSERVO,HIGH);
                             delayMicroseconds(1000);
                             digitalWrite(PULSERVO,LOW);
                             delayMicroseconds(1000);}
}
}
void loop() 

{ 
  int reading = digitalRead(BUTTON); 
  if (reading != lastButtonState)
    {
      lastDebounceTime = millis();
    }

  if ((unsigned long)(millis()-lastDebounceTime)>debounceDelay)
  {
    if (reading != buttonState) 
    {
      buttonState = reading;
      if (buttonState == HIGH)
      {
                         
                         
                         
                           
                            {for (int i=0; i<34; i++)
                          
                            
                           {
                            {for (int i=0; i<436; i++)
                            {
                            {for (int i=0; i<400; i++)  
                            {digitalWrite(DIRSERVO,LOW);
                             digitalWrite(ENASERVO,HIGH);
                             digitalWrite(PULSERVO,HIGH);
                             delayMicroseconds(9);
                             digitalWrite(PULSERVO,LOW);
                             delayMicroseconds(9);}}
                            for (int i=0; i<5; i++)
                            {digitalWrite(DIRSTEP,LOW);
                             digitalWrite(PULSTEP,HIGH);
                             delayMicroseconds(50);
                             digitalWrite(PULSTEP,LOW);
                             delayMicroseconds(50);}}}
                             
                                      
                                    
                            {for (int i=0; i<436; i++)
                            {
                            {for (int i=0; i<400; i++)  
                            {digitalWrite(DIRSERVO,LOW);
                             digitalWrite(ENASERVO,HIGH);
                             digitalWrite(PULSERVO,HIGH);
                             delayMicroseconds(9);
                             digitalWrite(PULSERVO,LOW);
                             delayMicroseconds(9);}}
                             for (int i=0; i<5; i++)
                            {digitalWrite(DIRSTEP,HIGH);
                             digitalWrite(PULSTEP,HIGH);
                             delayMicroseconds(50);
                             digitalWrite(PULSTEP,LOW);
                             delayMicroseconds(50);}}}
                             
                                      
                            
                           
                            {for (int i=0; i<436; i++)
                            {
                            {for (int i=0; i<400; i++)  
                            {digitalWrite(DIRSERVO,LOW);
                             digitalWrite(ENASERVO,HIGH);
                             digitalWrite(PULSERVO,HIGH);
                             delayMicroseconds(9);
                             digitalWrite(PULSERVO,LOW);
                             delayMicroseconds(9);}}
                            for (int i=0; i<5; i++)
                            {digitalWrite(DIRSTEP,LOW);
                             digitalWrite(PULSTEP,HIGH);
                             delayMicroseconds(50);
                             digitalWrite(PULSTEP,LOW);
                             delayMicroseconds(50);}}}
                             
                                      
                                     
                            {for (int i=0; i<437; i++)
                            {
                            {for (int i=0; i<400; i++)  
                            {digitalWrite(DIRSERVO,LOW);
                             digitalWrite(ENASERVO,HIGH);
                             digitalWrite(PULSERVO,HIGH);
                             delayMicroseconds(9);
                             digitalWrite(PULSERVO,LOW);
                             delayMicroseconds(9);}}
                             for (int i=0; i<5; i++)
                            {digitalWrite(DIRSTEP,HIGH);
                             digitalWrite(PULSTEP,HIGH);
                             delayMicroseconds(50);
                             digitalWrite(PULSTEP,LOW);
                             delayMicroseconds(50);}}}
                           }
                           }         

      }
    }
  }
  lastButtonState = reading; 
}
