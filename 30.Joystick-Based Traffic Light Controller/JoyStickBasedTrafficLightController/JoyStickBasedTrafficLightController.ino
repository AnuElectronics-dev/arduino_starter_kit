const int VRx = A0; // Joystick VRx pin
const int VRy = A1; // Joystick VRy pin
const int SW = 2;   // Joystick switch pin

const int redLED = 11;
const int yellowLED = 10;
const int greenLED = 9;

void setup() {
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(SW, INPUT_PULLUP);

    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int xPosition = analogRead(VRx);
    int yPosition = analogRead(VRy);
    int switchState = digitalRead(SW);

    // Display joystick position
    Serial.print("X: ");
    Serial.print(xPosition);
    Serial.print(" | Y: ");
    Serial.print(yPosition);
    Serial.print(" | Switch: ");
    Serial.println(switchState);

    if (xPosition < 300) { // Move left
        digitalWrite(redLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(greenLED, LOW);
    } else if (xPosition > 700) { // Move right
        digitalWrite(redLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(greenLED, HIGH);
    } else if (yPosition < 300) { // Move up
        digitalWrite(redLED, LOW);
        digitalWrite(yellowLED, HIGH);
        digitalWrite(greenLED, LOW);
    } else if (yPosition > 700) { // Move down
        digitalWrite(redLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(greenLED, HIGH);
    } else { // Center position
        digitalWrite(redLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(greenLED, LOW);
    }

    delay(200);
}
