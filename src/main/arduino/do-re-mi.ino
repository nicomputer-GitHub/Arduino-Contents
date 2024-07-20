void setup(){
pinMode(13, OUTPUT);
}

void loop(){
  for(int i = 0; i < 1056; i++){
    digitalWrite(13, HIGH);
    delayMicroseconds(473);
    digitalWrite(13, LOW);
    delayMicroseconds(473);
  }

  for(int i = 0; i < 1176; i++){
    digitalWrite(13, HIGH);
    delayMicroseconds(425);
    digitalWrite(13, LOW);
    delayMicroseconds(425);
  }

  for(int j = 0; j < 1320; j++){
    digitalWrite(13, HIGH);
    delayMicroseconds(378);
    digitalWrite(13,LOW);
    delayMicroseconds(378);
  }  
  delay(1000);
}
