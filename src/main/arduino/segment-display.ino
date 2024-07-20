boolean Num_Array[10][7] = {
  {1,1,1,1,1,1,0}, 
  {0,1,1,0,0,0,0}, 
  {1,1,0,1,1,0,1}, 
  {1,1,1,1,0,0,1}, 
  {0,1,1,0,0,1,1}, 
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1}, 
  {1,1,1,0,0,1,0}, 
  {1,1,1,1,1,1,1}, 
  {1,1,1,1,0,1,1}, 
};

void setup(){
  for(int i = 2; i < 9; i++){
    pinMode(i, OUTPUT);
  }
}

void NumPrint(int Number){
  for(int w = 0; w < 7; w++){
    digitalWrite(w + 2, Num_Array[Number][w]);
  }
}

void loop(){
  for(int i = 0; i < 10; i++){
    NumPrint(i);
    delay(1000);
  }
}
