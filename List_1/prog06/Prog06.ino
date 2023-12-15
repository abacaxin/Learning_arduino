#define button  8 
#define cared  11 
#define caryel  12 
#define cargre  13 
#define pedred 7
#define pedgre 6

float tempo; 
float set; 
bool logic; 

void setup(){
  Serial.begin(9600); 
  pinMode(button, INPUT); 
  pinMode(cared, OUTPUT);
  pinMode(caryel, OUTPUT);
  pinMode(cargre, OUTPUT);
  pinMode(pedgre, OUTPUT);
  pinMode(pedred, OUTPUT);
  set = millis();
  
}

void loop(){
  
  while(logic == 0 ){
   digitalWrite(cargre, HIGH);
   digitalWrite(caryel, LOW);
   digitalWrite(cared, LOW);
   digitalWrite(pedgre, LOW);
   digitalWrite(pedred, HIGH);
   tempo = (millis() - set + 200) / 1000 ; 
   Serial.println(tempo);
    if(digitalRead(button) == HIGH && tempo + 0.2 > 3){
      delay(3000); 
      logic = 1; 
    }
  }
  
  if(logic == 1){
   digitalWrite(cargre, LOW);
   digitalWrite(caryel, HIGH); 
   digitalWrite(cared, LOW);
   delay(2000); 
   digitalWrite(cared, HIGH);
   digitalWrite(caryel, LOW);
   digitalWrite(cargre, LOW);
   digitalWrite(pedgre, HIGH);
   digitalWrite(pedred, LOW);
   delay(5000); 
   set = millis(); 
   logic = 0;
  
 }
}
     
