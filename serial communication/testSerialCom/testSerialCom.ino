
// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   Serial.println("hello world!");
//   delay(1000);
// }


int x;
void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
}
void loop() {
 if(Serial.available()){
  x = Serial.readString().toInt();
  Serial.print(x + 1);
 }
}
