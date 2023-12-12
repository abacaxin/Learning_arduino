int ledA = 13;
int ledB = 12;
int ledC = 11;
int ledD = 10;
int actualed;
int last;
int next; 

void setup(){
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  actualed = ledA;
}



void loop(){
  digitalWrite(actualed, HIGH);
  digitalWrite(last, LOW);
  delay(300);
  call();
  change();
  
}




void change(){
   last = actualed; 
   actualed = next;
}

void call(){
  if(actualed == ledA){
    next = ledB;
  }
  
  if(actualed == ledB){
    next = ledC;
  }
  
  if(actualed == ledC){
    next = ledD;
  }
  
  if(actualed == ledD){
    next = ledA;
  }
}