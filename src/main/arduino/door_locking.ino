#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#define Password_Length 5

Servo myservo;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

int arg = 0;
int buzz = 8; 

char Data[Password_Length];
char Master[Password_Length] = "1234";
byte data_count = 0;

bool door = false;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

Keypad customKeypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  myservo.attach(9, 1000, 2000); 
  ServoClose();
  lcd.begin(16, 2);
  pinMode(buzz, OUTPUT);  
  lcd.print("Locking zzz");
  loading("Loading");
  lcd.clear();
  setPassword();  
}

void loop() {
  if (door == true) {
    customKey = customKeypad.getKey();
    if (customKey == '#') {
      lcd.clear();
      ServoClose();
      lcd.print("Locking zzz");
      delay(3000);
      door = false;
    }
  } else {
    Open();
  }
}

void loading(char msg[]) {
  lcd.setCursor(0, 1);
  lcd.print(msg);
  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }
}

void clearData() {
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
}

void ServoClose() {
  for (arg = 0; arg <= 90; arg += 10) { 
    myservo.write(arg);
    delay(50); 
  }
}

void ServoOpen() {
  for (arg = 90; arg >= 0; arg -= 10) {  
    myservo.write(arg);
    delay(50); 
  }
}

void Open() {
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  
  customKey = customKeypad.getKey();
  if (customKey) {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print('*'); 
    data_count++;
  }

  if (data_count == Password_Length - 1) {
    if (!strcmp(Data, Master)) {
      lcd.clear();
      ServoOpen();
      lcd.print("Unlocking ok");
      door = true;
      delay(5000); 
      countdown();
      ServoClose();
      lcd.print("Time is up!");
      delay(1000);
      lcd.clear();
      door = false;
    } else {
      lcd.clear();
      lcd.print("Wrong Password");
      incorrectBuzz();
      delay(1000);
      lcd.clear();
      door = false;
    }
    clearData();
  }
}

void countdown() {
  for (int i = 5; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time remaining");
    lcd.setCursor(6, 1);
    lcd.print(i);
    countdownBuzz();
    delay(1000);
  }
}

void incorrectBuzz() {
  for (int i = 0; i < 3; i++) {  
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
  }
}

void countdownBuzz() {
  digitalWrite(buzz, HIGH);
  delay(200);
  digitalWrite(buzz, LOW);
  delay(200);
}

void setPassword() {
  lcd.clear();
  lcd.print("Set Password");
  data_count = 0;
  while (data_count < Password_Length - 1) {
    customKey = customKeypad.getKey();
    if (customKey) {
      Data[data_count] = customKey;
      lcd.setCursor(data_count, 1);
      lcd.print('*'); 
      data_count++;
    }
  }
  Data[data_count] = '\0'; 
  strcpy(Master, Data); 
  clearData(); 
  lcd.clear();
  lcd.print("Password Set");
  delay(1000);
  lcd.clear();
}
