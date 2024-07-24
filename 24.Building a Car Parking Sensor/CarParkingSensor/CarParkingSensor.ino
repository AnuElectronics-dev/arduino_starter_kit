const int trigPin = 9;
const int echoPin = 10;
const int redLed = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int buzzer = 5;

long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(redLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Clear the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Set the trigPin HIGH for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echoPin
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance
    distance = duration * 0.034 / 2;

    // Print the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    // Control the LEDs and buzzer based on the distance
    if (distance < 10) {
        digitalWrite(redLed, HIGH);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, LOW);
        tone(buzzer, 1000); // Buzzer on
    } else if (distance < 20) {
        digitalWrite(redLed, LOW);
        digitalWrite(yellowLed, HIGH);
        digitalWrite(greenLed, LOW);
        noTone(buzzer); // Buzzer off
    } else {
        digitalWrite(redLed, LOW);
        digitalWrite(yellowLed, LOW);
        digitalWrite(greenLed, HIGH);
        noTone(buzzer); // Buzzer off
    }

    delay(500); // Delay between measurements
}
