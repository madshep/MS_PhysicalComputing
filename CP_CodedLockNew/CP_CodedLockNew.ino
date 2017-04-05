
//Button pins
int redButton = 2;
int greenButton = 3;
int yellowButton = 4;

//Button States
volatile int redPress = 0;
volatile int greenPress = 0;
volatile int yellowPress = 0;

int redButtonState = 0;
int greenButtonState = 0;
int yellowButtonState = 0;

//Servo
#include <Servo.h>
Servo boxLatch;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redButton, INPUT);
  pinMode(greenButton, INPUT);
  pinMode(yellowButton, INPUT);

  attachInterrupt(digitalPinToInterrupt(2), redButtonCheck, RISING);
  attachInterrupt(digitalPinToInterrupt(3), greenButtonCheck, RISING);
  
  boxLatch.attach(13);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonCheck();

  if (redPress >= 5 && greenPress >= 3){
    Serial.println("UNLOCKED");
    for (pos = 0; pos <= 90; pos += 1) { 
    boxLatch.write(pos);              
    delay(1000); 
    boxLatch.detach();
    }
  }

  delay(1);
}

void redButtonCheck(){
  Serial.println("Red Button");
  redPress++;
  delay(1000);
  }

void greenButtonCheck(){
  Serial.println("Green Button");
  greenPress++;
  delay(1000);
}

void buttonCheck(){ 
  redButtonState= digitalRead(redButton); 
  greenButtonState = digitalRead(greenButton); 
  yellowButtonState  = digitalRead(yellowButton); 

  //digitalWrite(2, redButtonState);


//  while (redButtonState == HIGH){
//    Serial.println("Red Button");
//    redPress++;
//    delay(1000);
//    
//    }
//
//   while (greenButtonState == HIGH){
//     Serial.println("Green Button");
//     greenPress++;
//     delay(1000);
//   }
//
//   while (yellowButtonState == HIGH){
//     Serial.println("Yellow Button");
//     yellowPress++;
//     delay(1000);
//   } 
}

void passwordCheck(){
  
}
  
