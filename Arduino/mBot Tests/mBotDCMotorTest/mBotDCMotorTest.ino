/**
 * @file    mBotDCMotorTest.ino
 * @author  Evan Genuise
 * @version V1.0.0
 * @date    11/5/2018
 * @brief   Description: This file is used to test the DC Motors on mBot
 * 
 * Function List:
 * 1. void run(int speed)
 *    @brief Runs motor
 *    @param speed Speed of motor, range: -255 to 255, 0 = idle
 * 
 * 2. void stop(void)
 *    @brief Stops motor
 */

#include <MeMCore.h>

MeDCMotor leftMotor(M1);  //M1 is Left Motor
MeDCMotor rightMotor(M2); //M2 is Right Motor

const int motorSpeed = 100;
void setup(){}

void loop()
{
  leftMotor.run(-motorSpeed);    // negative numbers move left wheel forward
  rightMotor.run(motorSpeed);    // positive numbers move right wheel forward
  delay(1000);
  leftMotor.run(motorSpeed);
  rightMotor.run(-motorSpeed);
  delay(1000);
}
