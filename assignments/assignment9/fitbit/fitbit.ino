// Name(s): Seunghan Bae

#include <Wire.h>
#include <SparkFun_MMA8452Q.h>

MMA8452Q accel;

int switchB = 12;
bool switchState = LOW;
bool switchLastState = LOW;
unsigned long switchDebTime = 0;

int resetB = 11;
bool resetState = LOW;
bool resetLastState = LOW;
unsigned long resetDebTime = 0;

int tempSensor = 0;
unsigned long deltaTime = 0;

bool mode = true;
unsigned long stepCount = 0;
unsigned long sleepTime = 0;
double compare[] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  pinMode(switchB, INPUT_PULLUP);
  pinMode(resetB, INPUT_PULLUP);
  accel.init();

  sendDebug("Fitbit");
  sendDebug("Mark.I");
  sendDebug("...buy Apple Watch");
}

void loop() {
  switchMode();
  reset();

  if (mode) countStep();
  else countSleep();

  unsigned long now = millis();
  if (now - deltaTime >= 1000) {
    sendTemp();
    sendRuntime(now);
    deltaTime += 1000;
  }
}

void sendDebug(String s) {
  Serial.write(0x21);
  Serial.write(0x30);
  Serial.write((s.length() >> 8) & 0xff);
  Serial.write(s.length() & 0xff);
  for (int i = 0; i < s.length(); i++) {
    Serial.write(s[i]);
  }
}

void sendError(String s) {
  Serial.write(0x21);
  Serial.write(0x31);
  Serial.write((s.length() >> 8) & 0xff);
  Serial.write(s.length() & 0xff);
  for (int i = 0; i < s.length(); i++) {
    Serial.write(s[i]);
  }
}

void switchMode() {
  bool reading = digitalRead(switchB);
  if (reading != switchLastState) switchDebTime = millis();

  if (millis() - switchDebTime >= 50) {
    if (reading != switchState) {
      switchState = reading;
      if (!switchState) mode = !mode;
    }
  }

  switchLastState = reading;
}

void reset() {
  bool reading = digitalRead(resetB);
  if (reading != resetLastState) resetDebTime = millis();

  if (millis() - resetDebTime >= 50) {
    if (reading != resetState) {
      resetState = reading;
      if (!resetState) {
        if (mode) stepCount = 0;
        else sleepTime = 0;
      }
    }
  }

  resetLastState = reading;
}

void countStep() {
  if (accel.available()) {
    accel.read();
    // FIXME
  }
}

void countSleep() {
  if (accel.available()) {
    accel.read();
    // FIXME
  }
}

void sendTemp() {
  int tempReading = analogRead(tempSensor);
  float temp = (tempReading * 500.0 / 1023) - 50;
  unsigned long longTemp = *(unsigned long *) &temp;

  Serial.write(0x21);
  Serial.write(0x34);
  Serial.write(longTemp >> 24);
  Serial.write(longTemp >> 16);
  Serial.write(longTemp >> 8);
  Serial.write(longTemp);
}

void sendRuntime(unsigned long runtime) {
  Serial.write(0x21);
  Serial.write(0x35);
  Serial.write(runtime >> 24);
  Serial.write(runtime >> 16);
  Serial.write(runtime >> 8);
  Serial.write(runtime);
}

