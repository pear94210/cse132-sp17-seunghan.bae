//Name(s): Seunghan Bae

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(0x41);
  Serial.write(0x53);
  Serial.write(0x43);
  Serial.write(0x49);
  Serial.write(0x49);
  Serial.write(0x20);
  Serial.write(0x74);
  Serial.write(0x61);
  Serial.write(0x62);
  Serial.write(0x6c);
  Serial.write(0x65);
//  Serial.write(0x53);
//  Serial.write(0x6b);
//  Serial.write(0x79);
//  Serial.write(0x6c);
//  Serial.write(0x61);
//  Serial.write(0x72);
//  Serial.write(0x3c);
//  Serial.write(0x33);
  Serial.write(0x0a);
}

