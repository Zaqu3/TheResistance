//interruptButtonLED181118c
const int S1pin=3; //interrupt-capable pin
const int LED1pin=13; //built-in LED
volatile bool LED1on; // true when we want to turn it on

void setup() {
  pinMode(LED1pin,OUTPUT);
  pinMode(S1pin,INPUT);
  attachInterrupt(digitalPinToInterrupt(S1pin),S1rising,RISING);
}

void loop(){
}

void S1rising() {
  LED1on=!LED1on;
  if (LED1on) {
    digitalWrite(LED1pin, HIGH);  
  }
  else {
    digitalWrite(LED1pin, LOW);  
  }
}
