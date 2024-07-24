#include <IRremote.h>

const int RECV_PIN = 7;
const int RED_PIN = 4;
const int GREEN_PIN = 3;
const int BLUE_PIN = 2;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        
        switch (results.value) {
            case 0xFFA25D: // Button 1
                setColor(255, 0, 0); // Red
                break;
            case 0xFF629D: // Button 2
                setColor(0, 255, 0); // Green
                break;
            case 0xFFE21D: // Button 3
                setColor(0, 0, 255); // Blue
                break;
            case 0xFF22DD: // Button 4
                setColor(255, 255, 0); // Yellow
                break;
            case 0xFF02FD: // Button 5
                setColor(0, 255, 255); // Cyan
                break;
            case 0xFFC23D: // Button 6
                setColor(255, 0, 255); // Magenta
                break;
            case 0xFFE01F: // Button 7
                setColor(255, 255, 255); // White
                break;
            case 0xFFA857: // Button 8
                setColor(0, 0, 0); // Off
                break;
        }

        irrecv.resume(); // Receive the next value
    }
}

void setColor(int red, int green, int blue) {
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}
