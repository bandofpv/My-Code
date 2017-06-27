int sensorpin = 0; //sets IR sensor to pin A0
int val = 0;  //variables to store the IR sensor values
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //start the serial monitor
  
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(sensorpin); //sets value to the value of Ir distance
  Serial.println(val); //prints the value in serial monitor
  delay(100); //sets delay to 0.1 seconds
  
}
