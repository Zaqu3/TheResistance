/*
 * 181118d bds259 1227
 * 
 * Required hardware:
 * Arduino Uno
 * Switch connecting 5V and Pin 3 (Interrupt 1)
 * Pulldown resistor also on Pin 3
 * 
 * Optional hardware:
 * External LED and current-limiting resistor between Pin 13 (anode) and ground
 * 
 * Background:
 * 
 * Timer 0 by Arduino OS default is prescaled to tick only every 64th clock cycle, and, being 8-bit, overflows every 256 ticks. Thus, slows time by a factor of 64*256=16,384.
 * Timer 0 has three associated interrupts: overflow, compare ch A, and compare ch B. The Arduino OS uses "overflow" and our program uses "A".
 * Timer 0 overflows every 1/16,000,000 (16 MHz) X 64 (prescale) X 256 (roll over): every 0.001024 seconds, a longer period than the ideal 0.001s (1 ms).
 * I.e., 16000000/64/256=976.5625 Hz, a lower frequency than the ideal 1000 Hz.
 * 
 * The operating system's Timer 0 overflow interrupt handler corrects this to 1 KHz, but it's somewhat inelegant:
 * 1) Increments the value of timer0_millis every 1.024 ms
 * 2) Adds an extra increment to timer0_millis every time timer0_fract is greater than 125 to account for the missing 0.024 ms (this correction happens every 125/3=41.67 ms).
 * Thus, timer0_millis accumulates an error of 0.024ms each time it executes (every overflow), until the error approaches 1 ms, then timer0_millis increases by 2 rather than 1 that time.
 * (A processor hardware clock frequency of 16,384,000 Hz instead of 16,000,000 Hz would have been so much better. ALWAYS USE POWERS OF TWO, PEOPLE!)
 * 
 * To piggyback onto the system's use of Timer 0 without changing its frequency, we will set up an interrupt to happen at some point before Timer 0 overflows.
 * We don't want to do this near 00 or FF because the system is already busy then, handling the overflow interrupt. So we'll pick some value around 7F (127, i.e., 180 degrees out of phase).
 * Every time Timer 0's value reaches our number, the comparison will be true and our interrupt will assert and our handler will fire. This will happen every 1.024 ms.
 * Then, for, say, 2 Hz, we could maintain our own counter and look for modulo 512 to be zero, or (much better) we could just look at the already-corrected system counter and use modulo 500.
 * 
 * Note: "volatile" means stored in global RAM rather than as a register value that would not be accessible across a context switch (i.e., inside an interrupt service routine).
 */

const int LED1pin=13;
const int S1pin=3;
volatile bool LED1on;
volatile bool LED1blink;

void setup() {
  pinMode(LED1pin,OUTPUT);
  digitalWrite(LED1pin, LOW); //start out off (optional)
  pinMode(S1pin,INPUT);
  attachInterrupt(digitalPinToInterrupt(S1pin),S1rising,RISING);
  OCR0A = 0x7F; //Timer0 output compare register, look for a time opposite when the system's overflow handler fires
  TIMSK0 |= _BV(OCIE0A); //generate a 'TIMER0_COMPA' interrupt (every 1.024 ms)
}

void loop() {
}

SIGNAL(TIMER0_COMPA_vect) 
{
  if (LED1blink) {
    unsigned long currentMillis = millis();
    if (currentMillis % 250 == 0) {
      LED1on=!LED1on;
      if (LED1on) {
        digitalWrite(LED1pin, HIGH);  
        }
      else {
        digitalWrite(LED1pin, LOW);  
        }
      }
   }
}

void S1rising() {
  LED1blink=!LED1blink;
  if (!LED1blink) {
    digitalWrite(LED1pin, LOW); //off when not blinking (optional)
  }
}
