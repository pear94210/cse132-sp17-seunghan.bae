// Name(s): Seunghan Bae

const unsigned long deltaPeriod = 1000;
const unsigned long tempPeriod = 250;
unsigned long deltaTime = 0;
unsigned long tempTime = 0;

#define FILTER_COUNTS 8
float temperatures[FILTER_COUNTS];
int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();

  //sendDebug("java");
  //sendDebug("arduino");
  //sendDebug("hello world");
  
  if (now - deltaTime >= deltaPeriod) {
    unsigned long nowTime = now;
    sendMillis(nowTime);
    int pot = analogRead(0);
    sendPotentiometer(pot);

    deltaTime += deltaPeriod;
  }

  if (now - tempTime >= tempTPeriod) {
    int temp = analogRead(1);
    readTemp(temp);
    sendTempAD(temp);
    sendTempUnfiltered(temp);
    sendTempFiltered(temp);
    
    tempTime += tempPeriod;
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

void sendMillis(unsigned long l) {
    Serial.write(0x21);
    Serial.write(0x32);
    Serial.write(0x04);
    Serial.write((l >> 24) & 0xff);
    Serial.write((l >> 16) & 0xff);
    Serial.write((l >> 8) & 0xff);
    Serial.write(l & 0xff);
}

void sendPotentiometer(int pot) {
  Serial.write(0x21);
  Serial.write(0x33);
  Serial.write(0x02);
  Serial.write((pot >> 8) & 0xff);
  Serial.write(pot & 0xff);
}

void sendTempAD(int temp) {
  Serial.write(0x21);
  Serial.write(0x34);
  Serial.write(0x02);
  Serial.write((temp >> 8) & 0xff);
  Serial.write(temp & 0xff);
}

void sendTempUnfiltered(int temp) {
  float tempUnfiltered = temperatures[(count-1) % FILTER_COUNTS];
  unsigned long rawBits = *(unsigned long *) &tempUnfiltered;
  
  Serial.write(0x21);
  Serial.write(0x35);
  Serial.write(0x04);
  Serial.write((rawBits >> 24) & 0xff);
  Serial.write((rawBits >> 16) & 0xff);
  Serial.write((rawBits >> 8) & 0xff);
  Serial.write(rawBits & 0xff);
}

void sendTempFiltered(int temp) {
  float tempFiltered = getAvgTemp();
  unsigned long rawBits = *(unsigned long *) &tempFiltered;
  
  Serial.write(0x21);
  Serial.write(0x36);
  Serial.write(0x04);
  Serial.write((rawBits >> 24) & 0xff);
  Serial.write((rawBits >> 16) & 0xff);
  Serial.write((rawBits >> 8) & 0xff);
  Serial.write(rawBits & 0xff);
}

void readTemp(int reading) {
  float temperature = (reading * 110.0 / 1023) - 50;
  temperatures[count % FILTER_COUNTS] = temperature;
  count += 1;
}

float getAvgTemp() {
  float tempSum = 0;
  for (int i = 0; i < FILTER_COUNTS; i++) {
    tempSum += temperatures[i];
  }
  
  if (count < FILTER_COUNTS) {
    return tempSum / count;
  } else {
    return tempSum / FILTER_COUNTS;
  }
}
