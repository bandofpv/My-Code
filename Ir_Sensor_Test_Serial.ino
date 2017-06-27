int sensorpin = 0; //sets IR sensor to pin A0
int val = 0;  //variables to store the IR sensor values
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //start the serial monitor
  
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(sensorpin); //sets value to the value of Ir distance
  if (val >= 200){
    Serial.println("INCOMING!");
  }
  else {
    Serial.println("KEEP MOVING!");
  }
}
