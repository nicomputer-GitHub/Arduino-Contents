int b[4];

void setup(){
  for(int i = 2; i < 6; i++){
    pinMode(i, OUTPUT);
  }
}

void NumPrint(int Number){
  b[0] = (Number / 1 ) % 2;
  b[1] = (Number / 2 ) % 2;
  b[2] = (Number / 4 ) % 2;
  b[3] = (Number / 8 ) % 2;
  
  for(int w = 0; w < 4; w++){
    digitalWrite(w + 2,b[w]);
  }
}

void loop(){
  for(int i = 0; i < 10; i++){
    NumPrint(i);
    delay(1000);
  } 
}
