#define STACK_SIZE 16

float stck[STACK_SIZE]; 
int sp = 0;

class Stack {
public:
  void init();
  void push(float ch); 
  float pop(); 
};

void Stack::init() {
  sp = 0;
}

void Stack::push(float ch) {
  if (sp == STACK_SIZE) {
    Serial.println("Stack is full.");
    return;
  }
  stck[sp] = ch;
  sp++;
}

float Stack::pop() {
  if (sp == 0) {
    Serial.println("Stack is empty.");
    return 0;
  }
  sp--;
  return stck[sp];
}

Stack stack;

char keymap[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

char c = '!';
char cc = '!';
int cnt = 0;

void setup() {
  for (unsigned short i = 3; i < 7; i++) pinMode(i, OUTPUT);
  for (unsigned short j = 7; j < 11; j++) pinMode(j, INPUT);
  Serial.begin(9600);
  stack.init();
}

void loop() {
  for (int i = 3; i < 7; i++) {
    digitalWrite(i, HIGH);
    for (int j = 7; j < 11; j++) {
      cnt++;
      if (digitalRead(j)) {
        c = keymap[10 - j][6 - i];
        cnt = 0;
        if (cc != c) {
          cc = c;
          if (c >= '1' && c <= '9') {
            float num = c - '0'; 
            Serial.print("Push : ");
            Serial.println(num);
            stack.push(num);
          }
          // num2から抽出
          else if (c == 'A') { 
            float num2 = stack.pop();
            float num1 = stack.pop();
            float result = num1 + num2;
            Serial.print("Add Result : ");
            Serial.println(result);
            stack.push(result);
          }
          else if (c == 'B') { 
            float num2 = stack.pop();
            float num1 = stack.pop();
            float result = num1 - num2;
            Serial.print("Sub Result : ");
            Serial.println(result);
            stack.push(result);
          }
          else if (c == 'C') { 
            float num2 = stack.pop();
            float num1 = stack.pop();
            float result = num1 * num2;
            Serial.print("Mul Result : ");
            Serial.println(result);
            stack.push(result);
          }
          else if (c == 'D') { 
            float num2 = stack.pop();
            float num1 = stack.pop();
            if (num2 != 0) {
              float result = num1 / num2;
              Serial.print("Div Result : ");
              Serial.println(result);
              stack.push(result);
            } else {
              Serial.println("Error : Division by zero");
              stack.push(num1);
              stack.push(num2);
            }
          }
        }
      }
      if (cnt == 16) {
        cc = '!';
        cnt = 0;
      }
    }
    digitalWrite(i, LOW);
  }
}
