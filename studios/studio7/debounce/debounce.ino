// Name(s): Seunghan Bae

int button = 12;
int buttonState = LOW;
int tempState = LOW;

unsigned long debounceDelay = 100;
unsigned long debounceTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int reading - digitalRead(button);
  if (reading != tempState) debounceTime = millis();

  if (millis() - debounceTime >= debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      Serial.println(buttonState);
    }
  }

  tempState = reading;
}
