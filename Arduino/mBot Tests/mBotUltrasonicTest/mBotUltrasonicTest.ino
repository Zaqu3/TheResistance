/**
 * @file    mBotUltrasonicTest.ino
 * @author  Evan Genuise
 * @version V1.0.0
 * @date    11/5/2018
 * @brief   Description: This file is used to test the ultrasonic sensor on mBot
 * 
 * Function List:
 * 1. double distanceCm(void)
 *    @return Returns distance in centimeters, range: 3-400
 */

#include <MeMCore.h>

MeUltrasonicSensor ultrasonic(PORT_3);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Distance: ");
  Serial.print(ultrasonic.distanceCm());
  Serial.println("cm");
  delay(50);
}
