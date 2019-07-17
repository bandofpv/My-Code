/* 
This is just a testing code
*/
//Status Light Varitables
const int redLed = A4; //sets the red led to pin A4
const int greenLed = 13; //sests the green led to pin 13

//Voltage Divider Variables
const int battery = 0; //sets the battery to pin A0
const float voltageBatCharged = 12.68; // Voltage measured when battery fully charged

//Read Battery
float  readBattery(int input){ //input will be the power source your measuring: The Battery!
  int readInput = analogRead(input); //sets readInput to the value of the input
  float voltage = (((readInput*4.9)/1000)*voltageBatCharged ) / 5; // resolution of analog input = 4.9mV per Voltage 
  Serial.print(" Battery= "); //Prints "Battery=" 
  Serial.print(voltage); //Prints the value of the battery after the formula
  return voltage; //returns the voltage
  } 
  
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
const int leftwallsensor = 2; //sets the left wall IR sensor to pin A2
const int rightwallsensor = 3; //sets the right wall IR sensor to pin A3
const int leftgroundsensor = 7; //sets the left ground IR sensor to pin A4
const int rightgroundsensor = 8; //sets the right ground sensor to pin A5
 
//Button Pin Variables
const int leftbutton = 11; //sets the left button to pin 11
const int rightbutton = 10; //sets the right button to pin 12

//PWM Variables
const int pwmMax = 160; //sets pwmMax to 160
const int pwmMin = 70; //sets pwmMin to 70
const int low = 0; //sets low to 0
const int pwmIncrease = 20; //sets pwmIncrease to 20

//Delay Variable
int fivesecDelay = 5; //sets fivesecDelay to 5 seconds
int detectgroundDelay = 75; //sets detectground to 75 milliseconds

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

//Green LED ON
void greenledOn(int delaytime){
  digitalWrite(greenLed, HIGH); //Turns green led on
  delay(delaytime); //Turns green led on for dealytime
}

//Green LED Blink
void greenledBlink(int n, int frequency){ //blink for n seconds at frequency hz
  for (int i=1; i <= n; i++){
    for(int j=1; j<=frequency; j++){
      digitalWrite(greenLed, HIGH); //Turn green led on
      delay((1000/frequency)/2); //Half time on            
      digitalWrite(greenLed, LOW); //Turn green ledoff   
      delay((1000/frequency)/2); //Half time off
    }
  }
}

//Red LED ON
void redledOn(int delaytime){
  digitalWrite(redLed, HIGH); //Turns red led on
  delay(delaytime); //Turns red led on for delaytime
}

//Red LED Blink
void redledBlink(int n, int frequency){ //blink for n seconds at frequency hz
  for (int i=1; i <= n; i++){
    for(int j=1; j<=frequency; j++){
      digitalWrite(redLed, HIGH); //Turn red led on
      delay((1000/frequency)/2); //Half time on            
      digitalWrite(redLed, LOW); //Turn green led off 
      delay((1000/frequency)/2); //Half time off
    }
  }
}

void setup() {

  //Status Light Pins
  pinMode(greenLed, OUTPUT); //sets green led pin to an OUTPUT
  pinMode(redLed, OUTPUT); //sets red led pin to an OUTPUT

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
  Serial.begin(9600); //Starts Serial Monitor
  greenledBlink(fivesecDelay, 1); //5 second blinking delay
}

  //Turn on Fan Motor
void fanmotorOn(){ //turns the fan motor on 
  digitalWrite(fanmotor, HIGH); //Turns fan motor on
  Serial.println("FAN HIGH"); //Prints "FAN HIGH" to serial monitor
}

//Turn off Fan Motor
void fanmotorOff(){ //turns the fan motor off
  digitalWrite(fanmotor, LOW); //Turns fan motor off
  Serial.println("FAN LOW"); //Prints "FAN LOW" to serail monitor
}

//detectground(); function
boolean detectGround(int groundsensor){
  boolean irValueFirst = digitalRead(groundsensor); //creates irValueFirst to the value of groundsensor
  delay(detectgroundDelay); //delay for 50milliseconds
  boolean irValueSecond = digitalRead(groundsensor); //creates irValueSecond to the value of groundsensor
  delay(detectgroundDelay); //delay for 50milliseconds
  boolean irValueThird = digitalRead(groundsensor); //creates irValueThird to the value of groundsensor
  delay(detectgroundDelay); //delay for 50 miliseconds
  boolean irValueFourth = digitalRead(groundsensor); //creates irValueFourth to the value of groundsensor

  return (irValueFirst ||irValueSecond || irValueThird || irValueFourth); //returns 1 if one value is one and returns 0 if all values are 0(Bitwise OR)
}

