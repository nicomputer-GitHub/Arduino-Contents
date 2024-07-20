void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop(){
  int sensorValue = analogRead(A0);
  float V = (float)sensorValue * 5 / 1023;
  float Temp = (V - 0.5) / 0.01;
  
  Serial.print("sensorValue : ");
  Serial.println(sensorValue);
  Serial.print("sensorVoltage : ")
  Serial.println(V);
  Serial.print("sensorTemperature : ");
  Serial.println(Temp);
  
  if(Temp >= 65){
    for(int i = 0; i < 440; i++){
      digitalWrite(2, HIGH);
      delayMicroseconds(1131);
      digitalWrite(2, LOW);
      delayMicroseconds(1131);
    }
  }
}
