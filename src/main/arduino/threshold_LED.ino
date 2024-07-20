void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  int analog= analogRead(A0);
  float v = (float)analog * 5 / 1023;

  Serial.print("analogRead : ");
  Serial.println(analog);
  delay(1000);
  Serial.print("Voltage : ");
  Serial.println(v);
  delay(1000);

  if(v < 1.253){
    digitalWrite(5, HIGH);
    delay(1000);
  }else{
    digitalWrite(5, LOW);
    delay(1000);
  }
}
