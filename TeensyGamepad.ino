/*
Teensy Gamepad
https://github.com/kasperkarlsson/TeensyGamepad
*/

const int LED_PIN = 11;
const int BUTTON_PIN = 2;

int button_state, last_state = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("Serial ready");
}

void loop() {
  button_state = digitalRead(BUTTON_PIN);
  if (button_state != last_state) {
    digitalWrite(LED_PIN, last_state);
    Serial.println(button_state);
    if (button_state == HIGH) {
      Serial.println("Button pressed");
    }
    else {
      Serial.println("Button released");
    }
    last_state = button_state;
  }
  delay(50);
}
