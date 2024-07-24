void setup() {
    pinMode(11, OUTPUT); // Blue
    pinMode(12, OUTPUT); // Green
    pinMode(13, OUTPUT); // Red
}

void loop() {
    analogWrite(13, 255); // Red on
    analogWrite(12, 0);   // Green off
    analogWrite(11, 0);   // Blue off
    delay(1000);          // Wait for 1 second

    analogWrite(13, 0);   // Red off
    analogWrite(12, 255); // Green on
    analogWrite(11, 0);   // Blue off
    delay(1000);          // Wait for 1 second

    analogWrite(13, 0);   // Red off
    analogWrite(12, 0);   // Green off
    analogWrite(11, 255); // Blue on
    delay(1000);          // Wait for 1 second
}
