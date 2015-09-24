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
// Joystick pin mappings
const int joystick_pins[] = {7, 8, 9, 10};
// Joystick key mappings (arro)
const int joystick_keys[] = {KEY_LEFT, KEY_UP, KEY_RIGHT, KEY_DOWN};

const int number_of_buttons = (sizeof(button_pins)/sizeof(int));
int last_states[number_of_buttons];

const int number_of_joystick_pins = (sizeof(joystick_pins)/sizeof(int));
int last_joystick_states[number_of_joystick_pins];
int input_tmp;

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
  for (int i=0; i<number_of_joystick_pins; i++) {
    // Setup joystick pin
    pinMode(joystick_pins[i], INPUT_PULLUP);
    // Initialize last state to avoid trigging on start
    last_joystick_states[i] = HIGH;
  }
  Serial.println("Setup complete!");
}

void loop() {
  for (int i=0; i<number_of_joystick_pins; i++) {
    input_tmp = digitalRead(joystick_pins[i]);
    if (input_tmp != last_joystick_states[i]) {
      digitalWrite(led_pin, last_joystick_states[i]);
      if (input_tmp == HIGH) {
        Serial.print("Joystick ");
        Serial.print(i);
        Serial.println(" released");
        Keyboard.release(joystick_keys[i]);
      }
      else {
        Serial.print("Joystick ");
        Serial.print(i);
        Serial.println(" pressed");
        Keyboard.press(joystick_keys[i]);
      }
      last_joystick_states[i] = input_tmp;
    }
  }
  for (int i=0; i<number_of_buttons; i++) {
    input_tmp = digitalRead(button_pins[i]);
    if (input_tmp != last_states[i]) {
      digitalWrite(led_pin, last_states[i]);
      if (input_tmp == HIGH) {
        Serial.println(" Released!");
      }
      else {
        Serial.print("Button ");
        Serial.print(i);
        Serial.print(" pressed...");
        Keyboard.print(button_keys[i]);
      }
      last_states[i] = input_tmp;
    }
  }
  delay(20);
}
