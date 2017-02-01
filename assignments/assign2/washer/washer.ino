// Name(s): Seunghan Bae

enum State {
  idle,
  ecnWash,
  ecnDry,
  dlxWash,
  dlxDry,
  sprWash,
  sprDry
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
          state = ecnWash;
        } else if (analogRead(0) < 341) {
          state = sprWash;
        } else {
          state = dlxWash;
        }
      }
      break;

    case ecnWash:
      Serial.println("Economy Wash");
      digitalWrite(4, HIGH);
      digitalWrite(13, HIGH);
      delay(5000);
      if (analogRead(0) > 682) {
        state = ecnDry;
      } else {
        state = dlxDry;
      }
      break;

    case ecnDry:
      Serial.println("Economy Dry");
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(2000);
      state = idle;
      break;

    case dlxWash:
      Serial.println("Deluxe Wash");
      digitalWrite(5, HIGH);
      digitalWrite(13, HIGH);
      delay(7000);
      if (analogRead(0) > 682) {
        state = ecnDry;
      } else {
        state = dlxDry;
      }
      break;

    case dlxDry:
      Serial.println("Deluxe Dry");
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(7000);
      state = idle;
      break;

    case sprWash:
      Serial.println("Super Deluxe Wash");
      digitalWrite(5, HIGH);
      digitalWrite(13, HIGH);
      delay(7000);
      if (analogRead(0) > 682) {
        state = ecnDry;
      } else {
        digitalWrite(4, HIGH);
        delay(7000);
        state = sprDry;
      }
      break;

    case sprDry:
      Serial.println("Super Deluxe Dry");
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(7000);
      state = idle;
      break;
  }

  return state;
}

