#include <IRremote.h>
#include <Servo.h>

const int RECV_PIN = 7; // Pin connected to the IR receiver
const int SERVO_PIN = 3; // Pin connected to the servo motor

IRrecv irrecv(RECV_PIN);
decode_results results;
Servo myservo;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the IR receiver
    myservo.attach(SERVO_PIN); // Attach the servo to pin 3
    myservo.write(90); // Initialize the servo to the middle position
}

void loop() {
    if (irrecv.decode(&results)) {
        unsigned int value = results.value;
        Serial.println(value);

        // Rotate the servo based on the IR command
        if (value == 0xFF30CF) { // Button 1
            myservo.write(0); // Move to 0 degrees
        } else if (value == 0xFF18E7) { // Button 2
            myservo.write(45); // Move to 45 degrees
        } else if (value == 0xFF7A85) { // Button 3
            myservo.write(90); // Move to 90 degrees
        } else if (value == 0xFF10EF) { // Button 4
            myservo.write(135); // Move to 135 degrees
        } else if (value == 0xFF38C7) { // Button 5
            myservo.write(180); // Move to 180 degrees
        }

        irrecv.resume(); // Receive the next value
    }
}
