#include"MorseCodes.h"

const int led = 13;
const unsigned long morsePeriod = 500;
unsigned long morseTime = 0;

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
    Serial.print(input);
    Serial.print(": ");
    String morse = morseEncode(input);
    Serial.println(morse);
    ledMorse(morse);
  }
}

void ledMorse(String morse) {
  if (morse == " ") {
    delay(2000);
  } else {
    for (int i = 0; i < morse.length(); i++) {
      if (morse[i] == '.') {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
      } else {
        digitalWrite(led, HIGH);
        delay(1500);
        digitalWrite(led, LOW);
        delay(500);
      }
    }
    delay(1000);
  }
}

void loop() {
  // No Need to Modify this.  Put most of your code in "convertIncomingCharsToMorseCode()"
  convertIncomingCharsToMorseCode();
}
