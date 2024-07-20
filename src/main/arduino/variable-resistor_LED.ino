int output = 13;
float T = 100;

void setup(){
  Serial.begin(9600);
  pinMode(output, OUTPUT);
}

void loop(){
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  
  float D = (float)sensorValue / 1023;
  float high_time = T * D;
  float low_time = T - high_time;
  
  digitalWrite(output, HIGH);
  delay(high_time);
  digitalWrite(output, LOW);
  delay(low_time);
}
