// Name(s): Seunghan Bae

#include <Wire.h>
#include <SparkFun_MMA8452Q.h>

MMA8452Q accel;
int count = 0;
double compare[] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  accel.init();
}

void loop() {
  if (accel.available()) {
    accel.read();
//    printCalculatedAccels();
    printCount();
    Serial.println();
  }
}

void printCalculatedAccels() {
  Serial.print(accel.cx, 3);
  Serial.print(",");
  Serial.print(accel.cy, 3);
  Serial.print(",");
  Serial.print(accel.cz, 3);
}

void printCount() {
  compare[0] = compare[1];
  compare[1] = compare[2];
  compare[2] = accel.cz;

  if ((compare[1] > compare[0]) && (compare[1] > compare[2]) && (compare[1] > 1)) {
    count++;
    Serial.print(count);
  }
}

