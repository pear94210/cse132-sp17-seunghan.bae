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
      pprint(state);
      if (checkReverse() == 0) state = up3;
      else state = down1;
      break;

    case up3:
      bit1 = 1;
      pprint(state);
      if (checkReverse() == 0) state = up4;
      else state = down2;
      break;

    case up4:
      bit1 = 0;
      bit2 = 0;
      bit3 = 1;
      pprint(state);
      if (checkReverse() == 0) state = up5;
      else state = down3;
      break;

    case up5:
      bit1 = 1;
      pprint(state);
      if (checkReverse() == 0) state = up6;
      else state = down4;
      break;

    case up6:
      bit1 = 0;
      bit2 = 1;
      pprint(state);
      if (checkReverse() == 0) state = up7;
      else state = down5;
      break;

    case up7:
      bit1 = 1;
      pprint(state);
      if (checkReverse() == 0) state = up0;
      else state = down6;
      break;

    case down0:
      bit1 = 0;
      bit2 = 0;
      bit3 = 0;
      pprint(state);
      if (checkReverse() == 0) state = down7;
      else state = up1;
      break;
       
    case down1:
      bit1 = 1;
      pprint(state);
      if (checkReverse() == 0) state = down0;
      else state = up2;
      break;

    case down2:
      bit1 = 0;
      bit2 = 1;
      pprint(state);
      if (checkReverse() == 0) state = down1;
      else state = up3;
      break;

    case down3:
      bit1 = 1;
      pprint(state);
      if (checkReverse() == 0) state = down2;
      else state = up4;
      break;

    case down4:
      bit1 = 0;
      bit2 = 0;
      bit3 = 1;
      pprint(state);
      if (checkReverse() == 0) state = down3;
      else state = up5;
      break;

    case down5:
      bit1 = 1;
      pprint(state);
      if (checkReverse() == 0) state = down4;
      else state = up6;
      break;

    case down6:
      bit1 = 0;
      bit2 = 1;
      pprint(state);
      if (checkReverse() == 0) state = down5;
      else state = up7;
      break;

    case down7:
      bit1 = 1;
      pprint(state);
      if (checkReverse() == 0) state = down6;
      else state = up0;
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

