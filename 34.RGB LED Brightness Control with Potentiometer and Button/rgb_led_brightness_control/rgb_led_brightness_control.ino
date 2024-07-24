const int potPin = A0;  // Pin connected to the potentiometer
const int buttonPin = 13; // Pin connected to the push button

const int redPin = 4; // Pin connected to the red anode of the RGB LED
const int greenPin = 3; // Pin connected to the green anode of the RGB LED
const int bluePin = 2; // Pin connected to the blue anode of the RGB LED

int buttonState = 0;  // Variable for reading the button status
int colorState = 0;   // Variable to keep track of the current color

void setup() {
    pinMode(potPin, INPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int potValue = analogRead(potPin); // Read the potentiometer value
    int brightness = map(potValue, 0, 1023, 0, 255); // Map the value to a range from 0 to 255

    buttonState = digitalRead(buttonPin); // Read the state of the button

    // Change color on button press
    if (buttonState == LOW) {
        colorState = (colorState + 1) % 3; // Cycle through 0, 1, 2
        delay(200); // Debounce delay
    }

    // Set the RGB LED color based on the current color state
    if (colorState == 0) { // Red
        analogWrite(redPin, brightness);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
    } else if (colorState == 1) { // Green
        analogWrite(redPin, 0);
        analogWrite(greenPin, brightness);
        analogWrite(bluePin, 0);
    } else if (colorState == 2) { // Blue
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, brightness);
    }

    // Print the potentiometer value and the corresponding brightness
    Serial.print("Potentiometer Value: ");
    Serial.print(potValue);
    Serial.print(" | Brightness: ");
    Serial.print(brightness);
    Serial.print(" | Color State: ");
    Serial.println(colorState);

    delay(100); // Wait for a short period before the next loop
}
