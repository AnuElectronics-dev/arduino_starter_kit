#include <Servo.h>

Servo myservo; // create servo object to control a servo
int sensorPin = 2; // IR sensor pin
int ledPin = 4; // LED pin
int sensorValue = 0; // variable to store the sensor value

void setup() {
    myservo.attach(3); // attaches the servo on pin 3 to the servo object
    pinMode(sensorPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600); // start serial communication
}

void loop() {
    sensorValue = digitalRead(sensorPin); // read the sensor value
    Serial.println(sensorValue); // print the sensor value to the serial monitor

    if (sensorValue == HIGH) {
        digitalWrite(ledPin, LOW); // turn on the LED (since it is connected to GND)
        myservo.write(90); // rotate servo to 90 degrees to open the liquid flow
    } else {
        digitalWrite(ledPin, HIGH); // turn off the LED
        myservo.write(0); // rotate servo back to 0 degrees to close the liquid flow
    }
}
