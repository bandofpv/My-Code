const int fanmotor = 12; //number of fan motor pin

void setup() {
  // put your setup code here, to run once:
  pinMode(fanmotor, OUTPUT); //setting the fan motor pin to an OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(fanmotor, HIGH); //turn on the fan motor. 
 
}
