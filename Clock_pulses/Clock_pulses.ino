const int pinSalida = 13;
const int periodo = 1000;

void setup() {
  pinMode(pinSalida, OUTPUT);
}

void loop() {
  digitalWrite(pinSalida, HIGH);
  delay(periodo / 2);
  digitalWrite(pinSalida, LOW);
  delay(periodo / 2);
}