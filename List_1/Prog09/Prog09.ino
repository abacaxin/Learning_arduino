// C++ code
//
#define echo 2
#define trig 3

bool State;

bool changed;

long duration, dist;
int Limiter1;
int Limiter2;

void setup(){
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(5, OUTPUT);
  readultra();
  
}

void loop()
{

  
  while(dist > 50){   
    tone(5, 1100, 60);
    delay(5000);
    readultra();
  }
  while(dist <= 50 && dist >= 10){   
    tone(5, 1100, 60);
    delay(dist * 50 - 70);
    readultra();
  }
  while(dist < 10){   
    tone(5, 1100, 60);
    delay(1);
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

