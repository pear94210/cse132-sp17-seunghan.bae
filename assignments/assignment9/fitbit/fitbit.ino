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

bool mode = true;
int modeLed = 13;
unsigned long stepCount = 0;
unsigned long sleepCount = 0;
unsigned long stepTime = 0;
unsigned long sleepTime = 0;
double compare[] = {0, 0, 0};
double prev[] = {0, 0, 0};

int tempSensor = 0;
unsigned long deltaTime = 0;
unsigned long deltaPeriod = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(switchB, INPUT_PULLUP);
  pinMode(resetB, INPUT_PULLUP);
  pinMode(modeLed, OUTPUT);
  accel.init();

  sendDebug("Fitbit");
  sendDebug("Mark.I");
  sendDebug("...buy Apple Watch");
}

void loop() {
  switchMode();
  digitalWrite(modeLed, mode);
  reset();
  
  if (mode) countStep();
  else countSleep();

  unsigned long now = millis();
  if (now - deltaTime >= deltaPeriod) {
    if (mode) sendStep();
    else sendSleep();
    sendTemp();
    sendRuntime(now);
    deltaTime += deltaPeriod;
  }
}

void switchMode() {
  bool reading = digitalRead(switchB);
  if (reading != switchLastState) switchDebTime = millis();

  if (millis() - switchDebTime >= 50) {
    if (reading != switchState) {
      switchState = reading;
      if (!switchState) {
        mode = !mode;
        if (mode) {
          stepCount = 0;
          stepTime = millis();
        }
        else {
          sleepCount = 0;
          sleepTime = millis();
        }
      }
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
        else sleepCount = 0;
      }
    }
  }

  resetLastState = reading;
}

void countStep() {
  if (millis() - stepTime >= 50) {
    if (accel.available()) {
      accel.read();
    
      compare[0] = compare[1];
      compare[1] = compare[2];
      compare[2] = accel.cz;

      if ((compare[1] > compare[0]) && (compare[1] > compare[2]) && (compare[1] > 1.3)) stepCount++;
    }
    stepTime += 50;
  }
}

void countSleep() {
  if (millis() - sleepTime >= 50) {
    if (accel.available()) {
      accel.read();

      bool boolX = abs(accel.cx - prev[0]) < 0.1;
      bool boolY = abs(accel.cy - prev[1]) < 0.1;
      bool boolZ = abs(accel.cz - prev[2]) < 0.1;

      if (boolX && boolY && boolZ) sleepCount += 50;

      prev[0] = accel.cx;
      prev[1] = accel.cy;
      prev[2] = accel.cz;
    }
    sleepTime += 50;
  }
}

void sendDebug(String s) {
  Serial.write(0x23);
  Serial.write(0x30);
  Serial.write((s.length() >> 8) & 0xff);
  Serial.write(s.length() & 0xff);
  for (int i = 0; i < s.length(); i++) {
    Serial.write(s[i]);
  }
}

void sendError(String s) {
  Serial.write(0x23);
  Serial.write(0x31);
  Serial.write((s.length() >> 8) & 0xff);
  Serial.write(s.length() & 0xff);
  for (int i = 0; i < s.length(); i++) {
    Serial.write(s[i]);
  }
}

void sendStep() {
  Serial.write(0x23);
  Serial.write(0x32);
  Serial.write(stepCount >> 24);
  Serial.write(stepCount >> 16);
  Serial.write(stepCount >> 8);
  Serial.write(stepCount);
}

void sendSleep() {
  Serial.write(0x23);
  Serial.write(0x33);
  Serial.write(sleepCount >> 24);
  Serial.write(sleepCount >> 16);
  Serial.write(sleepCount >> 8);
  Serial.write(sleepCount);
}

void sendTemp() {
  int tempReading = analogRead(tempSensor);
  float temp = (tempReading * 500.0 / 1023) - 50;
  unsigned long longTemp = *(unsigned long *) &temp;

  Serial.write(0x23);
  Serial.write(0x34);
  Serial.write(longTemp >> 24);
  Serial.write(longTemp >> 16);
  Serial.write(longTemp >> 8);
  Serial.write(longTemp);
}

void sendRuntime(unsigned long runtime) {
  Serial.write(0x23);
  Serial.write(0x35);
  Serial.write(runtime >> 24);
  Serial.write(runtime >> 16);
  Serial.write(runtime >> 8);
  Serial.write(runtime);
}

