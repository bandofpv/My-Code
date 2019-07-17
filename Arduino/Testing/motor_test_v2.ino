const int dcmotor1 = 9; //number of the first motor pin
const int dcmotor2 = 6; //number of the second motor pin
const int dcmotor3 = 5; //number of the third motor pin
const int dcmotor4 = 3; //number of the 4th motor pin

void setup() {
  // put your setup code here, to run once:
  pinMode(dcmotor1, OUTPUT); //sets the first motor pin to an OUTPUT
  pinMode(dcmotor2, OUTPUT); //sets the second motor pin to an OUTPUT
  pinMode(dcmotor3, OUTPUT); //sets the third motor pin to an OUTPUT
  pinMode(dcmotor4, OUTPUT); //sets the fourth motor pin to an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dcmotor1, 0); //moves motor
  digitalWrite(dcmotor2, 180); //moves motor
  digitalWrite(dcmotor3, 0); //changes the motor direction
  digitalWrite(dcmotor4, 70); //changes the motor direction
 
}