void loop() {

  //Battery Values
  float batteryVoltage = readBattery(battery); //sets batteryVoltage to the cell voltage of the lipo battery
  float lowBattery = 3.8; //sets lowBattery to 3.8v
  float highBattery = 4.5; //sets highBattery to 4.5v
  
  //IR Sensor Values
  int irValue1 = digitalRead(leftfrontsensor); //sets irValue1 to the value of the left Ir sensor
  int irValue2 = digitalRead(rightfrontsensor); //sets irValue2 to the value of the right Ir sensor
  int irValue3 = analogRead(leftwallsensor); //sets irValue3 to the value of the left wall IR sensor
  int irValue4 = analogRead(rightwallsensor); //sets irValue4 to the value of the right wall IR sensor

  //Distances
  static int wallminDistance = 500; //sets wallminDistance to 500 miliseconds
  
  //Motor Delays
  int motorDelay = 500; //sets motorDelay to 0.5 seconds
  int turnmotorDelay = 300; //sets motorDelay to 300 miliseconds
  int wallmotorDelay = 200; //sets wallmotorDelay to 200 milliseconds
  int motorDelay180 = 1700; //sets motorDelay180 to 1700 milliseconds
  int motorDelay90 = 850; //sets 90motrDelay to 850 miliseconds
  int unstuckmotorDelay = 1000; //sets unstuckmotorDelay to 1 second
  int aproach = 100; //sets aproach to 100 miliseconds
  int noDelay = 0; //sets noDelay to 0 miliseconds

  //Extra Variables
  static int wall = 0; //sets wall to 0
  static int stuck = 0; //sets stuck to 0
  static int corner = 0; //sets corner to 0
  
  //Bumper Values
  int leftbumper = digitalRead(leftbutton); //creates leftbumper to the value of the leftbutton
  int rightbumper = digitalRead(rightbutton); //creates rightbumper to the value of the rightbutton


  //Voltage Divider and Fan Motor Conditional Statements

  //If the battery cell voltage is less than 3.8v or greater than 4.5v
  if (readBattery(battery) <= lowBattery){ 
    fanmotorOff(); //turns the fan motor to LOW or off
    stopMotors(); //stops the robot from moving
    greenledBlink(fivesecDelay, 0); //Blink the green led
  }

  //If the battery cell voltage is greater than 3.8v and less than 4.5v...
  else if (readBattery(battery) >= lowBattery && readBattery(battery) <= highBattery){
    fanmotorOn(); //turns the fan motor to HIGH or on
    greenledOn(noDelay); //Turn on the green led
  }
  
  //Front IR Sensor Conditional Statements
    
  //If the left front sensor detects an object and the right front sensor doesn't...
  if (irValue1 == HIGH && irValue2 == LOW) {
  backwardMotors(motorDelay); //move backwards for a second
  rightMotors(turnmotorDelay); //move left 
  forwardMotors(aproach); //moves forwards a little
  Serial.println("Left HIGH"); //prints "Left HIGH" to serail monitor
  }

  //if the left front sensor doesn't detect an object and the right front sensor detects an object...
  else if (irValue1 == LOW && irValue2 == HIGH){ 
   backwardMotors(motorDelay); //move backwards for a second
   leftMotors(turnmotorDelay); //move left 
   forwardMotors(aproach); //move forwards a little
   Serial.println("Right HIGH"); //prints "Right HIGH" to serial monitor
  }

  //if both front sensors detect an object and wall is equal to 0...
  else if (irValue1 == HIGH && irValue2 == HIGH){ 
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay180); //move left 180 degrees
  forwardMotors(aproach); //move forward a little
  Serial.println("Both HIGH"); //prints "Both HIGH" to serial monitor
  }
/*
  //if both front sensors detect an object and wall is equal to 1...
  else if (irValue1 == HIGH && irValue2 == HIGH && wall == 1){ 
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay90); //move left 90 degrees
  forwardMotors(wallmotorDelay); //move forward 
  leftMotors(motorDelay); //move left 90 degrees
  forwardMotors(wallmotorDelay); //move forward
  wall = 0; //changes wall to 0
  Serial.println("Both HIGH"); //prints "Both HIGH" to serial monitor
  }
  */
  //if both front sensors don't detect anything...
  else if (irValue1 == LOW && irValue2 == LOW) { 
    forwardMotors(noDelay); //move forwards 
    stuck = 0; //changes stuck to 0
    Serial.println("None HIGH"); //prints "None HIGH" to serial monitor
  }

  //Bumper Conditional Statements
  
  //If the left or right bumper is hit...
  if (leftbumper == LOW || rightbumper == LOW){
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay); //move left for a second
  forwardMotors(aproach); //move forward a little
  //stuck++; //increase stuck 
  Serial.println("Bumper HIGH"); //prints "Bumper HIGH" to serial monitor
  }

  //If the left or right bumper isn't hit...
  else if (leftbumper == HIGH || rightbumper == HIGH){
    forwardMotors(noDelay); //move forwards 
    Serial.println("Bumper LOW"); //prints "Bumper LOW" to serial monitor
  }
