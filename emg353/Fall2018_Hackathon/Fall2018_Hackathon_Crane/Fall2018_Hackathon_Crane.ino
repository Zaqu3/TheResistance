#include <Servo.h>

// Servos
Servo xAxisServo;     //directional
Servo elevationServo; //directional

// Pin values
#define xPot A0
#define elevPot A1
#define ISRPin 3
#define ledPin 13
#define buzzPin 5
#define stopButton 2

// Servo Values
int xServoVal;
int elevServoVal;

// Buzzer values
volatile bool enableState;
volatile bool ledOn;
volatile int buzzCount;

int prevMillis;

void setup()
{
  xAxisServo.attach(9);
  elevationServo.attach(10);
  
  pinMode(xPot, INPUT);
  pinMode(elevPot, INPUT);
  pinMode(ISRPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); //Start out off
  
  attachInterrupt(digitalPinToInterrupt(ISRPin), buttonRising, RISING);
  OCR0A = 0x7F;
  TIMSK0 |= _BV(OCIE0A);
}

void loop()
{
  if (enableState)
  {
    while(buzzCount < 5)
    {
      tone(buzzPin, 523);
      delay(50);
      noTone(buzzPin);
      delay(50);
      buzzCount ++; 
    }
    xServoVal = map(analogRead(xPot), 0, 1023, 180, 0);
    elevServoVal = map(analogRead(elevPot), 0, 1023, 180, 0);
    elevationServo.write(elevServoVal);
    xAxisServo.write(xServoVal);

    if (digitalRead(stopButton) == HIGH)
      enableState = false;
  }
}

SIGNAL(TIMER0_COMPA_vect)
{
  if (enableState)
  {
    unsigned long currentMillis = millis();
    if (currentMillis % 500 == 0)
    {
      ledOn =! ledOn;
      if (ledOn)
        digitalWrite(ledPin, HIGH);
      else
        digitalWrite(ledPin, LOW);
    }
  }
  if (!enableState)
    digitalWrite(ledPin, LOW);
}

void buttonRising()
{
  enableState = true;
  buzzCount = 0;
}
