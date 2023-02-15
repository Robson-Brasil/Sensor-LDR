//LDR e LEDs
//Autor : Robson Brasil
//Versão : 2
//Última Modificação : 01/01/2020

const int pinoLDR = A0; // pino onde o LRD está conectado
const int pinoLED = 7; // pino onde o LED está conectado
int leitura = 0; // variável para armazenar o valor lido pelo ADC
float tensao = 0.0; // variável para armazenar a tensão

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600bps
  // configura os pinos do LDR e LED
  pinMode(pinoLDR, INPUT); 
  pinMode(pinoLED, OUTPUT);
  }

void loop() {
  // le o valor de ADC no pino do LDR
  leitura = analogRead(pinoLDR);

  // imprime valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); // tabulacao

  // converte e imprime o valor em tensão elétrica
  tensao = leitura * 5.0 / 1023.0;
  Serial.print("Tensão: ");
  Serial.print(tensao);
  Serial.print("V");

  Serial.println(); // nova linha

  delay(1000); // aguarda 1 segundo para uma nova leitura

  // verifica luminosidade do ambiente
  if(leitura < 880){ // se a luminosidade for menor que 40
    digitalWrite(pinoLED,HIGH); // acende o LED
  }
  else { // se não
    digitalWrite(pinoLED,LOW); // apaga o LED
  }
  delay(50); // aguarda 100 milissegundos para uma nova leitura
}