/*
  //If the left or right bumper is hit and stuck is equal to 3...
  else if ((leftbumper == LOW || rightbumper == LOW) && stuck == 3){
    backwardMotors(motorDelay); //move backwards
    leftMotors(unstuckmotorDelay); //turn left to get unstuck
    stuck = 0; //turn stuck back to 0
    Serial.println("Stuck"); //prints "Stuck" to serial monitor
  }

  //Wall Sensor Conditional Statements

  //If left wall sensor and the left or right front sensors are hit and corner is equal to 0
  if (irValue3 >= wallminDistance && (irValue1 == HIGH || irValue2 == HIGH) && corner == 0){
    backwardMotors(motorDelay); //move backwards
    rightMotors(motorDelay180); //move right 180 degrees
    corner = 1; //turn corner to 1
    Serial.println("Left Corner"); //prints "Left Corner" to serial monitor 
  }

  //If left wall sensor and the left or right front sensors are hit and corner is equal to 1 
  else if (irValue3 >= wallminDistance && (irValue1 == HIGH || irValue2 == HIGH) && corner == 1){
  backwardMotors(motorDelay); //move backwards for a second
  rightMotors(motorDelay90); //move right 90 degrees
  forwardMotors(wallmotorDelay); //move forward 
  rightMotors(motorDelay); //move right 90 degrees
  forwardMotors(wallmotorDelay); //move forward
  corner = 0; //changes corner to 0
  Serial.println("Left Corner"); //prints "Left Corner" to serial monitor 
  }

  //If right wall sensor and the left or right front sensors and wall is equal to 0
  else if (irValue4 >= wallminDistance && (irValue1 == HIGH || irValue2 == HIGH) && wall == 0){
    backwardMotors(motorDelay); //move backwards
    leftMotors(motorDelay180); //turn left 180 degrees
    wall = 1; //changes wall to 1
    Serial.println("Right Corner"); //prints "Right Corner" to serial monitor 
  }

  //If right wall sensor and left or right degrees and wall equals 1
  else if (irValue4 >= wallminDistance && (irValue1 == HIGH || irValue2 == HIGH) && wall == 1){
  backwardMotors(motorDelay); //move backwards for a second
  leftMotors(motorDelay90); //move left 90 degrees
  forwardMotors(wallmotorDelay); //move forward 
  leftMotors(motorDelay); //move left 90 degrees
  forwardMotors(wallmotorDelay); //move forward
  wall = 0; //changes wall to 0
  Serial.println("Right Corner"); //prints "Right Corner" to serail monitor 
  }
*/
  
  //Ground Sensor Conditional Statements

  //If left grond sensor detects a cliff and the right ground sensor doesn't...
  if (detectGround(leftgroundsensor) == LOW && detectGround(rightgroundsensor) == HIGH){
    backwardMotors(motorDelay); //move backwards
    rightMotors(motorDelay); //turn right 
    Serial.println("Left Cliff"); //prints "Left Cliff" to serial monitor 
  }

  ////If left grond sensor doesn't detect a cliff and the right ground sensor does...
  else if (detectGround(leftgroundsensor) == HIGH && detectGround(rightgroundsensor) == LOW){
    backwardMotors(motorDelay); //move backwards
    leftMotors(motorDelay); //turn left
    Serial.println("Right Cliff"); //prints "Right Cliff" to serial monitor 
  }

  //If left ground sensor detects a cliff and the right ground sensor does...
  else if (detectGround(leftgroundsensor) == LOW && detectGround(rightgroundsensor) == LOW){
    backwardMotors(motorDelay); //move backwards
    rightMotors(motorDelay); //turn right 
    Serial.println("Both Cliff"); //prints "Both Cliff" to serial monitor 
  }

  //If both ground sensors don't detect a cliff...
  else if (detectGround(leftgroundsensor) == HIGH && detectGround(rightgroundsensor) == HIGH){
  forwardMotors(noDelay); //move forward
  Serial.println("No Cliff"); //prints "No Cliff" to serial monitor 
  }
}
