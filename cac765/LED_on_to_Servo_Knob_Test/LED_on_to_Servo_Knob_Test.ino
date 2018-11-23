// initialize variables and libraries
#include <Servo.h>

const int potPin = 0;
const int ledPin = 13;
int prev_val;
int val;

Servo motor;

void setup() {
  // put your setup code here, to run once:
  motor.attach(9);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  prev_val = val;
  val = map(analogRead(potPin), 0, 1023, 0, 180);
  if( prev_val != val)
  {
   digitalWrite(ledPin, HIGH);
  }
  motor.write(val);
  delay(15);
  digitalWrite(ledPin, LOW);
}
