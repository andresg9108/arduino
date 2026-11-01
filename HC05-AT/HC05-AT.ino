#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // TX, RX

void setup() {
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH); // activa EN antes de iniciar serial

  Serial.begin(9600);
  BT.begin(38400); // Velocidad por defecto en modo AT

  Serial.println("Modo AT listo");
}

void loop() {
  if (BT.available()) {
    Serial.write(BT.read());
  }
  if (Serial.available()) {
    BT.write(Serial.read());
  }
}