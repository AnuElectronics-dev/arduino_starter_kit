#include <Stepper.h>

const int stepsPerRevolution = 2048; // Number of steps per revolution for the stepper motor
const int potPin = A0;  // Pin connected to the potentiometer

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int potValue = analogRead(potPin); // Read the potentiometer value
    int stepSpeed = map(potValue, 0, 1023, 1, 10); // Map the value to a range for stepper speed

    myStepper.setSpeed(stepSpeed * 10); // Set the motor speed
    myStepper.step(stepsPerRevolution / 100); // Move the motor a small number of steps

    // Print the potentiometer value and the corresponding speed
    Serial.print("Potentiometer Value: ");
    Serial.print(potValue);
    Serial.print(" | Stepper Speed: ");
    Serial.println(stepSpeed * 10);

    delay(100); // Wait for a short period before the next loop
}
