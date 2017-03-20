#include <Wire.h>
#include <SparkFun_MMA8452Q.h>

// Name(s): Seunghan Bae

MMA8425Q accel;

void setup() {
  Serial.begin(9600);
  accel.init();
}

void loop() {
  if (accel.available) {
    accel.read();

    // FIXME
  }
}

