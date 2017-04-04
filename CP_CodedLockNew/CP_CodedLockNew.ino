
//Button pins
int redButton = A0;
int greenButton = A1;
int yellowButton = A2;

//Button States
volatile int redPress = 0;
volatile int greenPress = 0;
volatile int yellowPress = 0;

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

  attachInterrupt(digitalPinToInterrupt(A2), buttonCheck, CHANGE);

  
  boxLatch.attach(13);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonCheck();

  if (redPress >= 5 && greenPress >= 3 && yellowPress >= 8){
    Serial.println("UNLOCKED");
    
    for (pos = 0; pos <= 90; pos += 1) { 
    boxLatch.write(pos);              
    delay(1000); 
    boxLatch.detach();
    }
  }

  delay(1);
}

void buttonCheck(){ 
  int redButtonState = digitalRead(redButton); 
  int greenButtonState = digitalRead(greenButton); 
  int yellowButtonState = digitalRead(yellowButton); 

  digitalWrite(A2, yellowButtonState);


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
  
