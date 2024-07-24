// Define segment pins
const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// Segment patterns for digits 0-9 (assuming common cathode)
const byte digitPatterns[10] = {
    B00111111, // 0
    B00000110, // 1
    B01011011, // 2
    B01001111, // 3
    B01100110, // 4
    B01101101, // 5
    B01111101, // 6
    B00000111, // 7
    B01111111, // 8
    B01101111  // 9
};

void setup() {
    // Set segment pins as outputs
    for (int i = 0; i < 8; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
}

void loop() {
    for (int digit = 0; digit < 10; digit++) {
        displayDigit(digit);
        delay(1000); // Display each digit for 1 second
    }
}

void displayDigit(int digit) {
    for (int i = 0; i < 8; i++) {
        digitalWrite(segmentPins[i], bitRead(digitPatterns[digit], i));
    }
}
