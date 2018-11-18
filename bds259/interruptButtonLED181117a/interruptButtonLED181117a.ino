// 181117interruptButtonLED
const int momentary=3;
const int LED=13;
volatile int momentaryState = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(momentary, INPUT);
  // Pin 3 is interrupt 1:
  attachInterrupt(1,handler,CHANGE);
}

void loop(){
}

void handler() {
  momentaryState = digitalRead(momentary);
  digitalWrite(LED, momentaryState);  
  }
