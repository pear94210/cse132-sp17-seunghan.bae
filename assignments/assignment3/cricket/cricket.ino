// Name(s): Seunghan Bae

/* 
 *  mV = 10t + 500
 *  analog = (1023/1100)mV
 *  =>
 *  mV = (1100/1023)analog
 *  t = (mV - 500)/10 = 0.1mV - 50
 *  =>
 *  t = (110/1023)analog - 50
 */

 /*
  * t = 10 + (n_60 - 40)/7
  * => n_60 = 7t - 30
  * => sec per chirp = 60/(7t - 30)
  * => millis per chirp = 60000/(7t - 30)
  */

const unsigned long deltaPeriod = 250;
unsigned long deltaTime = 0;
unsigned long blinkTime = 0;

#define FILTER_COUNTS 8
float temperatures[FILTER_COUNTS];
int count = 0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(12, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  if (now - deltaTime >= deltaPeriod) {
    readTemp();
    Serial.print(temperatures[(count-1) % FILTER_COUNTS]);
    Serial.print(" ");
    Serial.println(getAvgTemp());
    
    deltaTime += deltaPeriod;
  }
  blinkLight(12);
}

void readTemp() {
  int reading = analogRead(0);
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

void blinkLight(int n) {
  unsigned long blinkPeriod = (60000 / ((7 * getAvgTemp()) - 30));
  int BLINK_DURATION = 200;
  unsigned long now = millis();

  if (digitalRead(n)) {
    if ((now - blinkTime) >= BLINK_DURATION) {
      digitalWrite(n, LOW);
      blinkTime += BLINK_DURATION;
    }
  } else {
    if ((now - blinkTime) >= blinkPeriod - BLINK_DURATION) {
      digitalWrite(n, HIGH);
      blinkTime += blinkPeriod - BLINK_DURATION;
    }
  }
}
