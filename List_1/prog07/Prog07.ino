/*
By: Daniel Viegas
This program was made to simulate a car ditance back sensor, each color represents a distance range
Green: Over 25
Yellow: Between 25 and 10
Red: Below 10

The range can be changed by modifying the limiters 1 and 2
*/
#define echo 2
#define trig 3
#define ledg 4
#define ledy 5
#define ledr 6

bool State;

bool changed;

long duration, dist;
int Limiter1;
int Limiter2;

void setup(){
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledr, OUTPUT);
  readultra();
  Limiter1 = 25;
  Limiter2 = 10;
}

void loop()
{

  
  while(dist > Limiter1){   
    digitalWrite(ledg, HIGH);
    digitalWrite(ledy, LOW);
    digitalWrite(ledr, LOW);
    readultra();
  }
  while(dist <= Limiter1 && dist > Limiter2){   
    digitalWrite(ledg, LOW);
    digitalWrite(ledy, HIGH);
    digitalWrite(ledr, LOW);
    readultra();
  }
  while(dist <= Limiter2){   
    digitalWrite(ledg, LOW);
    digitalWrite(ledy, LOW);
    digitalWrite(ledr, HIGH);
    readultra();
  }
  

    
  
}

void readultra(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  
  
  dist = (duration / 2) / 29.1;  
  
}

