// Name(s): Seunghan Bae

int led = 13;
int button = 12;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  bool lastButton = digitalRead(button);
  bool thisButton = digitalRead(button);
  digitalWrite(led, !digitalRead(button));
  if (thisButton == lastButton + 1) {
    count++;
    Serial.println(count);
  }
}

