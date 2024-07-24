int potPin = A0;     // Analog pin connected to the potentiometer
int potValue = 0;    // Variable to store the potentiometer value

void setup() {
    Serial.begin(9600);  // Initialize serial communication at 9600 bits per second
}

void loop() {
    potValue = analogRead(potPin);  // Read the potentiometer value
    Serial.println(potValue);       // Print the potentiometer value to the Serial Monitor
    delay(100);                     // Wait for 100 milliseconds before reading again
}
