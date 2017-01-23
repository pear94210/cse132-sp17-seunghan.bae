// Name(s): Seunghan Bae / Skylar Nam

enum State {
  up0,        // 0
  up1,        // 1
  up2,        // 2
  up3,        // 3
  up4,        // 4
  up5,        // 5
  up6,        // 6
  up7,        // 7
};

// Create a global Variable to keep track of the state we are currently in. (Start in up0).
State counterState = up0; 
bool bit1;
bool bit2;
bool bit3;


void setup() {
  Serial.begin(9600);
}

void loop() {
  counterState = nextState(counterState);
  delay(1000);
}


// A "nextState()" function is often used to
// Compute (and return) the state to go to next. 
// I.e., act like the arrows on the FSM diagram.
State nextState(State state) {
  switch (state) {
    case up0:               //When state up0 , the FSM must:

      bit1 = 0;             //set the bits to match the Count
      bit2 = 0;
      bit3 = 0;

      pprint(state);


      state = up1;          //Move to the next state
      //The next loop will go to case up1

      break;                //Break to the end of the switch
                            //So the next case won't run
 
    case up1:               //only if counterState == up1
      bit1 = 1;
      pprint(state);
      state = up2;
      break;

    case up2:
      bit1 = 0;
      bit2 = 1;
      pprint(state);
      state = up3;
      break;

    case up3:
      bit1 = 1;
      pprint(state);
      state = up4;
      break;

    case up4:
      bit1 = 0;
      bit2 = 0;
      bit3 = 1;
      pprint(state);
      state = up5;
      break;

    case up5:
      bit1 = 1;
      pprint(state);
      state = up6;
      break;

    case up6:
      bit1 = 0;
      bit2 = 1;
      pprint(state);
      state = up7;
      break;

    case up7:
      bit1 = 1;
      pprint(state);
      state = up0;
      break;
  }
  return state;
}


void pprint(State state) {
  Serial.print(state);
  Serial.print("  :  ");
  Serial.print(bit3);
  Serial.print(bit2);
  Serial.println(bit1);
}

