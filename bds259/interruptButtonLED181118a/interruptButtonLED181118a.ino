//interruptButtonLED181118a
const int S1pin=3; //interrupt-capable pin
const int LED1pin=13; //built-in LED

void setup() {
  pinMode(LED1pin,OUTPUT);
  pinMode(S1pin,INPUT);
  attachInterrupt(digitalPinToInterrupt(S1pin),S1on,RISING);
  attachInterrupt(digitalPinToInterrupt(S1pin),S1off,FALLING);
}

void loop(){
}

void S1on() {
  digitalWrite(LED1pin, HIGH);  
  }
void S1off() {
  digitalWrite(LED1pin, LOW);  
  }
