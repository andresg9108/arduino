const byte inputAnalog = A0;
const byte led1 = 3;
const byte led2 = 5;
const byte led3 = 6;

void setup() {
}

void loop() {
  // Tomando el valor de la entrada analogica que va de 0 a 1023
  int value = analogRead(inputAnalog);
  // Mapeo de 0 a 255
  int bright = map(value, 0, 1023, 0, 255);

  // Invirtiendo el resultado
  bright = 255 - bright;

  analogWrite(led1, bright);
  analogWrite(led2, bright);
  analogWrite(led3, bright);
  delay(10);
}
