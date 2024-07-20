char keymap[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

char c = '!';
char cc = '!';
int cnt = 0;

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
          Serial.println(c);
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
