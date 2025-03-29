const byte input = 12;
const byte led = 13;

void setup() {
  pinMode(input, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if(digitalRead(input) == HIGH)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
