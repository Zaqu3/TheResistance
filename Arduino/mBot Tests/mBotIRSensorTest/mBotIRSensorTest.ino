/**
 * @file    mBotIRSensorTest.ino
 * @author  Evan Genuise
 * @version V1.0.0
 * @date    11/5/2018
 * @brief   Description: This file is used to test the IR sensors on front of mBot
 * 
 * Function List:
 * 1. int readSensors(void)
 *    @return Returns IR state of each IR sensor
 */

#include <MeMCore.h>

MeLineFollower lineFinder(PORT_2); 

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorState = lineFinder.readSensors();
  switch(sensorState)
  {
    case S1_IN_S2_IN:   Serial.println("S1_IN_S2_IN"); break;
    case S1_IN_S2_OUT:  Serial.println("S1_IN_S2_OUT"); break;
    case S1_OUT_S2_IN:  Serial.println("S1_OUT_S2_IN"); break;
    case S1_OUT_S2_OUT: Serial.println("S1_OUT_S2_OUT"); break;
    default: break;
  }
  delay(50);
}
