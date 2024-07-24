#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int receiverPin = 7; // Pin connected to OUT pin of IR receiver
IRrecv irrecv(receiverPin);
decode_results results;

// Initialize the I2C LCD library with the I2C address of the display
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address as necessary

void setup() {
    Serial.begin(9600); // Start the serial communication
    irrecv.enableIRIn(); // Start the IR receiver
    lcd.init(); // Initialize the LCD
    lcd.backlight(); // Turn on the backlight
    lcd.print("IR Command");
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.print("IR Command: ");
        Serial.println(results.value); // Print the IR command to the serial monitor

        lcd.setCursor(0, 1); // Set the cursor to the second line
        lcd.print("                "); // Clear the line
        lcd.setCursor(0, 1); // Set the cursor to the second line again
        lcd.print(results.value); // Print the IR command to the LCD

        irrecv.resume(); // Receive the next value
    }
}
