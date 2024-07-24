#include <Servo.h>

Servo servo1;  // Create object for Servo motor 1

int position = 0;     // Variable to store the position

void setup()
{
  servo1.attach(3);   // Set PWM pin 3 for Servo motor 1
}
void loop()
{
  // Rotating Servo motor 1 in Anti clockwise from 0 degree to 180 degree
  for (position = 0; position <= 180; position++) 
  { 
    servo1.write(position);  // Set position of Servo motor 1
    delay(10);                     
  }
  
  // Rotating Servo motor 1 in clockwise from 180 degree to 0 degree
  for (position = 180; position >= 0; position--) 
  { 
    servo1.write(position);  // Set position of Servo motor 1
    delay(15);               // Short delay to control the speed
  }
  
}