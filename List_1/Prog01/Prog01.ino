int led = 7;
bool state;

void setup(){
 pinMode(led, OUTPUT); 
 state = 1;
}

void loop(){
  digitalWrite(led, state);
  delay(1700);
  state = !state;
  
}
