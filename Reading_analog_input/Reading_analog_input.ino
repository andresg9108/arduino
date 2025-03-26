const byte inputAnalog = A0;
const byte myLed = 2;
const int maxDelay = 500;

void setup() {
  pinMode(myLed, OUTPUT);
}

void loop() {
  // Tomando el valor de la entrada analogica que va de 0 a 1023
  double value = analogRead(inputAnalog);
  // Obteniendo el valor en porcentaje de la entrada
  double percentage = value / 1023;
  // Calcular el porcentaje según el retardo máximo definido
  double result = percentage * maxDelay;

  // Invirtiendo el resultado
  result = maxDelay - result;

  ledFlashing(result);
}

void ledFlashing(double ledDelay) {
  digitalWrite(myLed, HIGH);

  if(ledDelay > 10){
    digitalWrite(myLed, HIGH);
    delay(ledDelay);
    digitalWrite(myLed, LOW);
    delay(ledDelay);
  }
}