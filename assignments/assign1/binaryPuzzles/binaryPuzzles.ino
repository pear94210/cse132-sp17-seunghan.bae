// Name(s): 

void setup() {  
  Serial.begin(9600);
}

void loop() {
  //Test Cases:
  Serial.println();
  Serial.print("shiftRight(5,1) should return 2:          ");
  Serial.println(shiftRight(5,1));
  Serial.print("shiftRight(7,4) should return 0:          ");
  Serial.println(shiftRight(7,4));

  Serial.println();
  Serial.print("shiftLeft(5,2) should return 20:          ");
  Serial.println(shiftLeft(5,2));
  Serial.print("shiftLeft(-1,1) should return -2:        ");
  Serial.println(shiftLeft(-1,1));

  Serial.println();
  Serial.print("hasAOne(4) should return 1:               ");
  Serial.println(hasAOne(4));
  Serial.print("hasAOne(0) should return 0:               ");
  Serial.println(hasAOne(0));

  Serial.println();
  Serial.print("hasAZero(5) should return 1:              ");
  Serial.println(hasAZero(5));
  Serial.print("hasAZero(-1) should return 0:             ");
  Serial.println(hasAZero(-1));
    
  Serial.println();
  Serial.print("leastSigHasAOne(255) should return 1:     ");
  Serial.println(leastSigHasAOne(255));
  Serial.print("leastSigHasAOne(256) should return 0:     ");
  Serial.println(leastSigHasAOne(256));

  Serial.println();
  Serial.print("isNegativeInt(-500) should return 1:      ");
  Serial.println(isNegativeInt(-500));
  Serial.print("isNegativeInt(500) should return 0:       ");
  Serial.println(isNegativeInt(500));

  Serial.println();
  Serial.print("isNegativeLong(-40000) should return 1:   ");
  Serial.println(isNegativeLong(-40000));
  Serial.print("isNegativeLong(40000) should return 0:    ");
  Serial.println(isNegativeLong(40000));

  Serial.println();
  Serial.print("isNegativeChar(-5) should return 1:       ");
  Serial.println(isNegativeChar(-5));
  Serial.print("isNegativeChar(1) should return 0:        ");
  Serial.println(isNegativeChar(1));

  Serial.println();
  Serial.print("negate(-500) should return 500:           ");
  Serial.println(negate(-500));
  Serial.print("negate(500) should return -500:          ");
  Serial.println(negate(500));
}

// TODO: Complete/fix the following functions, using only the bitwise and Boolean operators
//       (No if-statements, while-loops or other conditional 

// Return an int
int shiftRight(int num, int n){
  return num;
}

// Return an int
int shiftLeft(int num, int n){
  return num;
}

/// The remaining functions should return 1 (true) if the condition is met and 0 (false) if it is not

int hasAOne(int num) {
  return num;
}

int hasAZero(int num) {
  return num;
}

int leastSigHasAOne(int num) {
  return num;
}

int isNegativeInt(int num) {
  return num;
}

int isNegativeLong(long num) {
  return num;
}

int isNegativeChar(char num) {
  return num;
}

int negate(int num) {
  return num;
}

