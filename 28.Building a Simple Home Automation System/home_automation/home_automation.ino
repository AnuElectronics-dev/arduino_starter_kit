const int buttonPin = 2; // the number of the pushbutton pin
const int relayPin = 3; // the number of the relay pin

int buttonState = 0; // variable for reading the pushbutton status
int lastButtonState = 0; // variable to store the last button state
int relayState = LOW; // variable to store the relay state

void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(relayPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(buttonPin); // read the state of the pushbutton value

    if (buttonState != lastButtonState) { // If the button state has changed
        if (buttonState == HIGH) { // If the current state is HIGH then the button was pressed
            relayState = !relayState; // toggle the relay state
            digitalWrite(relayPin, relayState); // turn relay on/off
            Serial.print("Relay state: ");
            Serial.println(relayState);
        }
        delay(50); // debounce delay
    }

    lastButtonState = buttonState; // save the current state as the last state
}
