/*
Teensy Gamepad
https://github.com/kasperkarlsson/TeensyGamepad
*/

// Internal LED - change to 6 if using Teensy++ 2.0
const int led_pin = 11; 

// Button pin mappings
const int button_pins[] = {2, 3, 4, 5};
// Button key mappings
const char button_keys[] = {'W', 'A', 'S', 'D'};

const int number_of_buttons = (sizeof(button_pins)/sizeof(int));
int button_states[number_of_buttons];
int last_states[number_of_buttons];

void setup() {
  Serial.begin(9600);
  Serial.println("Serial ready");
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
  Serial.println("Setting up pins and initializing");
  for (int i=0; i<number_of_buttons; i++) {
    // Setup button pin
    pinMode(button_pins[i], INPUT_PULLUP);
    // Initialize last state to avoid trigging on start
    last_states[i] = HIGH;
  }
  Serial.println("Setup complete!");
}

void loop() {
  for (int i=0; i<number_of_buttons; i++) {
    button_states[i] = digitalRead(button_pins[i]);
    if (button_states[i] != last_states[i]) {
      digitalWrite(led_pin, last_states[i]);
      Serial.print("Button pressed: ");
      Serial.println(i);
      if (button_states[i] == HIGH) {
        Serial.println(" Released!");
      }
      else {
        Serial.print("Button pressed...");
        Keyboard.print(button_keys[i]);
      }
      last_states[i] = button_states[i];
    }
  }
  delay(20);
}
