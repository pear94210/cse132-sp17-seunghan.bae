// Name(s): Seunghan Bae

void setup() {
  Serial.begin(9600);
}

void loop() {
  sendDebug("java");
  sendDebug("arduino");
  sendDebug("hello world");
}

void sendDebug(String s) {
  Serial.write(0x21);
  Serial.write(0x30);
  Serial.write((s.length() >> 8) & 0xff);
  Serial.write(s.length() & 0xff);
  for (int i = 0; i < s.length(); i++) {
    Serial.write(s[i]);
  }
}

