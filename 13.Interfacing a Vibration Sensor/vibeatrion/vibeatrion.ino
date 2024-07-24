int vibrationDigitalPin = 2; // Pin connected to D0 pin of vibration sensor

void setup() {
    Serial.begin(9600); // Start the serial communication
    pinMode(vibrationDigitalPin, INPUT); // Set digital pin as input
}

void loop() {
    int digitalValue = digitalRead(vibrationDigitalPin); // Read the digital value from the vibration sensor

    Serial.print("Digital Value: ");
    Serial.println(digitalValue); // Print the digital value to the serial monitor

    delay(500); // Wait for 500 milliseconds
}
