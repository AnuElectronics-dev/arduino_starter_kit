// Pin connected to LED
const int ledPin = 9;

// Pin connected to push button
const int buttonPin = 13;

// Setup function, runs once when Arduino is powered on
void setup() {
    // Initialize digital pins as inputs or outputs
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

// Loop function, runs repeatedly after setup() has finished
void loop() {
    // Check if the button is pressed
    if (digitalRead(buttonPin) == HIGH) {
        // If button is pressed, turn the LED on
        digitalWrite(ledPin, HIGH);
    } else {
        // If button is not pressed, turn the LED off
        digitalWrite(ledPin, LOW);
    }
}
