// Name(s): Seunghan Bae

#include "font.h"

int row[] = {2, 3, 4, 5, 6, 7, 8};
int col[] = {13, 12, 11, 10, 9};

void setup() {
  Serial.begin(9600);
  for (int r = 0; r < 7; r++) pinMode(row[r], OUTPUT);
  for (int c = 0; c < 5; c++) pinMode(col[c], OUTPUT);
}

void loop() {
  
}

