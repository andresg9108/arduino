const byte myLed = 2;
const int ledDelay = 500;

void setup() {
  pinMode(myLed, OUTPUT);
}

void loop() {
  digitalWrite(myLed, HIGH);
  delay(ledDelay);
  digitalWrite(myLed, LOW);
  delay(ledDelay);
}