// Name(s): Seunghan Bae

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < 360; i++) {
    Serial.write(i >> 8);
    Serial.write(i);
  }
}

void loop() {
  
}

