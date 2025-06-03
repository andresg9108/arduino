#include "Wire.h"
#include "LiquidCrystal_I2C.h"

const byte inputAnalog = A0;
const int ledDelay = 4000;
int value = 0;
LiquidCrystal_I2C lcd1602 (0x27, 16, 2);

byte simbolo_grados[8] = {B00110,B01001,B00110,B00000,B00000,B00000,B00000,B00000};

void setup() {
  Wire.begin();
  lcd1602.begin(16, 2);
  lcd1602.createChar(0, simbolo_grados);
  lcd1602.clear();
  lcd1602.backlight();
  // lcd1602.noBacklight();
}

void loop() {
  value = analogRead(inputAnalog);

  double result = value * 0.48;

  lcd1602.setCursor(2,0);
  lcd1602.print(String(result));
  lcd1602.setCursor(7,0);
  lcd1602.write(byte(0));
  lcd1602.setCursor(8,0);
  lcd1602.print("C");

  delay(10000);
}