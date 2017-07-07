/*
This code will be used to calculate the voltage of a 3cell lipo battery using a voltage divider.
NOTE:This code will only calculate the cell voltage so make sure the lipo is balanced.
If not, you will get false readings.
If the battery voltage is sufficient, the fan will turn on
 */
//Fan Motor Pin Variable
const int fanmotor = 12; //sets the fan motor to pin 12

//Variables
const int battery = 0; //sets the battery to pin A0
const float voltageBatCharged = 12.68; // Voltage measured when battery fully charged

void setup() {
  //Setup
  pinMode(battery, INPUT); //sets the battery to an INPUT
  Serial.begin(9600); //Starts the Serial Monitor
   //Fan Motor Pin
  pinMode(fanmotor, OUTPUT); //sets the fan motor to an OUTPUT
  
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
  Serial.println(" Battery= "); //Writes "Battery=" to the serial monitors
  Serial.println(voltage); //Writes the value of the battery after the formula
  return voltage; //returns the voltage
  } 
void loop() {
  // put your main code here, to run repeatedly:
  
  //If the battery cell voltage is less than 3.8v...
readBattery(battery); //Reads the battery. Setting the battery as the input
if (readBattery(battery) <= 3.8){ 
    fanmotorOff(); //turns the fan motor to LOW or off
    //stopMotors(); //stops the robot from moving
  }
  
  //If the battery cell voltage is greater than 3.8v and less than 4.5v...
  else if (readBattery(battery) >= 3.8 && readBattery(battery) <= 4.5){
    fanmotorOn(); //turns the fan motor to HIGH or on
  }
}
