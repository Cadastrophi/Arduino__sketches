/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS A0      // left sensor white 900 black 720
#define RS A1      // right sensor white 900 black 670

/*-------definning Outputs------*/
#define leftMotor1 3       // left motor speed
#define leftMotor2 2       // left motor direction
#define rightMotor1 11       // right motor speed
#define rightMotor2 8       // right motor direction
//#define PWR 2       // 5V for PWMD

const float Kp = 0.1; // Proportional gain
const float Ki = 0.01; // Integral gain
const float Kd = 0.1; // Derivative gain

float prevError = 0;
float integral = 0;

// Define global variables for left and right motor speed
int leftSpeed = 0;
int rightSpeed = 0;

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leftValue = analogRead(LS);
  int rightValue = analogRead(RS);

  float error = leftValue - rightValue;
  integral += error;
  float output = Kp * error + Ki * integral + Kd * (error - prevError);
  prevError = error;
  int threshold = 500; // Example threshold value

  leftSpeed = 200; // You may need to set speed for the left motor
  rightSpeed = 200; // Set speed
  analogWrite(leftMotor1, leftSpeed + output);
  analogWrite(rightMotor1, rightSpeed - output);
  Serial.print(error);
  Serial.print(",");
  Serial.println(output);
}