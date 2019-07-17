/*
This code is used to test the direction of the motors.
 */
const int dcmotor1pin1 = 3; //sets in1 to pin 3
const int dcmotor1pin2 = 5; //sets in2 to pin 5
const int dcmotor2pin1 = 6; //sets in3 to pin 6
const int dcmotor2pin2 = 9; //sets in4to pin 9
const int pwmMax = 160; //sets pwmMax to 160
const int pwmMin = 70; //sets pwmMin to 70

void setup() {
  // put your setup code here, to run once:
  pinMode(dcmotor1pin1, OUTPUT); //sets the first motor pin to an OUTPUT
  pinMode(dcmotor1pin2, OUTPUT); //sets the second motor pin to an OUTPUT
  pinMode(dcmotor2pin1, OUTPUT); //sets the thrid motor pin to an OUTPUT
  pinMode(dcmotor2pin2, OUTPUT); //sets the fourth motor pin to an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(dcmotor1pin1, pwmMin+20); //sets in1 to 90pwm
   digitalWrite(dcmotor1pin2, 0); //sets in2 to 0
   digitalWrite(dcmotor2pin1, 0); //sets in3 to 0
   digitalWrite(dcmotor2pin2, pwmMin+20); //sets in4 to 90pwm
}
