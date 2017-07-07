/* 
Ir, Motor, and Fan Test V1

This code will be used to avoid walls and other obstacles for my vacuum robot
This will also turn on the fan motor!

NOTE: This code only includes the two front sensors
*/

//Voltage Divider Variables
const int battery = 0; //sets the battery to pin A0
const float voltageBatCharged = 12.68; // Voltage measured when battery fully charged

//Fan Motor Pin Variable
const int fanmotor = 12; //sets the fan motor to pin 12

//Motor Pin Variables
const int dcmotor1pin1 = 3; //sets in1 to pin 3
const int dcmotor1pin2 = 5; //sets in2 to pin 5
const int dcmotor2pin1 = 6; //sets in3 to pin 6
const int dcmotor2pin2 = 9; //sets in4to pin 9

//Sensor Pin Variables
const int leftfrontsensor = 2; //sets the left front IR sensor to pin 2
const int rightfrontsensor = 4; //sets the right front IR sensor to pin 4

//PWM Variables
const int pwmMax = 160; //sets pwmMax to 160
const int pwmMin = 70; //sets pwmMin to 70
const int low = 0; //sets low to 0
const int pwmIncrease = 20; //sets pwmIncrease to 20

//Delay Variable
int threesecDelay = 3000; //sets threesecDelay to 3 seconds

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

  //Sensor Pins
  pinMode(leftfrontsensor, INPUT); //sets the left front IR sensor to an INPUT
  pinMode(rightfrontsensor, INPUT); //sets the right front IR sensor to an INPUT

  Serial.begin(9600); //Starts Serial Monitor
  delay(threesecDelay);
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
  delay(moveTime); //delay
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
  int irValue1 = digitalRead(leftfrontsensor); //sets irValue1 to the value of the left Ir sensor
  int irValue2 = digitalRead(rightfrontsensor); //sets irValue2 to the value of the right Ir sensor

  //Motor Delays
  int motorDelay = 500; //sets motorDelay to 1 second
  int aproach = 100; //sets aproach to 100 miliseconds
  int noDelay = 0; //sets noDelay to 0 miliseconds
  int frontminDistance = 1; //sets minDistance to 1

  //Voltage Divider and Fan Motor Conditional Statements

  //If the battery cell voltage is less than 3.8v...
  if (readBattery(battery) <= 3.8){ 
    fanmotorOff(); //turns the fan motor to LOW or off
    stopMotors(); //stops the robot from moving
  }

  //If the battery cell voltage is greater than 3.8v and less than 4.5v...
  else if (readBattery(battery) >= 3.8 && readBattery(battery) <= 4.5){
    fanmotorOn(); //turns the fan motor to HIGH or on
  }
  
  //Front IR Sensor Conditional Statements
    
  //If the left front sensor detects an object and the right front sensor doesn't...
  if (irValue1 == HIGH && irValue2 == LOW) {
  backwardMotors(motorDelay); //move backwards for a second
  rightMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //moves forwards a little
  Serial.println("Left HIGH"); //prints "Left HIGH" to serail monitor
  }

  //if the left front sensor doesn't detect an object and the right front sensor detects an object...
  else if (irValue1 == LOW && irValue2 == HIGH){ 
   backwardMotors(motorDelay); //move backwards for a second
   leftMotors(motorDelay); //move left for a second
   forwardMotors(aproach); //move forwards a little
   Serial.println("Right HIGH"); //prints "Right HIGH" to serial monitor
  }

  //if both front sensors detect an object...
  else if (irValue1 == HIGH && irValue2 == HIGH){ 
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //move forward a little
  Serial.println("Both HIGH"); //prints "Both HIGH" to serial monitor
  }

  //if both front sensors don't detect anything...
  else if (irValue1 == LOW && irValue2 == LOW) { 
    forwardMotors(noDelay); //move forwards 
    Serial.println("None HIGH"); //prints "None HIGH" to serial monitor
  }
}
