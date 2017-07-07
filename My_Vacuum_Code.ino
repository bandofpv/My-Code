/* 
Ir and Motor Test v2

This code will be used to avoid walls and other obstacles for my vacuum robot
*/

//Voltage Divider Variables
const int battery = 0; //sets the battery to pin A0
const float voltageBatCharged = 12.68; // Voltage measured when battery fully charged

//Fan Motor Pin Variables
const int fanmotor = 12; //sets the fan motor to pin 12

//Motor Pin Variables
const int dcmotor1pin1 = 3; //sets in1 to pin 3
const int dcmotor1pin2 = 5; //sets in2 to pin 5
const int dcmotor2pin1 = 6; //sets in3 to pin 6
const int dcmotor2pin2 = 9; //sets in4to pin 9

//IR Sensor Pin Variables
const int leftfrontsensor = 2; //sets the left front IR sensor to pin 2
const int rightfrontsensor = 4; //sets the right front IR sensor to pin 4
const int leftwallsensor = 2; //sets the left wall IR sensor to pin A2
const int rightwallsensor = 3; //sets the right wall IR sensor to pin A3
const int leftgroundsensor = 4; //sets the left ground IR sensor to pin A4
const int rightgroundsensor = 5; //sets the right ground sensor to pin A5 

//Button Pin Variables
const int leftbutton = 11; //sets the left button to pin 11
const int rightbutton = 12; //sets the right button to pin 12

//PWM Variables
const int pwmMax = 160; //sets pwmMax to 160
const int pwmMin = 70; //sets pwmMin to 70
const int low = 0; //sets low to 0
const int pwmIncrease = 20; //sets pwmIncrease to 20

void setup() {

  //Voltage Divider Pin
  pinMode(battery, INPUT); //sets the battery to an INPUT
  
  //Fan Motor Pin
  pinMode(fanmotor, OUTPUT); //sets the fan motor to an OUTPUT
  
  //Motor Pins
  pinMode(dcmotor1pin1, OUTPUT); //sets the first motor pin to an OUTPUT
  pinMode(dcmotor1pin2, OUTPUT); //sets the second motor pin to an OUTPUT
  pinMode(dcmotor2pin1, OUTPUT); //sets the thrid motor pin to an OUTPUT
  pinMode(dcmotor2pin2, OUTPUT); //sets the fourth motor pin to an OUTPUT

  //IR Sensor Pins
  pinMode(leftfrontsensor, INPUT); //sets the left front IR sensor to an INPUT
  pinMode(rightfrontsensor, INPUT); //sets the right front IR sensor to an INPUT
  pinMode(leftwallsensor, INPUT); //sets the left wall IR sensor to an INPUT
  pinMode(rightwallsensor, INPUT); //sets the right wall IR sensor to an INPUT
  pinMode(leftgroundsensor, INPUT); //sets the left ground IR sensor to an INPUT
  pinMode(rightgroundsensor, INPUT); //sets the right ground IR sensor to an INPUT

  //Button Pins
  pinMode(leftbutton, INPUT_PULLUP); //sets the left button to an INPUT_PULLUP
  pinMode(rightbutton, INPUT_PULLUP); //sets the right button to an INPUT_PULLUP
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

//Turn on Fan Motor
void fanmotorOn(){ //turns the fan motor on 
  digitalWrite(fanmotor, HIGH); 
}

//Turn off Fan Motor
void fanmotorOff(){ //turns the fan motor off
  digitalWrite(fanmotor, LOW); 
}

//Read Battery
float  readBattery(int input){ //input will be the power source your measuring: The Battery!
  int readInput = analogRead(input); //sets readInput to the value of the input
  float voltage = (((readInput*4.9)/1000)*voltageBatCharged ) / 5; // resolution of analog input = 4.9mV per Voltage 
  Serial.print(" Battery= "); //Prints "Battery=" 
  Serial.print(voltage); //Prints the value of the battery after the formula
  return voltage; //returns the voltage
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
  int irValue1 = digitalRead(leftfrontsensor); //sets irValue1 to the value of the left front IR sensor
  int irValue2 = digitalRead(rightfrontsensor); //sets irValue2 to the value of the right front IR sensor
  int irValue3 = analogRead(leftwallsensor); //sets irValue3 to the value of the left wall IR sensor
  int irValue4 = analogRead(rightwallsensor); //sets irValue4 to the value of the right wall IR sensor
  int irValue5 = analogRead(leftgroundsensor); //sets irValue5 to the value of the left ground IR sensor
  int irValue6 = analogRead(rightgroundsensor); //sets irValue6 to the value of the right ground IR sensor

  //Mininmum Distances
  int frontminDistance = 1; //sets frontminDistance to 1
  int wallminDistance = 600; //sets wallminDistance to 600

  //Motor Delays
  int motorDelay = 500; //sets motorDelay to 0.5 seconds
  int longmotorDelay = 1000; //sets longmotorDelay to 1 second
  int aproach = 100; //sets aproach to 100 miliseconds
  int noDelay = 0; //sets noDelay to 0 seconds

  //Voltage Divider and Fan Motor Conditional Statements

  //If the battery cell voltage is less than 3.8v...
  if (readBattery(battery) <= 3.8){ 
    fanmotorOff(); //turns the fan motor to LOW or off
  }

  //If the battery cell voltage is greater than 3.8v and less than 4.5v...
  else if (readBattery(battery) >= 3.8 && readBattery(battery) <= 4.5){
    fanmotorOn(); //turns the fan motor to HIGH or on
  }

  //Front IR Sensor Conditional Statements

  //If the left front sensor detects an object and the right front sensor doesn't...
  if (irValue1 >= frontminDistance && irValue2 <= frontminDistance) {
  backwardMotors(motorDelay); //move backwards for a second
  rightMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //moves forwards a little
  }

  //if the left front sensor doesn't detect an object and the right front sensor detects an object...
  else if (irValue1 <= frontminDistance && irValue2 >= frontminDistance){ 
   backwardMotors(motorDelay); //move backwards for a second
   leftMotors(motorDelay); //move left for a second
   forwardMotors(aproach); //move forwards a little
  }

  //if both front sensors detect an object...
  else if (irValue1 >= frontminDistance && irValue2 >= frontminDistance){ 
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //move forward a little
  }

  //if both front sensors don't detect anything...
  else if (irValue1 <= frontminDistance && irValue2 <= frontminDistance) { 
    forwardMotors(noDelay); //move forwards 
  }

  //Wall IR Sensor Conditional Statements
  if (irValue3 <= wallminDistance && irValue4 <= wallminDistance){
    leftMotors(motorDelay);
  }
  else if (irValue3 >= wallminDistance){
    rightMotors(motorDelay);
  }
  else if (irValue3 >= wallminDistance && irValue1 >= frontminDistance) {
    backwardMotors(motorDelay);
    rightMotors(longmotorDelay);
  }
  else if (irValue4 
  
  

  //Ground IR Sensor Conditional Statements

  //Button Conditional Statements
}
