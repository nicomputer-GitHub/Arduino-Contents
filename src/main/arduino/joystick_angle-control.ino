#include <Servo.h>
#include <String.h>
#define PIN_SERVO3 3
#define PIN_SERVO5 5
#define SEPARATOR
Servo myservo3;
Servo myservo5;

void setup() {
  myservo3.attach(PIN_SERVO3, 500, 2500);
  myservo3.write(90);
  delay(100);
  myservo5.attach(PIN_SERVO5, 500, 2500);
  myservo5.write(0);
  delay(100);

  Serial.begin(9600);
  delay(100);
}

void loop () {
  int UD = analogRead(A0);
  int LR = analogRead(A1);

  int udServo = map(UD, 0, 1023, 0, 180);
  myservo3.write(udServo);
  int lrServo = map(LR, 0, 1023, 0, 180);
  myservo5.write(lrServo);
  delay(100);

  float udVol = (float)UD * 5.0 / 1023;
  float lrVol = (float)LR * 5.0 / 1023;

  int udServoOut = myservo3.read();
  int lrServoOut = myservo5.read();

  Serial.print("UD:");
  Serial.print(udVol, DEC);
  Serial.print(", LR:");
  Serial.print(lrVol, DEC);
  Serial.print(", Tilt:");
  Serial.print(udServoOut * 0.1);
  Serial.print(", Pan:");
  Serial.print(lrServoOut * 0.1);
  Serial.println("");

  delay(500);
}
