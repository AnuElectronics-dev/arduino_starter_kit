#include <Stepper.h>

const int stepsPerRevolution = 2048; // Change this to match your motor

// Initialize the stepper library on the pins connected to the ULN2003 driver
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    // Set the speed to 15 RPM
    myStepper.setSpeed(15);
    // Initialize the Serial port
    Serial.begin(9600);
}

void loop() {
    // Step one revolution in one direction
    Serial.println("Clockwise");
    myStepper.step(stepsPerRevolution);
    delay(1000);

    // Step one revolution in the other direction
    Serial.println("Counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(1000);
}
