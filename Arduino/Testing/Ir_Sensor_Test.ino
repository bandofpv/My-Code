/*
This code is used to print the values from the IR sensor to the serial monitor

CHANGES: Added the pinMode(); function as well. Deleted the int val = 0; 
Put an int for val in loop function

 */
int sensorpin = 0; //sets IR sensor to pin A0

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //start the serial monitor
  pinMode(sensorpin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(sensorpin); //sets val to the value of Ir distance
  Serial.println(val); //prints the value in serial monitor
  delay(100); //sets delay to 0.1 seconds
  
}
