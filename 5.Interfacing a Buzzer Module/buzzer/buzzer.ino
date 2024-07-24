// Pin connected to buzzer module
const int buzzerPin = 2;

// Setup function, runs once when Arduino is powered on
void setup() {
    // Initialize digital pin as an output
    pinMode(buzzerPin, OUTPUT);
}

// Loop function, runs repeatedly after setup() has finished
void loop() {
    // Turn the buzzer on
    digitalWrite(buzzerPin, HIGH);
    delay(1000); // Wait for 1 second

    // Turn the buzzer off
    digitalWrite(buzzerPin, LOW);
    delay(1000); // Wait for 1 second
}
