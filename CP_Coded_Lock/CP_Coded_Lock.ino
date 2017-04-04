
#include <Servo.h>
Servo boxLatch;

int pos = 0;

bool whiteButton = false;
bool yellowButton = false;
bool greenButton = false;
bool redButton = false;
  
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  boxLatch.attach(13);
  // read the input on analog pin 0: 
}

void loop() {
  //Serial.println(sensorValue);
  buttonCheck();
  codeCheck();
  delay(1);
}

void buttonCheck(){ 
  int sensorValue = analogRead(A0);

  bool newWhiteButton = whiteButton;
  bool newYellowButton = yellowButton;
  bool newGreenButton = greenButton;
  bool newRedButton = redButton;

  if (sensorValue >= 800 && sensorValue < 1000){
    Serial.println("White Button");
    whiteButton = true;
  } else if (sensorValue >= 600 && sensorValue < 800){
    Serial.println("Yellow Button");
    yellowButton = true;
  } else if (sensorValue >= 400 && sensorValue < 600){
    Serial.println("Green Button");
    greenButton = true;
  } else if (sensorValue >= 200 && sensorValue < 400){
    Serial.println("Red Button");
    redButton = true;
  } else {
    Serial.println(sensorValue);
  } 
}

void codeCheck(){
  bool otherWhiteButton = whiteButton;
  bool otherYellowButton = yellowButton;
  bool otherGreenButton = greenButton;
  bool otherRedButton = redButton;

  if (otherGreenButton == true && otherYellowButton == true ){ //&& otherRedButton == false && otherWhiteButton == false ){
    for (pos = 0; pos <= 90; pos += 1) { 
    boxLatch.write(pos);              
    delay(1000); 
    boxLatch.detach();
    }
  }
}


