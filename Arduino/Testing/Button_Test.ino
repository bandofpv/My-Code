/*
This code will be used to test my buttons
 */

int leftbutton = 8; //sets leftbutton to pin 8
int rightbutton = 12; //sets rightbutton to pin 12

void setup() {
  pinMode(leftbutton, INPUT_PULLUP); //sets leftbutton to an INPUT_PULLUP
  pinMode(rightbutton, INPUT_PULLUP); //sets rightbuttonto an INPUT_PULLUP

  Serial.begin(9600); //starts serial monitor
}

void loop() {
  int leftbumper = digitalRead(leftbutton); //creates leftbumper to the value of the leftbutton
  int rightbumper = digitalRead(rightbutton); //creates rightbumper to the value of the rightbutton

  //If the left or right bumper is hit...
  if (leftbumper == LOW || rightbumper == LOW){
    Serial.println("Bumper HIGH"); //Print Bumper HIGH
  }

  //If the left or right bumpe ris hit...
  else if (leftbumper == HIGH || rightbumper == HIGH){
    Serial.println("Bumper LOW"); //Print Bumper LOW
  }

  delay(1000);
}

