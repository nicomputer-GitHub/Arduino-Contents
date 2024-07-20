#include <Servo.h>
#define PIN_SERVO3 3

int isUpdated = 1;
int argV = 0;
Servo myservo3;

void setup() {
  Serial.begin(9600);
  isUpdated = 1;
  myservo3.attach(PIN_SERVO3, 500, 2500);
  myservo3.write(0);
  delay(100);
}

void loop() {
  if(isUpdated == 1) {
    Serial.println("");
    Serial.println("--------------------------");
    Serial.println("Pls input value (0 to 180):");
    isUpdated = 0;
  }
  while (Serial.available() > 0) {
    String strTmp = Serial.readStringUntil(0xA);
    argV = strTmp.toInt();
    isUpdated = 1;
    Serial.println(argV);
    break;
  }
  myservo3.write(argV);
  return;
}
