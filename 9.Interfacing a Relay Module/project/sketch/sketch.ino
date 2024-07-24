int relayPin = 2; // Pin connected to IN pin of relay module

void setup() {
    pinMode(relayPin, OUTPUT); // Set relay pin as output
    digitalWrite(relayPin, LOW); // Initialize relay in OFF state
}

void loop() {
    digitalWrite(relayPin, HIGH); // Turn relay ON
    delay(1000); // Wait for 1 second
    digitalWrite(relayPin, LOW); // Turn relay OFF
    delay(1000); // Wait for 1 second
}
