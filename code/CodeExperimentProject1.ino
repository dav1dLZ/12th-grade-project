#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int phSensorPin = A0;
const int mq3SensorPin = A1;
const int mq2SensorPin = A2;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.print("Arduino Sensors");
  lcd.setCursor(0, 1);
  lcd.print("PH & MQ3 & MQ2");

  delay(2000);
  lcd.clear();
}

void loop() {
  float phValue = readPHSensor();
  float mq3Value = readMQ3Sensor();
  float mq2Value = readMQ2Sensor();


  lcd.setCursor(0, 0);
  lcd.print("pH: ");
  lcd.print(phValue);

  
  lcd.setCursor(0, 1);
  lcd.print("MQ-3: ");
  lcd.print(mq3Value);

  
  lcd.setCursor(0, 2);
  lcd.print("MQ-2: ");
  lcd.print(mq2Value);

  delay(1000);
  lcd.clear();
}

float readPHSensor() {
  int sensorValue = analogRead(phSensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float phValue = 7 - (voltage - 2.5); 
  return phValue;
}

float readMQ3Sensor() {
  int sensorValue = analogRead(mq3SensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float mq3Value = voltage; 
  return mq3Value;
}

float readMQ2Sensor() {
  int sensorValue = analogRead(mq2SensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float mq2Value = voltage;
  return mq2Value;
}
