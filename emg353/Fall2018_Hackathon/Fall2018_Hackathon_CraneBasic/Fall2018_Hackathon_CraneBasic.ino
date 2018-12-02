#include <Servo.h>

// Servos
Servo xAxisServo;     //directional
Servo elevationServo; //directional

// Potentiometers
const int xPot = A0;
const int elevPot = A1;

// Servo Values
int xServoVal;
int elevServoVal;

void setup()
{
  xAxisServo.attach(2);
  elevationServo.attach(3);
  
  pinMode(xPot, INPUT);
  pinMode(elevPot, INPUT);
}

void loop()
{
  xServoVal = map(analogRead(xPot), 0, 1023, 0, 180);
  elevServoVal = map(analogRead(elevPot), 0, 1023, 0, 180);
  
  elevationServo.write(elevServoVal);
  xAxisServo.write(xServoVal);
}
