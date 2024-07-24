#include <Servo.h>

const int VRx = A0; // Joystick VRx pin
const int VRy = A1; // Joystick VRy pin
const int SW = 2;   // Joystick switch pin

Servo myservo; // create servo object to control a servo

void setup() {
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(SW, INPUT_PULLUP);

    myservo.attach(3); // attaches the servo on pin 3 to the servo object

    Serial.begin(9600);
}

void loop() {
    int xPosition = analogRead(VRx);
    int yPosition = analogRead(VRy);
    int switchState = digitalRead(SW);

    // Map the joystick position to servo angle
    int servoAngle = map(xPosition, 0, 1023, 0, 180);

    // Set the servo position
    myservo.write(servoAngle);

    // Display joystick position and servo angle
    Serial.print("X: ");
    Serial.print(xPosition);
    Serial.print(" | Y: ");
    Serial.print(yPosition);
    Serial.print(" | Switch: ");
    Serial.print(switchState);
    Serial.print(" | Servo Angle: ");
    Serial.println(servoAngle);

    delay(200);
}
