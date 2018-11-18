/**
 * @file    mBotHaltUntilActionTest.ino
 * @author  Evan Genuise
 * @version V1.0.0
 * @date    11/5/2018
 * @brief   Description: This file halts the loop() function until the on-board button is pushed
 */

#include <MeMCore.h>

void setup()
{
  pinMode(7, INPUT);
  while (analogRead(7) > 100)
    delay(50);
}

void loop()
{
  //Other Code
}
