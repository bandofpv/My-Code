/* 
Ir and Motor Test v1

This code will 
*/
const int sensorpin1 = 0; //sets the left IR sensor to pin A0
const int sensorpin2 = 1; //sets the right IR sensor to pin A1
int irValue1 = 0;  //variable to store the IR sensor value
int irValue2 = 0;  //variable to store the IR sensor value
const int dcmotor1pin1 = 3; //sets in1 to pin 3
const int dcmotor1pin2 = 5; //sets in2 to pin 5
const int dcmotor2pin1 = 6; //sets in3 to pin 6
const int dcmotor2pin2 = 9; //sets in4to pin 9
const int enA = 10;
const int enB = 11; 

void setup() {
  // put your setup code here, to run once:
  pinMode(dcmotor1pin1, OUTPUT); //sets the first motor pin to an OUTPUT
  pinMode(dcmotor1pin2, OUTPUT); //sets the second motor pin to an OUTPUT
  pinMode(dcmotor2pin1, OUTPUT); //sets the thrid motor pin to an OUTPUT
  pinMode(dcmotor2pin2, OUTPUT); //sets the fourth motor pin to an OUTPUT
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void rightMotors(int moveTime){ //moves the motors forwards
    digitalWrite(dcmotor1pin1, LOW); //sets in1 to 0
    digitalWrite(dcmotor1pin2, HIGH); //sets in2 to 70pwm
    analogWrite(enA, 50);
    digitalWrite(dcmotor2pin1, LOW); //sets in3 to 0
    digitalWrite(dcmotor2pin2, HIGH); //sets in4 to 70pwm
    analogWrite(enB, 50);
    delay(moveTime); //delay
}

void leftMotors(int moveTime){ //moves the motors backwards
  digitalWrite(dcmotor1pin1, HIGH); //sets in1 to 70pwm
  digitalWrite(dcmotor1pin2, LOW); //sets in2 to 0
  analogWrite(enA, 50);
  digitalWrite(dcmotor2pin1, HIGH); //sets in3 to 70pwm
  digitalWrite(dcmotor2pin2, LOW); //sets in4 to 0
  analogWrite(enB, 50);
  delay(moveTime);
}

void forwardMotors(int moveTime){ //moves the left motor forward and the right backwards
   digitalWrite(dcmotor1pin1, LOW); //sets in1 to 0
   digitalWrite(dcmotor1pin2, HIGH); //sets in2 to 70pwm
   analogWrite(enA, 50);
   digitalWrite(dcmotor2pin1, HIGH); //sets in3 to 70pwm
   digitalWrite(dcmotor2pin2, LOW); //sets in4 to 0
   analogWrite(enB, 50);
   delay(moveTime); //delay
}

void backwardMotors(int moveTime){ //moves the lift motor backwards and the right forwards
   digitalWrite(dcmotor1pin1, HIGH); //sets in1 to 70pwm
   digitalWrite(dcmotor1pin2, LOW); //sets in2 to 0
   analogWrite(enA, 50);
   digitalWrite(dcmotor2pin1, LOW); //sets in3 to 0
   digitalWrite(dcmotor2pin2, HIGH); //sets in4 to 70pwm
   analogWrite(enB, 50);
   delay(moveTime); //delay
}

void stopMotors(){ //stops both motors
   digitalWrite(dcmotor1pin1, LOW); //sets in1 to 0
   digitalWrite(dcmotor1pin2, LOW); //sets in2 to 0
   digitalWrite(dcmotor2pin1, LOW); //sets in3 to 0
   digitalWrite(dcmotor2pin2, LOW); //sets in4 to 0
}
/*
void backrightMotors(int moveTime){
  digitalWrite(dcmotor1pin1, 0);
  digitalWrite(dcmotor1pin2, pwmMin-20);
  digitalWrite(dcmotor2pin1, pwmMin+20);
  digitalWrite(dcmotor2pin2, 0);
  delay(moveTime);
}

void backleftMotors(int moveTime){
  digitalWrite(dcmotor1pin1, pwmMin+20);
  digitalWrite(dcmotor1pin2, 0);
  digitalWrite(dcmotor2pin1, pwmMin-20);
  digitalWrite(dcmotor2pin2, 0);
}
*/
void loop() {
  // put your main code here, to run repeatedly:
  irValue1 = analogRead(sensorpin1); //sets irValue1 to the value of the left Ir sensor
  irValue2 = analogRead(sensorpin2); //sets irValue2 to the value of the right Ir sensor
  int motorDelay = 500; //sets motorDelay to 1 second
  int aproach = 100; //sets aproach to 100 miliseconds
  int noDelay = 0; //sets noDelay to 0 miliseconds
  int minDistance = 400; //sets minDistance to 100
  
  if (irValue1 >= minDistance && irValue2 <= minDistance) { //if the left sensor detects an object and the right doesn't...
  backwardMotors(motorDelay); //move backwards for a second
  rightMotors(motorDelay); //move left for a second
  forwardMotors(aproach);
  }
  else if (irValue1 <= minDistance && irValue2 >= minDistance){ //if the left sensor doesn't detect an object and the right sensor detects an object...
   backwardMotors(motorDelay); //move backwards for a second
   leftMotors(motorDelay); //move left for a second
   forwardMotors(aproach);
  }
  else if (irValue1 >= minDistance && irValue2 >= minDistance){ //if both sensors detect an object...
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //move forward a little
 
  }
  else if (irValue1 <= minDistance && irValue2 <= minDistance) { //if both motors don't detect anything...
    forwardMotors(noDelay); //move forwards for ever
  }
}
