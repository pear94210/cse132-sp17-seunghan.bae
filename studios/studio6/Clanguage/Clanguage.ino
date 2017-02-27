// Name(s): Seunghan Bae

char x = 0x54; //01010100
char y = 0xab; //10101011

void setup() {
  Serial.begin(9600);
  Serial.println(x);
  Serial.println(y);
  Serial.println(x & y); //00000000
  Serial.println(x | y); //11111111
  Serial.println(~x | ~y); //11111111
  Serial.println(~x & !y); //00000000
  Serial.println(x && y); //true(1)
  Serial.println(x || y); //true(1)
  Serial.println(!x || !y); //false(0)
  Serial.println(~x && ~y); //true(1)
}

void loop() {

}

