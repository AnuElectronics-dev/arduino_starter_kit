// Interfacing Arduino Uno with LDR sensor
const int ldrPin = A0; // Analog pin 0

void setup() {
    // The setup() function will only run once, after each powerup or reset of the Arduino board.
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT); // Here LED is determined as an output or an indicator.
    pinMode(ldrPin, INPUT);       // Here LDR sensor is determined as input.
}

void loop() {
    // Void loop is ran again and again and contains main code.
    int ldrStatus = analogRead(ldrPin);

    if (ldrStatus <= 200) {
        digitalWrite(LED_BUILTIN, HIGH); // If LDR senses darkness, LED pin is set high, causing the LED to glow.
        Serial.print("Darkness over here, turn on the LED: ");
        Serial.println(ldrStatus);
    } else {
        digitalWrite(LED_BUILTIN, LOW); // If LDR senses light, LED pin is set low, causing the LED to stop glowing.
        Serial.print("There is sufficient light, turn off the LED: ");
        Serial.println(ldrStatus);
    }
}
