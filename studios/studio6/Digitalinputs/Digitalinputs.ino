// Name(s): Seunghan Bae

int button = 3;
unsigned long pressed = 0;
unsigned long unpressed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button) == 1) {
    Serial.print("Have been pressing for ");
    Serial.print(pressed - unpressed);
    Serial.println(" sec");
  }
  while (digitalRead(button) == 1) {
    unpressed = millis();
  }
  if (digitalRead(button) == 0) {
    Serial.println("pressed");
    Serial.print(unpressed - pressed);
    Serial.println(" sec after last pressed");
  }
  while (digitalRead(button) == 0) {
    pressed = millis();
  }
}

