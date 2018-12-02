#include <Servo.h>

#define danceButton 4

Servo xAxis;
Servo yAxis;

int delayTime = 5;

void setup()
{
  pinMode(danceButton, INPUT);
  xAxis.attach(9);
  yAxis.attach(10);
}

void loop()
{
  //if (digitalRead(danceButton) == HIGH)
    dance();
}

void dance()
{
  for (int i = 90; i < 180; i++)
  {
    xAxis.write(i);
    delay(delayTime);
  }
  upDown();
  upDown();

  for (int i = 180; i > 0; i--)
  {
    xAxis.write(i);
    delay(delayTime);
  }

  upDown();
  upDown();

  for (int i = 0; i < 90; i++)
  {
    xAxis.write(i);
    delay(delayTime);
  }
}

void upDown()
{
  for(int i = 90; i > 0; i--)
  {
    yAxis.write(i);
    delay(delayTime);
  }

  for(int j = 0; j < 90; j++)
  {
    yAxis.write(j);
    delay(delayTime);
  }
}
