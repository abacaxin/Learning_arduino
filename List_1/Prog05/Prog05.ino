#define button 2
#define led 8

bool state = 0;
void setup(){
  pinMode(button, INPUT); 
  pinMode(led, OUTPUT);
  
}

void loop(){
  if(digitalRead(button) == 1){
    state = !state; 
    delay(200); 
  } 
  digitalWrite(led, state); 
}