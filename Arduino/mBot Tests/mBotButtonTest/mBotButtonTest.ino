/**
 * @file    mBotButtonTest.ino
 * @author  Evan Genuise
 * @version V1.0.0
 * @date    11/5/2018
 * @brief   Description: This file is used to test the on-board button on mBot
 */

#include <MeMCore.h>

void setup()
{
  Serial.begin(9600); // Initialize serial communication
  pinMode(7, INPUT);  // Define button pin as input
}

void loop() {
  if (analogRead(7) < 100){
  Serial.print("Button Pressed ");
  }else{
  Serial.print("Not Pressed "); 
  }
  Serial.println(analogRead(7));
  delay(50);
}
