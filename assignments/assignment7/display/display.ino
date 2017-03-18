/* display
 *  
 *  CSE 132 - Assignment 7
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Seunghan Bae
 *  WUSTL Key: seunghan.bae
 *  
 *  Name:
 *  WUSTL Key:
 *  
 */

#include "font.h"

int row[] = {2, 3, 4, 5, 6, 7, 8};
int col[] = {13, 12, 11, 10, 9};
//int row[] = {7, 8, 9, 10, 11, 12, 13};
//int col[] = {6, 5, 4, 3, 2};

int colNum = 0;
byte count = 0x00;
int upButton = 0;
int downButton = 1;
bool upState = LOW;
bool downState = LOW;
bool lastUpState = LOW;
bool lastDownState = LOW;

const unsigned long frameLength = 20;
unsigned long frameTime = 0;
const unsigned long buttonDelay = 50;
unsigned long upTime = 0;
unsigned long downTime = 0;

void setup () {
  Serial.begin(9600);
  for (int r = 0; r < 7; r++) pinMode(row[r], OUTPUT);
  for (int c = 0; c < 5; c++) pinMode(col[c], OUTPUT);
}

void loop () { 
  for (int c = 0; c < 5; c++) {
    if (c == colNum) digitalWrite(col[c], LOW);
    else digitalWrite(col[c], HIGH);
  }
  for (int r = 0; r < 7; r++) digitalWrite(row[r], font_5x7[count][colNum] & (0x01 << r + 1));
  
  if (millis() - frameTime >= frameLength / 5) {
      if (colNum == 4) colNum = 0;
      else colNum++;
      frameTime += frameLength / 5;
  }

  upPressed();
  downPressed();
}

void upPressed() {
  bool reading = analogRead(upButton);
  Serial.println(reading);
  if (reading != lastUpState) upTime = millis();

  unsigned long now = millis();
  if (now - upTime >= buttonDelay) {
    if (reading != upState) {
      upState = reading;
      if (!upState) {
        if (count == 95) count = 0;
        else count++;
      }
    }
  }

  lastUpState = reading;
}

void downPressed() {
  bool reading = analogRead(downButton);
  Serial.println(reading);
  if (reading != lastDownState) downTime = millis();

  unsigned long now = millis();
  if (now - downTime >= buttonDelay) {
    if (reading != downState) {
      downState = reading;
      if (!downState) {
        if (count == 0) count = 95;
        else count--;
      }
    }
  }

  lastDownState = reading;
}

