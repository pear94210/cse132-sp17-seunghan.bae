// Name(s): Seunghan Bae

enum State {
  idle,
  cold5,
  hot7,
  medium7,
  dry2,
  dry7,
};

State washState = idle;

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  washState = washer(washState);
}

State washer(State state) {
  switch (state) {
    case idle:
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(13, LOW);
      if (digitalRead(3) == 0) {
        if (analogRead(0) > 682) {
          state = cold5;
        } else {
          state = hot7;
        }
      } else {
        state = idle;
      }
      break;

    case cold5:
      Serial.println("cold wash for 5 min");
      digitalWrite(4, HIGH);
      digitalWrite(13, HIGH);
      delay(5000);
      if (analogRead(0) > 682) {
        state = dry2;
      } else {
        state = dry7;
      }
      break;

    case hot7:
      Serial.println("hot wash for 7 min");
      digitalWrite(5, HIGH);
      digitalWrite(13, HIGH);
      delay(7000);
      if (analogRead(0) > 682) {
        state = dry2;
      } else if (analogRead(0) < 341) {
        state = medium7;
      } else {
        state = dry7;
      }
      break;

    case medium7:
      Serial.println("medium wash for 7 min");
      digitalWrite(4, HIGH);
      delay(7000);
      state = dry7;
      break;

    case dry2:
      Serial.println("dry for 2 min");
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(2000);
      state = idle;
      break;

    case dry7:
      Serial.println("dry for 7 min");
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(7000);
      state = idle;
      break;
  }

  return state;
}

