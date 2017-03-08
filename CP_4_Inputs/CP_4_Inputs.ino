void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1); 

  int lightLevel = analogRead(A1);
  Serial.println(lightLevel);
  delay(1);
  
  if ((sensorValue >= 300) && (lightLevel > 1000)){ 
    digitalWrite(13, HIGH);
  }
  else
    digitalWrite(13, LOW);
}
