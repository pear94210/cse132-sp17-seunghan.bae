#include"MorseCodes.h"

const int led = 13;

// Argument: Any character
// Return Value: Either:
//                  1) If the character is a letter, the upper case equivalent.  
//                  2) If the character is not a letter, the original value.
char toUpper(char c) {
  // TODO
  if (c >= 0x61 && c <= 0x7a) return (c - 0x20);
  else return c;
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}


void convertIncomingCharsToMorseCode() {
  // TODO
  if (Serial.available()) {
    char input = Serial.read();
    char* morse = morseEncode(input);
    Serial.print(morse);
  }
}




void loop() {
  // No Need to Modify this.  Put most of your code in "convertIncomingCharsToMorseCode()"
  convertIncomingCharsToMorseCode();
}
