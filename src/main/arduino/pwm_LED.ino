const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup(){
  
}

void loop(){
  unsigned long duration = 30;
  int Array[4] = {redPin, greenPin, bluePin, redPin};
  for(int i = 0; i < 3; i++){
    for (int j = 255; j >= 0; j--){
      analogWrite(Array[i], j);
      delay(duration);
      analogWrite(Array[i + 1], 255 - j);     
    }
  }
}
