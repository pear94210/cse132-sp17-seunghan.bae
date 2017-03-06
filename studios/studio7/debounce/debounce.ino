// Name(s): Seunghan Bae

int button = 12;
int buttonState = LOW;
int lastState = LOW;

unsigned long debounceDelay = 50;
unsigned long debounceTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(button);
  if (reading != lastState) debounceTime = millis();

  unsigned long now = millis();
  if (now - debounceTime >= debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState) Serial.println("Now pressed");
      else Serial.println("Pressed");
    }
  }

  lastState = reading;
}
