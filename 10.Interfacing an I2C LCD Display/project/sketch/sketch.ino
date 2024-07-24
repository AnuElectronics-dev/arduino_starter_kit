#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Initialize the LCD
    lcd.begin();
    // Turn on the backlight
    lcd.backlight();
    // Print a message to the LCD
    lcd.setCursor(0, 0); // Set cursor to column 0, row 0
    lcd.print("Hello, Makers!");
}

void loop() {
    lcd.setCursor(0, 1); // Set cursor to column 0, row 1
    lcd.print("Welcome to");
    delay(1000); // Wait for 1 second
    lcd.print("Arduino! ");
    delay(1000); // Wait for 1 second
    lcd.clear(); // Clear the display
    lcd.setCursor(0, 0); // Reset cursor to column 0, row 0
    lcd.print("Hello, Makers!");
}
