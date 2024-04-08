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
  if (Serial.available() > 0) {
    angle = Serial.parseInt(); // Read the user input angle
    if(angle!=0){
      targetAngle=angle;
    }

    if (angle >= 0 && angle <= 180) {
      Serial.println(targetAngle);
      myservo.write(targetAngle); // Control the servo to go to the specified angle
      delay(1000); // Wait for the servo to reach the position
    } else {
      Serial.println("Invalid angle. Please enter an angle between 0 and 180.");
    }
  }
}