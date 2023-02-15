//LDR Teste com Bruzzer.ino
//Autor : Robson Brasil
//Versão : 1
//Última Modificação : 01/01/2019

#define pinLDR A0
#define pinBuzzer 7
#define nivelLuz 970

void setup() {
  pinMode (pinBuzzer, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  int valorLDR = analogRead(A0);
  Serial.print (valorLDR);

  if (valorLDR < nivelLuz) {
    digitalWrite(pinBuzzer, HIGH);
  } else {
    digitalWrite(pinBuzzer, LOW);
  }
}
