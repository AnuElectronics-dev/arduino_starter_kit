const int buttonPin = 13; // the number of the pushbutton pin
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // the number of the 7-segment display

const byte digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}  // 9
};

int count = 0; // variable to store the count
int buttonState = 0; // variable for reading the pushbutton status

void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT); // initialize the segment pins as outputs
    }
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
    displayDigit(count);
}

void loop() {
    buttonState = digitalRead(buttonPin); // read the state of the pushbutton value
    if (buttonState == HIGH) {
        delay(200); // debounce delay
        count++;
        if (count > 9) count = 0; // reset count after 9
        displayDigit(count);
        while (digitalRead(buttonPin) == HIGH); // wait for button release
    }
}

void displayDigit(int digit) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], digits[digit][i]); // write the digit to the display
    }
}
