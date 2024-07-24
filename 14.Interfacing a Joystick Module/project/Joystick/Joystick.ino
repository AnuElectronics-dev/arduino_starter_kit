int VRx = A0; // Pin connected to VRx of joystick
int VRy = A1; // Pin connected to VRy of joystick
int SW = 2;   // Pin connected to SW of joystick

int ledPins[] = {3, 4, 5, 6}; // Pins connected to LEDs

void setup() {
    Serial.begin(9600); // Start the serial communication
    pinMode(SW, INPUT_PULLUP); // Set SW pin as input with internal pull-up resistor
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT); // Set LED pins as outputs
    }
}

void loop() {
    int xValue = analogRead(VRx); // Read the analog value from VRx
    int yValue = analogRead(VRy); // Read the analog value from VRy
    int swValue = digitalRead(SW); // Read the digital value from SW

    Serial.print("X: ");
    Serial.print(xValue);
    Serial.print(" | Y: ");
    Serial.print(yValue);
    Serial.print(" | Button: ");
    Serial.println(swValue);

    // Map joystick values to control LEDs
    if (xValue < 300) {
        digitalWrite(ledPins[0], HIGH); // Turn on LED 1
    } else {
        digitalWrite(ledPins[0], LOW); // Turn off LED 1
    }

    if (xValue > 700) {
        digitalWrite(ledPins[1], HIGH); // Turn on LED 2
    } else {
        digitalWrite(ledPins[1], LOW); // Turn off LED 2
    }

    if (yValue < 300) {
        digitalWrite(ledPins[2], HIGH); // Turn on LED 3
    } else {
        digitalWrite(ledPins[2], LOW); // Turn off LED 3
    }

    if (yValue > 700) {
        digitalWrite(ledPins[3], HIGH); // Turn on LED 4
    } else {
        digitalWrite(ledPins[3], LOW); // Turn off LED 4
    }

    delay(100); // Wait for 100 milliseconds
}
