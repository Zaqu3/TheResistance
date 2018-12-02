#include <Servo.h>

Servo testServo;

const int buzzer = 2;

int servoVal;

volatile bool beep;

void setup()
{
  testServo.attach(3);
  attachInterrupt(1,servoChange,CHANGE);
}

void loop()
{
  servoVal = map(digitalRead(servoVal), 0, 1023, 80, 100);
  if (beep)
    tone(buzzer,440);
  else
    noTone(buzzer);
}

void servoChange()
{
  if (servoVal == 90)
    beep = false;
  else
    beep = true;
}
