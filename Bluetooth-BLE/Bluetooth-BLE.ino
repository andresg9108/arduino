#include <ArduinoBLE.h>

// Define tus UUIDs aquí
#define DATA_SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID      "abcdef01-1234-5678-1234-56789abcdef0"

BLEService dataService(DATA_SERVICE_UUID);
BLECharacteristic miCharacteristic(CHARACTERISTIC_UUID, BLERead | BLENotify, 20);

const byte leftA = 2;
const byte leftB = 4;
const byte leftPWM = 3;
const byte rightA = 7;
const byte rightB = 8;
const byte rightPWM = 6;

char input = "";

void setup() {
  BLE.begin();
  BLE.setLocalName("Gonza Car");
  BLE.setAdvertisedService(dataService);

  dataService.addCharacteristic(miCharacteristic);
  BLE.addService(dataService);

  miCharacteristic.writeValue(""); // Valor inicial

  BLE.advertise();

  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
}

void loop() {
  // miCharacteristic.writeValue("R");

  input = miCharacteristic.value();

  switch(input) {
    case 'a':
      forward();
      break;
    case 'b':
      back();
      break;
  }
}

void forward() {
  digitalWrite(leftA, HIGH);
  digitalWrite(leftB, LOW);
  
  digitalWrite(rightA, HIGH);
  digitalWrite(rightB, LOW);

  analogWrite(leftPWM, 255);
  analogWrite(rightPWM, 255);

  delay(2000);

  analogWrite(leftPWM, 0);
  analogWrite(rightPWM, 0);
}

void back() {
  digitalWrite(leftA, LOW);
  digitalWrite(leftB, HIGH);

  digitalWrite(rightA, LOW);
  digitalWrite(rightB, HIGH);

  analogWrite(leftPWM, 255);
  analogWrite(rightPWM, 255);

  delay(2000);

  analogWrite(leftPWM, 0);
  analogWrite(rightPWM, 0);
}