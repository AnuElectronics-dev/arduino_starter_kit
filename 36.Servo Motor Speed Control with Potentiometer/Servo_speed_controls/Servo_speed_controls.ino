#include <Servo.h>

const int potPin = A0;  // Pin connected to the potentiometer
const int servoPin = 3; // Pin connected to the servo motor

Servo myservo;

void setup() {
    myservo.attach(servoPin); // Attach the servo to pin 3
    myservo.write(90); // Initialize the servo to the middle position
    Serial.begin(9600);
}

void loop() {
    int potValue = analogRead(potPin); // Read the potentiometer value
    int angle = map(potValue, 0, 1023, 0, 180); // Map the value to a range from 0 to 180

    myservo.write(angle); // Set the servo position
    delay(15); // Wait for the servo to reach the position

    // Print the potentiometer value and the corresponding angle
    Serial.print("Potentiometer Value: ");
    Serial.print(potValue);
    Serial.print(" | Servo Angle: ");
    Serial.println(angle);
}
