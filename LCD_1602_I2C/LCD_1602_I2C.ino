#include "Wire.h"
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd1602 (0x27, 16, 2);

byte a_acentuada[8] = {B00100,B00000,B01110,B00001,B01111,B10001,B01111,B00000};
byte e_acentuada[8] = {B00100,B00000,B01110,B10000,B11110,B10000,B01110,B00000};

void setup() {
  Wire.begin();
  lcd1602.begin(16, 2);
  lcd1602.createChar(0, a_acentuada);
  lcd1602.createChar(1, e_acentuada);
  lcd1602.clear();
  lcd1602.backlight();
  // lcd1602.noBacklight();
  Serial.begin(9600);
}

void loop() {
  lcd1602.setCursor(2,0);
  lcd1602.print("Hola, mundo!");
  delay(2000);
  lcd1602.clear();
  delay(1000);
  
  lcd1602.setCursor(5,1);
  lcd1602.print("Me llamo Andr");
  lcd1602.setCursor(18,1);
  lcd1602.write(byte(1));
  lcd1602.setCursor(19,1);
  lcd1602.print("s ");
  lcd1602.setCursor(21,1);
  lcd1602.print("Gonz");
  lcd1602.setCursor(25,1);
  lcd1602.write(byte(0));
  lcd1602.setCursor(26,1);
  lcd1602.print("lez");
  for (int i=0; i<39; i++) {
    lcd1602.scrollDisplayLeft();
    delay(500);
  }

  lcd1602.clear();
  delay(1000);
}