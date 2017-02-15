// Name(s): Seunghan Bae

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(0x21);
  Serial.write(0x30);
}

void sendDebug() {
  Serial.write(0x21);
  Serial.write(0x30);
}

