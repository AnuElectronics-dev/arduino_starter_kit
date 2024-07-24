const int sensorPin = A0; // Pin connected to the sensor
const int redLED = 3;     // Pin connected to the red LED
const int yellowLED = 4;  // Pin connected to the yellow LED
const int greenLED = 5;   // Pin connected to the green LED

void setup() {
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int sensorValue = analogRead(sensorPin); // Read the sensor value

    // Print the sensor value
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);

    // Determine which LED to light up based on the sensor value
    if (sensorValue < 300) {
        digitalWrite(redLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(greenLED, LOW);
    } else if (sensorValue >= 300 && sensorValue < 600) {
        digitalWrite(redLED, LOW);
        digitalWrite(yellowLED, HIGH);
        digitalWrite(greenLED, LOW);
    } else {
        digitalWrite(redLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(greenLED, HIGH);
    }

    delay(500); // Wait for 500 milliseconds
}
