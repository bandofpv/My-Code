const int greenLed = 13;
const int redLed = A4;
void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void greenledOn(int delaytime){
  digitalWrite(greenLed, HIGH); //Turns green led on
  delay(delaytime); //Turns green led on for dealytime
}

//Green LED Blink
void greenledBlink(int delaytime){
  digitalWrite(greenLed, HIGH); //Turns green led on
  delay(1000); //Turns greeen led on for delaytime divided by 2
  digitalWrite(greenLed, LOW); //Turns green led off
  delay(1000); //Turns green led off for delaytime divided by 2
}
void waitBlinking(int n, int frequency){
  //blink for n seconds at frequency hz
  for (int i=1; i <= n; i++){
    for(int j=1; j<=frequency; j++){
      digitalWrite(greenLed, HIGH);   
      delay((1000/frequency)/2);   //Half time on            
      digitalWrite(greenLed, LOW);   
      delay((1000/frequency)/2);   //Half time off
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  greenledOn(1000);
}
