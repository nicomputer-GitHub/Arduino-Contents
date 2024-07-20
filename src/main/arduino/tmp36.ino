void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0);
  float V = (float)sensorValue * 5 / 1023;
  float Temp = (V - 0.5) / 0.01;
  
  Serial.print("sensorValue : ");
  Serial.println(sensorValue);
  delay(500);
  Serial.print("sensorVoltage : ");
  Serial.println(V);
  delay(500);
  Serial.print("sensorTemperature : ");
  Serial.println(Temp);
  delay(500);
}
