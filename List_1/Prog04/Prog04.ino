int red = 4;
int yel = 3;
int gre = 2;
int grep = 5;
int redp = 6; 
int actual; 
int last;
int next;
int time; 
bool may;

void setup(){
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(grep, OUTPUT);
  pinMode(redp, OUTPUT);
  actual = gre;
}

void loop(){
  call();
  digitalWrite(actual, HIGH);
  digitalWrite(grep, may);
  digitalWrite(redp, !may);
  digitalWrite(last, LOW);
  delay(time * 1000); 
  change();
}

void call(){
  if(actual == red){
    next = gre;
    time = 15; 
    may = 1;
  }
  
  if(actual == gre){
    next = yel;
    time = 20;
    may = 0;
  }
  
  if(actual == yel){
    next = red;
    time = 10;
    may = 0;
  }
}

void change() {
  last = actual; 
  actual = next;
}