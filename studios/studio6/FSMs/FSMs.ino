// Name(s): Seunghan Bae

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
   String s = Serial.readString();
   Serial.print(s);
   Serial.print(": ");
   if (s[0] == 's' && s[1] == 't') Serial.print(1);
   for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ' && s[i + 1] == 's' && s[i + 2] == 't') Serial.print(1);
   }
   Serial.println();
  }
}

