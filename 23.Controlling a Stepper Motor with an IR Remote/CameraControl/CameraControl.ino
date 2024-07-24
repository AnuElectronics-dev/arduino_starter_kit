#include <IRremote.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048; // Change this to match your motor

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
IRrecv irrecv(7); // IR receiver pin

decode_results results;

void setup() {
    Serial.begin(9600);
    myStepper.setSpeed(15); // Set the speed to 15 RPM
    irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX); // Print the received value to the serial monitor

        // Rotate the stepper motor based on the IR command
        if (results.value == 0xFFA25D) { // Example IR code for "forward"
            myStepper.step(stepsPerRevolution);
        } else if (results.value == 0xFF629D) { // Example IR code for "backward"
            myStepper.step(-stepsPerRevolution);
        }
        
        irrecv.resume(); // Receive the next value
    }
}
