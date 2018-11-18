/**
 * @file    Hackathon_Fall_2018.ino
 * @author  Corey Cline
 * @version V1.0.0
 * @date    11/16/2018
 * @brief   Description: Testing a directional and continuous Servo setup
 * 
 * Function List:
 * 1. pinMode(pin, mode)
 *    @assigns buttons to arduino pins
 *    @param button gets passed as an input
 * 
 * 2. map(value, fromLow, fromHigh, toLow, toHigh)
 *    @maps potentiometer values to direcitonal servo positions
 *    @param potentiometer, min read, max read, min map, max map)
 * 
 * 3. analogRead(pin)
 *    @reads analog signal input from potentiometer
 *    @param potentiometer
 *    
 * 4. digitalRead(pin)
 *    @reads the state of the buttons, 5V or 0V
 *    @param button
 */
 

// initialize variables and libraries
#include <Servo.h>

const int potPin1 = A0;
const int buttonUp = 8;
const int buttonDown = 7;

int knob_val;

Servo serv1;
Servo serv2;

void setup() {
  // put your setup code here, to run once:
  serv1.attach(11);
  serv2.attach(10);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // map val inputs
  knob_val = map(analogRead(potPin1), 0, 1023, 0, 180);
  // write val inputs to servos
  serv1.write(knob_val);
  delay(15);
  Serial.println(digitalRead(buttonUp));
  if(digitalRead(buttonUp) == HIGH)
  {
    serv2.write(180);
  }
  else if(digitalRead(buttonDown) == HIGH)
  {
    serv2.write(0);
  }
  else
    serv2.write(90);
}
