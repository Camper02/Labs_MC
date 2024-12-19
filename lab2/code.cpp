#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <SFE_BMP180.h>
#include <DS3232RTC.h>

DHT dht(7, DHT11);
SFE_BMP180 bmp180;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);
  bmp180.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  double p, bmpt;
  bmp180.startTemperature();
  bmp180.startPressure(3);
  bmp180.getPressure(p, bmpt);
  lcd.setCursor(0, 0);
  lcd.print(hour());
  lcd.print(":");
  lcd.print(minute());
  lcd.print(":");
  lcd.print(second());
  lcd.print(" T: ");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(h);
  lcd.print(" P: ");
  lcd.print(p);
}
