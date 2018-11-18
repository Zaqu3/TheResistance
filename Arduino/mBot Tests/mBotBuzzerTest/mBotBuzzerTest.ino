/**
 * @file    mBotBuzzerTest.ino
 * @author  Evan Genuise
 * @version V1.0.0
 * @date    11/6/2018
 * @brief   Description: This file is used to test the buzzer on mBot
 * 
 * Function List:
 * 1. void tone(int frequency, int duration)
 *    @brief Plays tone
 *    @param frequency Frequency (Hz)
 *    @param duration Time that note will be played x(ms)
 */

#include <MeMCore.h>

MeBuzzer buzzer;

void setup() {

}

void loop() {
  buzzer.tone(440, 1000);
  delay(1000);
  buzzer.tone(262, 1000);
  delay(3000);
}
