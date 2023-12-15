#define button 2
#define bit1 11
#define bit2 10
#define bit3 9
#define bit4 8

int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;


void setup(){
  pinMode(button, INPUT); 
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  pinMode(bit4, OUTPUT);
  
}

void loop(){
  if(digitalRead(button) == 1){
    while(digitalRead(button));
    count1++;
    count2++;
    count3++;
    count4++;
    change();
  } 
}

void change(){
  if(count1 == 1){
    digitalWrite(bit1, !digitalRead(bit1));
    count1 = 0;
  }
  if(count2 == 2){
    digitalWrite(bit2, !digitalRead(bit2));
    count2 = 0;
  }
  if(count3 == 4){
	digitalWrite(bit3, !digitalRead(bit3));
	count3 = 0;
  }
  if(count4 == 8){
	digitalWrite(bit4, !digitalRead(bit4));
	count4 = 0;
  }
}