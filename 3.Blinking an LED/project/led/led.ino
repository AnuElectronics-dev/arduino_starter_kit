// Pin connected to LED
const int ledPin = 13;

// Setup function, runs once when Arduino is powered on
void setup() {
    // Initialize digital pin as an output
    pinMode(ledPin, OUTPUT);
}

// Loop function, runs repeatedly after setup() has finished
void loop() {
    // Turn the LED on (HIGH is the voltage level)
    digitalWrite(ledPin, HIGH);
    // Delay for 1000 milliseconds (1 second)
    delay(1000);
    // Turn the LED off by making the voltage LOW
    digitalWrite(ledPin, LOW);
    // Delay for 1000 milliseconds
    delay(1000);
}
