#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pHPin = A0;
int mq135Pin = A1;
int mq3Pin = A2;
int waterLevelPin = A3;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  float pHValue = analogRead(pHPin) * 5.0 / 1024;
  float mq135Value = analogRead(mq135Pin);
  float mq3Value = analogRead(mq3Pin);
  float waterLevelValue = analogRead(waterLevelPin);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("pH: ");
  lcd.print(pHValue);

  lcd.setCursor(0, 1);
  lcd.print("MQ-135: ");
  lcd.print(mq135Value);

  lcd.setCursor(9, 1);
  lcd.print("MQ-3: ");
  lcd.print(mq3Value);

  lcd.setCursor(0, 1);
  lcd.print("Water Level: ");
  lcd.print(waterLevelValue);

  delay(1000);
}
