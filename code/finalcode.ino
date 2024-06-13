//the final code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

#define pHPin A0
#define mq2Pin A1
#define mq3Pin A2
#define waterLevelPin A3

const float mq2Threshold = 1.0; 
const float mq3Threshold = 1.0; 
const long interval = 60000; 

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600); 
}

void loop() {

  float pHValue = analogRead(pHPin) * (5.0 / 1023.0);
  float mq2Value = analogRead(mq2Pin) * (5.0 / 1023.0); 
  float mq3Value = analogRead(mq3Pin) * (5.0 / 1023.0); 
  float waterLevelValue = analogRead(waterLevelPin) * (5.0 / 1023.0); 

  char mq2Status = mq2Value >= mq2Threshold ? 'Y' : 'N';
  char mq3Status = mq3Value >= mq3Threshold ? 'Y' : 'N';
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("pH:");
  lcd.setCursor(2, 1);
  lcd.print(pHValue, 2); 

  lcd.setCursor(10, 0);
  lcd.print("Water: ");
  lcd.setCursor(10,1);
  lcd.print(waterLevelValue, 2); 

  lcd_bar();
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smoke:");
  lcd.setCursor(2, 1);
  lcd.print(analogRead(mq2Pin)); 

  lcd.setCursor(8, 0);
  lcd.print("Alcohol:");
  lcd.setCursor(10,1);
  lcd.print(analogRead(mq3Pin)); 

  lcd_bar();
  
  Serial.print("pH: ");
  Serial.print(pHValue, 2);
  Serial.print(" MQ-2: ");
  Serial.print(analogRead(mq2Pin),2);
  //mq2Value, 2);
  Serial.print(" Status: ");
  Serial.print(mq2Status);
  Serial.print(" MQ-3: ");
  Serial.print(mq3Value, 2);
  Serial.print(" Status: ");
  Serial.print(mq3Status);
  Serial.print(" Water Level: ");
  Serial.println(waterLevelValue, 2);

  delay(3000);                                                                                                                                                                                        
}


void lcd_bar()
{
  lcd.setCursor(7,0);
  lcd.print("|");
  lcd.setCursor(7,1);
  lcd.print("|");
}
