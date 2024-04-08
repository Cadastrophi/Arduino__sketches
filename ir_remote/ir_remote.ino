#include <Servo.h>
#include <IRremote.h>

IRrecv IR(5);
Servo myServo;

const int servoPin = 9;

void setup() {
  IR.enableIRIn();
  myServo.attach(servoPin);
  myServo.write(90);
  Serial.begin(9600);
  // Additional setup code here, if needed
}

void loop() {
  
  if (IR.decode()) {
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if (IR.decodedIRData.decodedRawData == 0xEA15FF00) {
      myServo.write(110);
      delay(500);
    }  
    if (IR.decodedIRData.decodedRawData == 0xF807FF00) {
      myServo.write(70);
      delay(500);
      
    }
    delay(500);
    IR.resume();
  }
}