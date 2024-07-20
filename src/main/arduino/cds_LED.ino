void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

int cnt = 0;

void loop() {
  int analog = analogRead(A0);
  float v = (float)analog * 5 / 1023;

  Serial.print("analogRead : ");
  Serial.println(analog);
  Serial.print("Voltage : ");
  Serial.println(v);
  Serial.println("-----------");
  cnt += 5;
  delay(1000);
}
