#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2         // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11    // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
    lcd.begin();
    lcd.backlight();
    dht.begin();
    lcd.print("Weather Station");
    delay(2000);
    lcd.clear();
}

void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
        lcd.setCursor(0, 0);
        lcd.print("Error Reading");
        lcd.setCursor(0, 1);
        lcd.print("Sensor Data");
        return;
    }

    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print(" %");

    delay(2000); // Wait 2 seconds before updating the readings
}
