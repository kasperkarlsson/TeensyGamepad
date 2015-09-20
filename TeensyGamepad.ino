/*
Teensy Gamepad
https://github.com/kasperkarlsson/TeensyGamepad
*/

const int LED_PIN = 11;
boolean led_state = HIGH;
boolean enabled = false;
boolean key_enabled = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (key_enabled) {
    Keyboard.println("wasd");
  }
  enabled = !enabled;
  if (enabled)
  
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
    
  delay(5000);

}
