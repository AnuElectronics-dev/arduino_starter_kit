const int potPin = A0; // Pin connected to the potentiometer
const int ledPin = 2; // Pin connected to the LED

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int potValue = analogRead(potPin); // Read the potentiometer value
    int brightness = map(potValue, 0, 1023, 0, 255); // Map the value to a range from 0 to 255

    analogWrite(ledPin, brightness); // Set the LED brightness

    // Print the potentiometer value and the corresponding brightness
    Serial.print("Potentiometer Value: ");
    Serial.print(potValue);
    Serial.print(" | Brightness: ");
    Serial.println(brightness);

    delay(100); // Wait for a short period before the next loop
}
