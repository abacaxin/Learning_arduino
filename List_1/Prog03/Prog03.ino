#define red 4
#define yel  3
#define gre  2
int actual; 
int last;
int next;
int time; 

void setup(){
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  actual = gre;
}

void loop(){
  call();
  digitalWrite(actual, HIGH);
  digitalWrite(last, LOW);
  delay(time * 1000); 
  change();
}

void call(){
  if(actual == red){
    next = gre;
    time = 15; 
  }
  
  if(actual == gre){
    next = yel;
    time = 20; 
  }
  
  if(actual == yel){
    next = red;
    time = 10; 
  }
}

void change() {
  last = actual; 
  actual = next;
}