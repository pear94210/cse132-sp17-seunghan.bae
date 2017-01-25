// Name(s): Seunghan Bae

enum State {
  up0,
  up1,
  up2,
  up3,
  up4,
  up5,
  up6,
  up7,
  down0,
  down1,
  down2,
  down3,
  down4,
  down5,
  down6,
  down7
};

State counterState = up0;
bool bit1;
bool bit2;
bool bit3;
bool reverse = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  counterState = nextState(counterState);
  delay(1000);
}


State nextState(State state){
  switch (state) {
    case up0:
      bit1 = 0;
      bit2 = 0;
      bit3 = 0;
      pprint(state);
      if (checkReverse() == 0) {
        state = up1;
      } else {
        Serial.println("--Reverse--");
        state = down7;
      }
      break;
       
    case up1:
      bit1 = 1;
      bit2 = 0;
      bit3 = 0;
      pprint(state);
      if (checkReverse() == 0) {
        state = up2;
      } else {
        Serial.println("--Reverse--");
        state = down0;
      }
      break;

    case up2:
      bit1 = 0;
      bit2 = 1;
      bit3 = 0;
      pprint(state);
      if (checkReverse() == 0) {
        state = up3;
      } else {
        Serial.println("--Reverse--");
        state = down1;
      }
      break;

    case up3:
      bit1 = 1;
      bit2 = 1;
      bit3 = 0;
      pprint(state);
      if (checkReverse() == 0) {
        state = up4;
      } else {
        Serial.println("--Reverse--");
        state = down2;
      }
      break;

    case up4:
      bit1 = 0;
      bit2 = 0;
      bit3 = 1;
      pprint(state);
      if (checkReverse() == 0) {
        state = up5;
      } else {
        Serial.println("--Reverse--");
        state = down3;
      }
      break;

    case up5:
      bit1 = 1;
      bit2 = 0;
      bit3 = 1;
      pprint(state);
      if (checkReverse() == 0) {
        state = up6;
      } else {
        Serial.println("--Reverse--");
        state = down4;
      }
      break;

    case up6:
      bit1 = 0;
      bit2 = 1;
      bit3 = 1;
      pprint(state);
      if (checkReverse() == 0) {
        state = up7;
      } else {
        Serial.println("--Reverse--");
        state = down5;
      }
      break;

    case up7:
      bit1 = 1;
      bit2 = 1;
      bit3 = 1;
      pprint(state);
      if (checkReverse() == 0) {
        state = up0;
      } else {
        Serial.println("--Reverse--");
        state = down6;
      }
      break;

    case down0:
      bit1 = 0;
      bit2 = 0;
      bit3 = 0;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down7;
      } else {
        Serial.println("--Reverse--");
        state = up1;
      }
      break;
       
    case down1:
      bit1 = 1;
      bit2 = 0;
      bit3 = 0;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down0;
      } else {
        Serial.println("--Reverse--");
        state = up2;
      }
      break;

    case down2:
      bit1 = 0;
      bit2 = 1;
      bit3 = 0;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down1;
      } else {
        Serial.println("--Reverse--");
        state = up3;
      }
      break;

    case down3:
      bit1 = 1;
      bit2 = 1;
      bit3 = 0;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down2;
      } else {
        Serial.println("--Reverse--");
        state = up4;
      }
      break;

    case down4:
      bit1 = 0;
      bit2 = 0;
      bit3 = 1;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down3;
      } else {
        Serial.println("--Reverse--");
        state = up5;
      }
      break;

    case down5:
      bit1 = 1;
      bit2 = 0;
      bit3 = 1;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down4;
      } else {
        Serial.println("--Reverse--");
        state = up6;
      }
      break;

    case down6:
      bit1 = 0;
      bit2 = 1;
      bit3 = 1;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down5;
      } else {
        Serial.println("--Reverse--");
        state = up7;
      }
      break;

    case down7:
      bit1 = 1;
      bit2 = 1;
      bit3 = 1;
      pprint(state - 8);
      if (checkReverse() == 1) {
        state = down6;
      } else {
        Serial.println("--Reverse--");
        state = up0;
      }
      break; 
  }
  return state;
}

bool checkReverse(){
  if (Serial.read() != -1) {
    reverse = !reverse;
  }
  return reverse;
}

void pprint(State state) {
  Serial.print(state);
  Serial.print("  :  ");
  Serial.print(bit3);
  Serial.print(bit2);
  Serial.println(bit1);
}

