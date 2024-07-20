int Echo = 6;
int Trig = 7;

void setup() {
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
}

void loop() {
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  unsigned long time = pulseIn(Echo, HIGH);
  float dist = (331.4 + 0.606 * 21.0 + 0.00124 * 61.1) * time * 0.000001 * 100 * 0.5;

  Serial.print("Time : ");
  Serial.println(time);
  delay(1000);
  Serial.print("Distance : ");
  Serial.print(dist);
  Serial.println("cm");
  delay(1000);
  Serial.println("--------");
}
