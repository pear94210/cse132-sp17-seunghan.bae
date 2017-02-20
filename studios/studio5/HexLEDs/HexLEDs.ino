// Name(s): Seunghan Bae

int bit0 = 12;
int bit1 = 11;
int bit2 = 10;
int bit3 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(bit0, OUTPUT);
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    byte myVar = Serial.read();
    Serial.print((char)myVar);
    Serial.print(": ");
    
    if (myVar >= 0x30 && myVar <= 0x39) myVar -= 0x30;
    else if (myVar >= 0x41 && myVar <= 0x46) myVar -= 0x37;
    else if (myVar >= 0x61 && myVar <= 0x66) myVar -= 0x57;
    else myVar = -1;

    if (myVar >= 0x00 && myVar <= 0x0f) Serial.println(myVar);
    numLED(myVar);
  }
}

void numLED(byte myVar) {
  switch (myVar) {
    case 0x00:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, LOW);
      break;

   case 0x01:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, LOW);
      break;

    case 0x02:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, LOW);
      break;

    case 0x03:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, LOW);
      break;

    case 0x04:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, LOW);
      break;

    case 0x05:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, LOW);
      break;

    case 0x06:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, LOW);
      break;

    case 0x07:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, LOW);
      break;

    case 0x08:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, HIGH);
      break;

    case 0x09:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, HIGH);
      break;

    case 0x0a:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, HIGH);
      break;

    case 0x0b:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, LOW);
      digitalWrite(bit3, HIGH);
      break;

    case 0x0c:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, HIGH);
      break;

    case 0x0d:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, LOW);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, HIGH);
      break;

    case 0x0e:
      digitalWrite(bit0, LOW);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, HIGH);
      break;

    case 0x0f:
      digitalWrite(bit0, HIGH);
      digitalWrite(bit1, HIGH);
      digitalWrite(bit2, HIGH);
      digitalWrite(bit3, HIGH);
      break;

    default:
      Serial.println("INVALID INPUT");
      break;
  }
}

