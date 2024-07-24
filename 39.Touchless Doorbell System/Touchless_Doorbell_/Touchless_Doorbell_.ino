const int irSensorPin = 2; // Pin connected to the IR sensor
const int buzzerPin = 3;   // Pin connected to the buzzer

void setup() {
    pinMode(irSensorPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int irState = digitalRead(irSensorPin); // Read the IR sensor state

    if (irState == HIGH) {
        digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
        Serial.println("Hand detected!");
    } else {
        digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    }

    delay(100); // Wait for a short period before the next loop
}
