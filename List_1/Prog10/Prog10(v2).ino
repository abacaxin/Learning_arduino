#define button 2
int numberofleds = 5;
int pinos[5] = {11, 10, 9, 8, 7};
int i = 0;
int limiters[5] = {limiters[4]/16, limiters[4]/8, limiters[4]/4, limiters[4]/2, 16};
int countlim[5] = {1, 1, 1, 1, 1};
bool states[5] = {0, 0, 0, 0, 0};

void setup(){
  Serial.begin(9600);
  pinMode(button, INPUT); 
  for(int p = 0; p < numberofleds; p++){
    pinMode(pinos[p], OUTPUT);
  }
}

void loop(){
  if(digitalRead(button)){
    while(digitalRead(button));
    for(i = 0; i < numberofleds; i++){
      countlim[i]++;
      if(countlim[i] > limiters[i]){
        countlim[i] = 1;
        states[i] = !states[i];
      }
    }
  }
  for(int l = 0; l < numberofleds; l++){
    digitalWrite(pinos[l], states[l]);
    delay(1);
  }
}