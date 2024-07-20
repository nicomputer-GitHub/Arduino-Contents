int pushButton = 2;
int output = 13;
float T = 110;
float D = 0.5;
float high_time = T * D;
float low_time = T - high_time;

void setup(){
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(output, OUTPUT);
}

void loop(){
  int buttonState = digitalRead(pushButton);

  if(buttonState == HIGH){
    digitalWrite(output, HIGH);
    delay(high_time);
    digitalWrite(output, LOW);
    delay(low_time);
  } else {
    digitalWrite(output, LOW);
    delay(low_time);
  }
}
