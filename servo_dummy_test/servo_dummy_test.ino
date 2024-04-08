#include <Servo.h>

Servo myservo; // Create a servo object to control the servo
int angle=10;
int targetAngle = 10;
void setup() {
  myservo.attach(9); // Attach the servo to pin 9
  myservo.write(90); // Rotate the servo slowly to 0 degrees immediately
  Serial.begin(9600); // Initialize serial communication
}
void loop() {
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
}
