/*
This code includes the formula to get the distance in centimeters from the IR Sensor
*/

#define sensor A0 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)

void setup() {
  Serial.begin(9600); // start the serial port
}

void loop() {
  
  // 5v
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  delay(100); // slow down serial port 
  
  Serial.println(distance);   // print the distance
  
}
