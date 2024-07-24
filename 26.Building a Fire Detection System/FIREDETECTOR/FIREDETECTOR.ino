const int flamePin = 2;   // the number of the flame sensor pin
const int irPin = 7;      // the number of the IR sensor pin
const int buzzerPin = 3;  // the number of the buzzer pin
const int redPin = 4;     // the number of the red LED pin
const int greenPin = 5;   // the number of the green LED pin
const int bluePin = 6;    // the number of the blue LED pin

int flameState = 0; // variable for reading the flame sensor status
int irState = 0;    // variable for reading the IR sensor status

void setup() {
    pinMode(flamePin, INPUT);
    pinMode(irPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    flameState = digitalRead(flamePin); // read the state of the flame sensor
    irState = digitalRead(irPin);       // read the state of the IR sensor

    if (flameState == LOW || irState == LOW) {
        // Flame or heat detected
        digitalWrite(buzzerPin, HIGH); // turn on the buzzer
        digitalWrite(redPin, HIGH);    // turn on the red LED
        digitalWrite(greenPin, LOW);   // turn off the green LED
        digitalWrite(bluePin, LOW);    // turn off the blue LED
        Serial.println("Fire detected!");
    } else {
        // No flame or heat detected
        digitalWrite(buzzerPin, LOW);  // turn off the buzzer
        digitalWrite(redPin, LOW);     // turn off the red LED
        digitalWrite(greenPin, HIGH);  // turn on the green LED
        digitalWrite(bluePin, LOW);    // turn off the blue LED
        Serial.println("No fire.");
    }

    delay(200); // delay for stability
}
