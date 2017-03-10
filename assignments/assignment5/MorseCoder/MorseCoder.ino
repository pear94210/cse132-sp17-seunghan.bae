#include"MorseCodes.h"

const int led = 13;
const unsigned long morsePeriod = 500;
unsigned long morseTime;

char input;
String morse;
int count;

enum State {
  start,
  newChar,
  dotOn,
  dashOn,
  off,
  charSpace,
  wordSpace,
};

State ledState = start;

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
  ledState = ledMorse(ledState);
}

State ledMorse(State state) {
  switch (state) {
    case start:
      if (Serial.available()) {
        input = Serial.read();
        Serial.print(input);
        Serial.print(": ");
        morse = morseEncode(input);
        Serial.println(morse);
        morseTime = millis();
        count = 0;
        state = newChar;
      }
      break;

    case newChar:
      if (morse == " ") state = wordSpace;
      else {
        if (morse[count] == '.') state = dotOn;
        else if (morse[count] == '-') state = dashOn;
      }
      break;
    
    case dotOn:
      digitalWrite(led, HIGH);
      if (millis() - morseTime >= morsePeriod) {
        state = off;
        morseTime += morsePeriod;
      }
      break;

    case dashOn:
      digitalWrite(led, HIGH);
      if (millis() - morseTime >= (3 * morsePeriod)) {
        state = off;
        morseTime += (3 * morsePeriod);
      }
      break;

    case off:
      digitalWrite(led, LOW);
      if (millis() - morseTime >= morsePeriod) {
        count++;
        if (count == morse.length()) state = charSpace;
        else state = newChar;
        morseTime += morsePeriod;
      }
      break;

    case charSpace:
      digitalWrite(led, LOW);
      if (millis() - morseTime >= (2 * morsePeriod)) {
        state = start;
        morseTime += (2 * morsePeriod);
      }
      break;

    case wordSpace:
      digitalWrite(led, LOW);
      if (millis() - morseTime >= (4 * morsePeriod)) {
        state = start;
        morseTime += (4 * morsePeriod);
      }
      break;
  }
  return state;
}

void loop() {
  // No Need to Modify this.  Put most of your code in "convertIncomingCharsToMorseCode()"
  convertIncomingCharsToMorseCode();
}
