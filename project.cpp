#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4  
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin(); 
  lcd.init(); 
  lcd.backlight();  
}

void loop() {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = tempC * 9 / 5 + 32;  

  lcd.setCursor(0, 0);
  if (isnan(humidity) || isnan(tempF)) {
    lcd.print("Sensor Error!");
  } else {
    lcd.print("Humidity: ");
    lcd.print(humidity, 0);
    lcd.print("%   "); 
    lcd.setCursor(0, 1); 
    lcd.print("Temp: ");
    lcd.print(tempF, 1); 
    lcd.print(" F   ");
  }

  delay(200);
}