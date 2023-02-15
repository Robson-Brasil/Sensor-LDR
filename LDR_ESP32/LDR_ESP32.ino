#define Light  2

void setup() {
  
  Serial.begin(115200);
  delay(1000);
}

void loop() {
int val = analogRead(Light);
Serial.println(val);
delay(100);
}
