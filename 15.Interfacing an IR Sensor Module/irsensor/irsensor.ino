int irSensorPin = 2; // Pin connected to OUT pin of IR sensor

void setup() {
    Serial.begin(9600); // Start the serial communication
    pinMode(irSensorPin, INPUT); // Set IR sensor pin as input
}

void loop() {
    int sensorValue = digitalRead(irSensorPin); // Read the digital value from the IR sensor

    Serial.print("IR Sensor Value: ");
    Serial.println(sensorValue); // Print the sensor value to the serial monitor

    delay(500); // Wait for 500 milliseconds
}
