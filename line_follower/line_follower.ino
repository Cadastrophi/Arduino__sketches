/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS A0      // left sensor white 900 black 720
#define RS A1      // right sensor white 900 black 670

/*-------definning Outputs------*/
#define LM1 3       // left motor speed
#define LM2 2       // left motor direction
#define RM1 11       // right motor speed
#define RM2 8       // right motor direction
//#define PWR 2       // 5V for PWMD

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  //pinMode(PWR, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int lightleft = analogRead(LS); // white 900 black 770 (835)
  Serial.println(lightleft); //

  int lightright = analogRead(RS); // white 840 black 710 (775)
  Serial.println(lightright);
  
  //Greater than is white, less than is black
  //Right white = 860, black = 785
  //Left White = 870, black = 815
  int left_col = 835, right_col = 775;
    
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
  
  if (analogRead(LS)>left_col && analogRead(RS)>right_col)     // Move Forward
  {
    digitalWrite(LM1, 0.5*255);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, 0.5*255);
    digitalWrite(RM2, LOW);
  }
  
  if( analogRead(LS)<left_col && analogRead(RS)>right_col )    // Turn left
  {--
    analogWrite(LM1, 0.5*255);
    digitalWrite(LM2, HIGH);
    analogWrite(RM1, 0.5*255);
    digitalWrite(RM2, LOW);
  }
  
  if( analogRead(LS)>left_col && analogRead(RS)<right_col )    // turn right
  {
    analogWrite(LM1, 0.5*255);
    digitalWrite(LM2, LOW);
    analogWrite(RM1, 0.5*255);
    digitalWrite(RM2, HIGH);
  }
  
  if(analogRead(LS)<left_col && analogRead(RS)<right_col )     // stop
  {
    analogWrite(LM1, 0.25*255);
    digitalWrite(LM2, LOW);
    analogWrite(RM1, 0.25*255);
    digitalWrite(RM2, LOW);
  }
}
