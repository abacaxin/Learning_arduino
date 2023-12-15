#define tmp A3
#define ledb 8
#define ledy 9 
#define ledr 10


#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

float leitura;
float tensao;
int temp;

void setup()
{
  pinMode(tmp, INPUT);
  pinMode(ledb, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledr, OUTPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);

  lcd_1.print("Starting...");
  readtmp();
  lcd_1.setCursor(0, 1);
  lcd_1.clear();
  delay(1000);
  
}

void loop(){
  while(temp >= 30){
    lcd_1.clear();
    digitalWrite(ledr, HIGH);
    digitalWrite(ledy, LOW);
    digitalWrite(ledb, LOW);
    lcd_1.print("Hot!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Temperatura: ");
    lcd_1.print(temp);
    readtmp();
    delay(200);
  }
  while(temp < 30 && temp > 10){
    lcd_1.clear();
    digitalWrite(ledr, LOW);
    digitalWrite(ledy, HIGH);
    digitalWrite(ledb, LOW);
    lcd_1.print("Normal");    
    lcd_1.setCursor(0, 1);
    lcd_1.print("Temperatura: ");
    lcd_1.print(temp);
    readtmp();
    delay(200);
  }
  while(temp <= 10){
    lcd_1.clear();
    digitalWrite(ledr, LOW);
    digitalWrite(ledy, LOW);
    digitalWrite(ledb, HIGH);
    lcd_1.print("Cold");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Temperatura: ");
    lcd_1.print(temp);
    readtmp();
    delay(200);
  }
    
    

  
}
void readtmp(){
  leitura = analogRead(tmp);
  tensao = 5 * leitura / 1023;
  temp = (tensao - 0.5) * 100;
  
}