const int vibrationPin = 2; // Pin connected to the vibration sensor
const int buzzerPin = 3;    // Pin connected to the buzzer
const int ledPin = 4;       // Pin connected to the LED

void setup() {
    pinMode(vibrationPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int vibrationState = digitalRead(vibrationPin); // Read the vibration sensor state

    if (vibrationState == HIGH) {
        digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
        digitalWrite(ledPin, HIGH);    // Turn on the LED
        Serial.println("Vibration detected!");
    } else {
        digitalWrite(buzzerPin, LOW); // Turn off the buzzer
        digitalWrite(ledPin, LOW);    // Turn off the LED
    }

    delay(100); // Wait for a short period before the next loop
}
