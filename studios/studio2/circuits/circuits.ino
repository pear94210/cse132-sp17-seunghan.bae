// Name(s): Seunghan Bae

enum State {
  up0,
  up1,
  up2,
  up3,
  up4,
  up5,
  up6,
  up7
};

State counterState = up0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  counterState = nextState(counterState);
  delay(1000);
}

State nextState(State state) {
  switch (state) {
    case up0:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      state = up1;
      break;

    case up1:
      digitalWrite(5, HIGH);
      state = up2;
      break;
      
    case up2:
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      state = up3;
      break;

    case up3:
      digitalWrite(5, HIGH);
      state = up4;
      break;

    case up4:
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      state = up5;
      break;

    case up5:
      digitalWrite(5, HIGH);
      state = up6;
      break;

    case up6:
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      state = up7;
      break;

    case up7:
      digitalWrite(5, HIGH);
      state = up0;
      break;
  }
  return state;
}

