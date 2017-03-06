// Name(s): Seunghan Bae

int row[] = {8, 7, 6, 5, 4, 3, 2};
int col[] = {13, 12, 11, 10, 9};

void setup() {
  Serial.begin(9600);
  for (int r = 0; r < 7; r++) pinMode(row[r], OUTPUT);
  for (int c = 0; c < 5; c++) pinMode(col[c], OUTPUT);
}

void loop() {
  
//  1: Light an individual LED
//  for (int r = 0; r < 7; r++) digitalWrite(row[r], LOW);
//  for (int c = 0; c < 5; c++) digitalWrite(col[c], LOW);
//  delay(1000);
//
//  for (int r = 0; r < 7; r++) digitalWrite(row[r], HIGH);
//  for (int c = 1; c < 5; c++) digitalWrite(col[c], HIGH);
//  delay(1000);
//
//  for (int r = 1; r < 7; r++) digitalWrite(row[r], LOW);
//  delay(1000);

//  2: Binary encoding
//  for (int c = 1; c < 5; c++) digitalWrite(col[c], HIGH);
//
//  for (int i = 0; i < 8; i++) {
//    digitalWrite(row[0], i & B00000001);
//    digitalWrite(row[1], i & B00000010);
//    digitalWrite(row[2], i & B00000100);
//    delay(1000);
//  }

// 3: One-hot encoding
  for (int c = 0; c < 5; c++) digitalWrite(col[c], HIGH);
  
  for (int c = 0; c < 5; c++) {
    if (c == 0) digitalWrite(col[c + 4], HIGH);
    else digitalWrite(col[c - 1], HIGH);
    digitalWrite(col[c], LOW);
    
    for (int r = 0; r < 7; r++) {
      if (r == 0) digitalWrite(row[r + 6], LOW);
      else digitalWrite(row[r - 1], LOW);
      digitalWrite(row[r], HIGH);
      delay(1000);
    }
  }
}

