const byte motor1A = 2;
const byte motor1B = 4;
const byte motor1Velocidad = 3;
double velocidad = 0;

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
}

void loop() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);

  velocidad = 0;
  run();

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);

  velocidad = 0;
  run();

  // Frenar el motor
  // digitalWrite(motor1A, HIGH);
  // digitalWrite(motor1B, HIGH);
}

void run() {
  for (velocidad = 0; velocidad <= 255; velocidad += 25) {
    analogWrite(motor1Velocidad, velocidad);
    delay(2000);
  }

  for (velocidad = 255; velocidad > 0; velocidad -= 25) {
    analogWrite(motor1Velocidad, velocidad);
    delay(2000);
  }
}