// Name(s): Seunghan Bae

enum State {
  carGo,
  carYellow,
  carStop,
  pedestrianGo,
  pedestrianStop
};

const unsigned long trafficPeriod = 7500;
const unsigned long yellowPeriod = 2000;
const unsigned long blinkPeriod = 500;
unsigned long trafficTime = 0;
unsigned long blinkTime = 0;
State traffic = carGo;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  traffic = trafficSignal(traffic);
}

State trafficSignal(State state) {
  unsigned long now = millis();
  
  switch (state) {
    case carGo:
      light(state);
      if (now - trafficTime >= trafficPeriod) {
        state = carYellow;
        trafficTime += trafficPeriod;
      }
      break;

    case carYellow:
      light(state);
      if (now - trafficTime >= yellowPeriod) {
        state = carStop;
        trafficTime += yellowPeriod;
      }
      break;

    case carStop:
      light(state);
      state = pedestrianGo;
      break;

    case pedestrianGo:
      light(state);
      if (now - trafficTime >= trafficPeriod) {
        state = pedestrianStop;
        trafficTime += trafficPeriod;
      }
      break;

    case pedestrianStop:
      light(state);
      state = carGo;
      break;
  }
  return state;
}

void light(State state) {
  switch(state) {
    case carGo:
      digitalWrite(12, LOW);
      digitalWrite(10, HIGH);
      blinkLight(8);
      break;
    
    case carYellow:
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      blinkLight(8);
      break;

    case carStop:
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      break;

    case pedestrianGo:
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;

    case pedestrianStop:
      digitalWrite(9, LOW);
      blinkLight(8); 
  }
}

void blinkLight(int n) {
  unsigned long now = millis();
  if((now - blinkTime) >= blinkPeriod) {
    digitalWrite(n, !digitalRead(n));
    blinkTime += blinkPeriod;
  }
}
