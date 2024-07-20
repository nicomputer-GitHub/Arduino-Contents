void setup(){
pinMode(13, OUTPUT);
}

void loop(){
  for(int i = 0; i < 440; i++){
    digitalWrite(13, HIGH);
    delayMicroseconds(1136);
    digitalWrite(13, LOW);
    delayMicroseconds(1136);
  }
  delay(1000);
}
