char keymap[4][4] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'*', '0', '#', '/'}
};

char c = '!';
char cc = '!';
int cnt = 0;
int num1 = 10;
int num2 = 10;

void setup(){
  for(unsigned short i = 3; i < 7; i++) pinMode(i, OUTPUT);
  for(unsigned short j = 7; j < 11; j++) pinMode(j, INPUT);
  Serial.begin(9600);
}

void loop(){
  for(int i = 3; i < 7; i++){
    digitalWrite(i, HIGH);
    for(int j = 7; j < 11; j++){
      cnt++;
      if(digitalRead(j)){
        c = keymap[10 - j][6 - i];
        cnt = 0;
        if(cc != c){
          cc = c;
          if(c >= '0' && c <= '9'){
            int num = c - '0';
    		if(num1 == 10 && num2 == 10){
      		  Serial.print("Num1 : ");
      		  Serial.println(num);
      		  num1 = num;
    		}
            else if(num1 != 10 && num2 == 10){
              Serial.print("Num2 : ");
              Serial.println(num);
              num2 = num;
            }
  		  }
  		  else if(c == '+'){
    		Serial.print("Add : ");
            Serial.println(num1 + num2);
            num1 = 10;
            num2 = 10;
          }
          else if(c == '-'){
            Serial.print("Sub : ");
            Serial.println(num1 - num2);
            num1 = 10;
            num2 = 10;
          }
          else if(c == '*'){
            Serial.print("Mul : ");
            Serial.println(num1 * num2);
            num1 = 10;
            num2 = 10;
          }
          else if(c == '/'){
            Serial.print("Div : ");
            Serial.println((float)num1 / (float)num2);
            num1 = 10;
            num2 = 10;
          }
        }
      }
      if(cnt == 16){
        cc = '!';
        cnt = 0;
      }
    }
    digitalWrite(i, LOW);
  }
}
