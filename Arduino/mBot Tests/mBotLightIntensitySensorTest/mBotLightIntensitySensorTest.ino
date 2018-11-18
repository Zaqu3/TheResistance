/**
 * @file    mBotLightIntensitySensorTest.ino
 * @author  Evan Genuise
 * @version V1.0.0
 * @date    11/5/2018
 * @brief   Description: This file is used to test the light intensity sensor on mBot
 * 
 * Function List:
 * 1. int read()
 *    @return Returns level of brightness as an integer, range: 0-1023, 0 = dark, 1023 = bright
 */

#include <MeMCore.h>

MeLightSensor lightSensor(PORT_8);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("value = ");           // Print the results to the serial monitor
  Serial.println(lightSensor.read()); // Brightness value from 0-1023
  delay(50);                          // Wait 50 milliseconds before next measurement
}
