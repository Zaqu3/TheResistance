#include <Servo.h>

// Declare the triggers
Servo servoTrigger;
Servo servoX;
Servo servoY;

// The zero values for the continuous servos
int servoXZero = 96;
int servoTriggerZero = 91;

// Shit that does some other shit
const int buttonPin = 3;
const int potPinX = 0;
const int potPinY = 1;
int buttonState = LOW;
int potPinXVal;
int potPinYVal;

// setup
void setup() {
  // sets the servos to pin numbers
  servoTrigger.attach(11);
  servoX.attach(9);
  servoY.attach(10);

  //Sets the button to be an input
  pinMode(buttonPin, INPUT);
  
  //for debug
  //Serial.begin(9600);
  
  // Sets the trigger to not moving
  servoTrigger.write(91);
  }

// Does the stuff forever
void loop() {
  // Delay time for the trigger
  int delay_time = 400;
  
  // Reads the button state
  int buttonState = digitalRead(buttonPin);

  // Make code easy
  int valX = analogRead(potPinX);
  int valY = analogRead(potPinY);

  // Maps the correct values for the potentiometers
  valX = map(analogRead(potPinX), 0, 1023, 91, 101);
  valY = map(analogRead(potPinY), 0, 1023, 0, 180);
  
  // Give control to the dank knobs
  servoX.write(valX);
  servoY.write(valY);

  // Fires
  if (buttonState == HIGH) {
    servoTrigger.write(92);
    delay(delay_time);
    servoTrigger.write(90);
    delay(delay_time);
    servoTrigger.write(91);
  }
}

