//Definições -----------------------------------------------------------------------------------------
#define btn1 2 
#define btn2 6
int led1 = 3;
int led2 = 4;
int led3 = 5;// Define pino do botão 1
int endnumber;
int timeset;
int tempo;
int diferenca;

int bot = 0;
#define button 2

bool go = 0;                                             // Define pino do botão 3
	 
//Variáveis Globais ----------------------------------------------------------------------------------
byte cont = 0;                                               // Variável de Controle
	 
//Setup ----------------------------------------------------------------------------------------------
void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT); 
    Serial.begin(9600);                                      // Inicializa a serial com 9600
    pinMode(btn1, INPUT_PULLUP);   
    pinMode(btn2, INPUT_PULLUP);
  	pinMode(bot, INPUT_PULLUP);// Configura o pino como INPUT PULL-UP
                              // Configura o pino como INPUT PULL-UP
}
	 
//Loop -----------------------------------------------------------------------------------------------
void loop() {
    if(digitalRead(btn1) == 0){
      while(!digitalRead(btn1)){delay(10);}
      chama();
    }
  
     
     if(!digitalRead(btn2)){                              // Verifica se o botão 3 foi pressionado
        while(!digitalRead(btn2)){cont = 0;}                  // Loop até que o botão 3 seja solto 
        endnumber = 0;
        acender();// Imprime que o contador foi reiniciado
    }
  
}

void sla(){
  tempo = millis();
  diferenca  = millis() - tempo;
}

void acender(){
  
  Serial.println("acendendo o led!");
  if(endnumber == 0){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  if(endnumber == 4){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  if(endnumber == 1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  if(endnumber == 2){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }

  if(endnumber == 3){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  
  if(endnumber == 5){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  
  if(endnumber == 6){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  
  if(endnumber == 7){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  
  if(endnumber == 8){
   pisca(); 	
  }
  
  if(endnumber > 8){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    cont = 0;
   	endnumber = 0; 
  }
  
}

void restart(){
  tempo = 0;
  diferenca = 0;
}

void chama(){
  	cont++;                      
 	tempo = millis();
 	Serial.print(F("Contador: "));                       // Imprime a quantidade de cont na Serial
 	Serial.println(cont);
 	while((millis() - tempo) < 70){
      Serial.println("...");
    	if(digitalRead(btn1) == 0){
    	   chama();
  		 }
    } 
   endnumber = cont;
   acender();
  
}

void pisca(){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(200);
 	digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(200);
  	digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(200);
  
    
   
}