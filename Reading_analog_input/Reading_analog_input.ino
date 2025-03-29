const byte inputAnalog = A0;
const byte myLed = 2;
const int maxDelay = 500;
double value = 0;
bool showValue = false;

void setup() {
  pinMode(myLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Tomando el valor de la entrada analogica que va de 0 a 1023
  value = analogRead(inputAnalog);
  // Obteniendo el valor en porcentaje de la entrada
  double percentage = value / 1023;
  // Calcular el porcentaje según el retardo máximo definido
  double result = percentage * maxDelay;

  // Invirtiendo el resultado
  result = maxDelay - result;

  ledFlashing(result);
  serialCommunication();
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

void serialCommunication(){
  // Verifica si hay datos disponibles
  if(Serial.available() > 0){
    // Lee el byte entrante
    char incomingByte = Serial.read();

    switch(incomingByte){
      case 'S':
        showValue = true;
        break;
      case 'N':
        showValue = false;
        break;
    }
  }

  if(showValue){
    Serial.println(value);
  }
}