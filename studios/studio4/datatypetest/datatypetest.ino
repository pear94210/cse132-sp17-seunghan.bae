// Name(s): Seunghan Bae

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < 360; i++) {
    Serial.write((i >> 8) & 0xff);
    Serial.write(i & 0xff);
  }
}

void loop() {
  
}

