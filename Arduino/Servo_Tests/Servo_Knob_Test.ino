// initialize variables and library
#include <Servo.h>
Servo servo_1;
Servo servo_2;
const int potPin = 0;
int value;
int pos = 0;

// identify inputs and outputs and assign pins
void setup() {
  // put your setup code here, to run once:
  servo_1.attach(9);
  servo_2.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  // Servo_1 connnected to potentiometer
  value = analogRead(potPin);
  value = map(value, 0, 1023, 0, 180);
  servo_1.write(value);
  */
  /*
  // Servo_2 does a constant 180 degree sweep
   for(pos = 0; pos <= 180; pos++)
  {
    servo_2.write(pos);
    delay(10);
    value = analogRead(potPin);
    value = map(value, 0, 1023, 0, 180);
    servo_1.write(value);
  }
  for(pos = 180; pos > 0; pos--)
  {
    servo_2.write(pos);
    delay(10);
  }
  delay(100);
  */
}
