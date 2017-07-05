/* 
Ir and Motor Test v1

This code will be used to avoid walls and other obstacles for my vacuum robot

NOTE: This code only includes the two front sensors
*/

//Motor Pin Variables
const int dcmotor1pin1 = 3; //sets in1 to pin 3
const int dcmotor1pin2 = 5; //sets in2 to pin 5
const int dcmotor2pin1 = 6; //sets in3 to pin 6
const int dcmotor2pin2 = 9; //sets in4to pin 9

//Sensor Pin Variables
const int leftfrontsensor = 0; //sets the left front IR sensor to pin A0
const int rightfrontsensor = 1; //sets the right front IR sensor to pin A1

//PWM Variables
const int pwmMax = 160; //sets pwmMax to 160
const int pwmMin = 70; //sets pwmMin to 70
const int low = 0; //sets low to 0
const int pwmIncrease = 20; //sets pwmIncrease to 20

void setup() {
  
  //Motor Pins
  pinMode(dcmotor1pin1, OUTPUT); //sets the first motor pin to an OUTPUT
  pinMode(dcmotor1pin2, OUTPUT); //sets the second motor pin to an OUTPUT
  pinMode(dcmotor2pin1, OUTPUT); //sets the thrid motor pin to an OUTPUT
  pinMode(dcmotor2pin2, OUTPUT); //sets the fourth motor pin to an OUTPUT

  //Sensor Pins
  pinMode(leftfrontsensor, INPUT); //sets the left front IR sensor to an INPUT
  pinMode(rightfrontsensor, INPUT); //sets the right front IR sensor to an INPUT
}

//Right
void rightMotors(int moveTime){ //moves the left motor forwards and the right motor backwards
    digitalWrite(dcmotor1pin1, low); //sets in1 to 0
    digitalWrite(dcmotor1pin2, pwmMin); //sets in2 to 70pwm
    digitalWrite(dcmotor2pin1, low); //sets in3 to 0
    digitalWrite(dcmotor2pin2, pwmMin); //sets in4 to 70pwm
    delay(moveTime); //delay
}

//Left
void leftMotors(int moveTime){ //moves the left motor backwards and the right motor forwards 
  digitalWrite(dcmotor1pin1, pwmMin); //sets in1 to 70pwm
  digitalWrite(dcmotor1pin2, low); //sets in2 to 0
  digitalWrite(dcmotor2pin1, pwmMin); //sets in3 to 70pwm
  digitalWrite(dcmotor2pin2, low); //sets in4 to 0
  delay(moveTime);
}

//Forwards
void forwardMotors(int moveTime){ //moves both motors forwards
   digitalWrite(dcmotor1pin1, low); //sets in1 to 0
   digitalWrite(dcmotor1pin2, pwmMin); //sets in2 to 70pwm
   digitalWrite(dcmotor2pin1, pwmMin); //sets in3 to 70pwm
   digitalWrite(dcmotor2pin2, low); //sets in4 to 0
   delay(moveTime); //delay
}

//Backwards
void backwardMotors(int moveTime){ //moves the both motors backwards
   digitalWrite(dcmotor1pin1, pwmMin); //sets in1 to 70pwm
   digitalWrite(dcmotor1pin2, low); //sets in2 to 0
   digitalWrite(dcmotor2pin1, low); //sets in3 to 0
   digitalWrite(dcmotor2pin2, pwmMin); //sets in4 to 70pwm
   delay(moveTime); //delay
}

//Stop
void stopMotors(){ //stops both motors
   digitalWrite(dcmotor1pin1, low); //sets in1 to 0
   digitalWrite(dcmotor1pin2, low); //sets in2 to 0
   digitalWrite(dcmotor2pin1, low); //sets in3 to 0
   digitalWrite(dcmotor2pin2, low); //sets in4 to 0
}

//Still working on this code
/*
void backrightMotors(int moveTime){
  digitalWrite(dcmotor1pin1, low);
  digitalWrite(dcmotor1pin2, pwmMin-pwmIncrease);
  digitalWrite(dcmotor2pin1, pwmMin+pwmIncrease);
  digitalWrite(dcmotor2pin2, low);
  delay(moveTime);
}

void backleftMotors(int moveTime){
  digitalWrite(dcmotor1pin1, pwmMin+pwmIncrease);
  digitalWrite(dcmotor1pin2, low);
  digitalWrite(dcmotor2pin1, pwmMin-pwmIncrease);
  digitalWrite(dcmotor2pin2, low);
}
*/

void loop() {

  //IR Sensor Values
  int irValue1 = analogRead(leftfrontsensor); //sets irValue1 to the value of the left Ir sensor
  int irValue2 = analogRead(rightfrontsensor); //sets irValue2 to the value of the right Ir sensor
  int motorDelay = 500; //sets motorDelay to 1 second
  int aproach = 100; //sets aproach to 100 miliseconds
  int noDelay = 0; //sets noDelay to 0 miliseconds
  int minDistance = 400; //sets minDistance to 100

  //Front IR Sensor Conditional Statements
  if (irValue1 >= minDistance && irValue2 <= minDistance) { //if the left front sensor detects an object and the right front sensor doesn't...
  backwardMotors(motorDelay); //move backwards for a second
  rightMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //moves forwards a little
  }
  
  else if (irValue1 <= minDistance && irValue2 >= minDistance){ //if the left front sensor doesn't detect an object and the right front sensor detects an object...
   backwardMotors(motorDelay); //move backwards for a second
   leftMotors(motorDelay); //move left for a second
   forwardMotors(aproach); //move forwards a little
  }
  
  else if (irValue1 >= minDistance && irValue2 >= minDistance){ //if both front sensors detect an object...
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //move forward a little
 
  }
  else if (irValue1 <= minDistance && irValue2 <= minDistance) { //if both front sensors don't detect anything...
    forwardMotors(noDelay); //move forwards 
  }
}
