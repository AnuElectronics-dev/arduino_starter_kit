int ldrPin = 2; // LDR digital output pin
int relayPin = 3; // Relay pin
int ldrValue = 0; // variable to store the LDR value

void setup() {
    pinMode(ldrPin, INPUT);
    pinMode(relayPin, OUTPUT);
    Serial.begin(9600); // start serial communication
}

void loop() {
    ldrValue = digitalRead(ldrPin); // read the LDR value
    Serial.println(ldrValue); // print the LDR value to the serial monitor

    if (ldrValue == LOW) {
        digitalWrite(relayPin, HIGH); // turn on the relay (and the light)
    } else {
        digitalWrite(relayPin, LOW); // turn off the relay (and the light)
    }
    delay(1000); // wait for a second before the next reading
}
