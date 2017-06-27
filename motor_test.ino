const int dcmotor1 = 9; //number of the first motor pin
const int dcmotor2 = 6; //number of the second motor pin
const int dcmotor3 = 5; //number of the third motor pin
const int dcmotor4 = 3; //number of the 4th motor pin
const int enA = 10; //number of the enable pin A
const int enB = 11; //number of the enable pin B
void setup() {
  // put your setup code here, to run once:
  pinMode(dcmotor1, OUTPUT); //sets the first motor pin to an OUTPUT
  pinMode(dcmotor2, OUTPUT); //sets the second motor pin to an OUTPUT
  pinMode(dcmotor3, OUTPUT); //sets the third motor pin to an OUTPUT
  pinMode(dcmotor4, OUTPUT); //sets the fourth motor pin to an OUTPUT
  pinMode(enA, OUTPUT); //sets the enable pin A to an OUTPUT
  pinMode(enB, OUTPUT); //sets the enalble pin B to an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dcmotor1, LOW); //moves motor
  digitalWrite(dcmotor2, HIGH); //moves motor
  analogWrite(enA, 200); //sets it to 200 microseconds almost 255=fulspeed
  digitalWrite(dcmotor3, LOW); //changes the motor direction
  digitalWrite(dcmotor4, HIGH); //changes the motor direction
  analogWrite(enB, 50); //sets it to 50 microseconds very slow!
  delay(1000); //sets the delay to 1 second before looping again
 
}
