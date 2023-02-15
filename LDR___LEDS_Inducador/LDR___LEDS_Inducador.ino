//LDR e LEDs
//Autor : Robson Brasil
//Versão : 2
//Última Modificação : 01/01/2020
 
int sensor = 0;      //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //Usada para ler o valor do sensor em tempo real.
 
const int ledVerde = 8;
const int ledAmarelo = 11;
const int ledVermelho = 13;
 
//Função setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(9600);
   
  //Definindo pinos digitais dos leds como de saída.
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAmarelo,OUTPUT);
  pinMode(ledVermelho,OUTPUT);
}
 
//Função loop, executado enquanto o Arduino estiver ligado.
void loop(){
   
  //Lendo o valor do sensor.
  int valorSensor = analogRead(sensor);
   
 
  //Valores da luminosidade podem ser alterados conforme necessidade. 
 
  //Luminosidade baixa.
  if (valorSensor < 800) {
    apagaLeds();
    digitalWrite(ledVermelho,HIGH);
  }
   
  //Luminosidade média.
  if (valorSensor >= 550 && valorSensor <= 800) {
    apagaLeds();
    digitalWrite(ledAmarelo,HIGH);
  }
   
  //Luminosidade alta.
  if (valorSensor > 640) {
    apagaLeds();
    digitalWrite(ledVerde,HIGH);
  }
   
  //Exibindo o valor do sensor no serial monitor.
  Serial.println(valorSensor);
   
  delay(50); 
}
 
//Função criada para apagar todos os leds de uma vez.
void apagaLeds() {
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledAmarelo,LOW);
  digitalWrite(ledVermelho,LOW);
}  
