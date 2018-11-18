const int LED1pin=13;
volatile bool LED1on;

void setup() {
  pinMode(LED1pin,OUTPUT);
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

void loop() {
}

SIGNAL(TIMER0_COMPA_vect) 
{
  unsigned long currentMillis = millis();
  if (currentMillis % 500 == 0)
  {
    LED1on=!LED1on;
  if (LED1on) {
    digitalWrite(LED1pin, HIGH);  
  }
  else {
    digitalWrite(LED1pin, LOW);  
  }
  }
}
