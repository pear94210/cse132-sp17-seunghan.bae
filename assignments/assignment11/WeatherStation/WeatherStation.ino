// Name(s): Seunghan Bae

#include "font.h"

int row[] = {2, 3, 4, 5, 6, 7, 8};
int col[] = {13, 12, 11, 10, 9};

int colNum = 0;
const unsigned long frameLength = 25;
unsigned long frameTime = 0;

const unsigned long deltaPeriod = 60000;
unsigned long deltaTime = 0;
int i = 3;
int currentInt = 3;
byte weather = 0x20;

float x[] = {38.649196, 37.373422, 59.330147};
float y[] = {-90.306099, 127.106715, 18.058155};

void setup() {
  Serial.begin(9600);
  for (int r = 0; r < 7; r++) pinMode(row[r], OUTPUT);
  for (int c = 0; c < 5; c++) pinMode(col[c], OUTPUT);
}

void loop() {
  if (analogRead(0) < 341) i = 0;
  else if (analogRead(0) < 682) i = 1;
  else i = 2;

  unsigned long now = millis();
  if ((i != currentInt) || (now - deltaTime >= deltaPeriod)) {
    toJava(i);
    currentInt = i;
    deltaTime = now;
  }
  
  weather = fromJava();

  displayLed(weather);
}

void toJava(int n) {
  unsigned long longX = *(unsigned long *) &x[n];
  unsigned long longY = *(unsigned long *) &y[n];

  Serial.write(0x21);  
  Serial.write(longX >> 24);
  Serial.write(longX >> 16);
  Serial.write(longX >> 8);
  Serial.write(longX);
  Serial.write(longY >> 24);
  Serial.write(longY >> 16);
  Serial.write(longY >> 8);
  Serial.write(longY);
}

byte fromJava() {
  byte ans = weather;
  if (Serial.available()) {
    if (Serial.read() == 0x21) {
      delay(100);
      ans = Serial.read();
    }
  }
  return ans;
}

void displayLed(byte weather) {
  for (int c = 0; c < 5; c++) {
    if (c == colNum) digitalWrite(col[c], LOW);
    else digitalWrite(col[c], HIGH);
  }
  for (int r = 0; r < 7; r++) digitalWrite(row[r], font_5x7[weather - 0x20][colNum] & (0x01 << r + 1));
  
  if (millis() - frameTime >= frameLength / 5) {
      if (colNum == 4) colNum = 0;
      else colNum++;
      frameTime += frameLength / 5;
  }
}

