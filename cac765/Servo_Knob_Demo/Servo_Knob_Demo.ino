#include <Servo.h>

const int potPin = 0;
int val;
Servo motor;

void setup() {
  // put your setup code here, to run once:
 motor.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
 val = map(analogRead(potPin), 0, 1023, 0, 180);
 motor.write(val);
}
