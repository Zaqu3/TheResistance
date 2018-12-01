#include <Servo.h>

const int xAxisPot = A0;
const int yAxisPot = A1;
const int grabPot = A2;
const int extensionPot = A3;

Servo xAxisServo;     //directional
Servo yAxisServo;     //continuous
Servo grabServo;      //directional
Servo extensionServo; //directional

const int buzzer = 6;
const int freq = 440;

int xVal;
int yVal;
int grabVal;
int extensionVal;

volatile bool beep;

void setup()
{
  pinMode(xAxisPot, INPUT);
  pinMode(yAxisPot, INPUT);
  pinMode(grabPot, INPUT);
  pinMode(extensionPot, INPUT);
  
  xAxisServo.attach(2);
  yAxisServo.attach(3);
  grabServo.attach(4);
  extensionServo.attach(5);

  attachInterrupt(digitalPinToInterrupt(yAxisPot),yChange,CHANGE);
  OCR0A = 0x7F;
  TIMSK0 |= _BV(OCIE0A);
}

void loop()
{
  xVal = map(analogRead(xAxisPot), 0, 1023, 0, 180);
  yVal = map(analogRead(yAxisPot), 0, 1023, 80, 100);
  grabVal = map(analogRead(grabPot), 0, 1023, 0, 180);
  extensionVal = map(analogRead(extensionPot), 0, 1023, 0, 180);

  xAxisServo.write(xVal);
  yAxisServo.write(yVal);
  grabServo.write(grabVal);
  extensionServo.write(extensionVal);
}

SIGNAL(TIMER0_COMPA_vect)
{
  if (beep)
    tone(buzzer, freq, 250);
}

void yChange()
{
  if (analogRead(yAxisPot) == 90)
    beep = false;
  else
    beep = true;
}
