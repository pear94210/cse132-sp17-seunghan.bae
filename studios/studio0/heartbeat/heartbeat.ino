int ledPin = 13;
int n = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);

  n++;
  Serial.print(n);
  Serial.println(" sec have elapsed");
  
  int i = millis();
  Serial.println(i);
  i = 0;
}
