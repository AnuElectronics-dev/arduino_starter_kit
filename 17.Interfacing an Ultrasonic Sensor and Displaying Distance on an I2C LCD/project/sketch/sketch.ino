#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 8
#define MAX_DISTANCE 200

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address as necessary
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
    Serial.begin(9600); // Start the serial communication
    lcd.init(); // Initialize the LCD
    lcd.backlight(); // Turn on the backlight
    lcd.print("Distance");
}

void loop() {
    delay(50); // Wait for 50 milliseconds
    unsigned int distance = sonar.ping_cm(); // Measure distance in centimeters

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    lcd.setCursor(0, 1); // Set the cursor to the second line
    lcd.print("                "); // Clear the line
    lcd.setCursor(0, 1); // Set the cursor to the second line again
    lcd.print(distance);
    lcd.print(" cm");
}
