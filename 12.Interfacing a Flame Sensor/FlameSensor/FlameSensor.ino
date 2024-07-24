int flameAnalogPin = A0; // Pin connected to A0 pin of flame sensor
int flameDigitalPin = 2; // Pin connected to D0 pin of flame sensor

void setup() {
    Serial.begin(9600); // Start the serial communication
    pinMode(flameDigitalPin, INPUT); // Set digital pin as input
}

void loop() {
    int analogValue = analogRead(flameAnalogPin); // Read the analog value from the flame sensor
    int digitalValue = digitalRead(flameDigitalPin); // Read the digital value from the flame sensor

    Serial.print("Analog Value: ");
    Serial.print(analogValue); // Print the analog value to the serial monitor
    Serial.print(" | Digital Value: ");
    Serial.println(digitalValue); // Print the digital value to the serial monitor

    delay(500); // Wait for 500 milliseconds
}
