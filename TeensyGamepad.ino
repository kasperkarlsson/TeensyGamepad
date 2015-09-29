/*
Teensy Gamepad
https://github.com/kasperkarlsson/TeensyGamepad
*/

// Button pin mappings
const int button_pins[] = {2, 3, 4, 5};
// Button key mappings
const char button_keys[] = {'W', 'A', 'S', 'D'};
// Joystick pin mappings
const int joystick_pins[] = {7, 8, 9, 10};
// Joystick key mappings (arro)
const int joystick_keys[] = {KEY_LEFT, KEY_UP, KEY_RIGHT, KEY_DOWN};

const int number_of_buttons = (sizeof(button_pins) / sizeof(int));
int last_states[number_of_buttons];

const int number_of_joystick_pins = (sizeof(joystick_pins) / sizeof(int));
int last_joystick_states[number_of_joystick_pins];
int input_tmp;

void printButtonStatus(boolean is_button, int index, boolean pressed) {
  if (is_button) {
    Serial.print("Button ");
  }
  else {
    Serial.print("Joystick ");
  }
  Serial.print(index);
  if (pressed) {
    Serial.println(" pressed");
  }
  else {
    Serial.println(" released");
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Serial ready");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
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
  // Handle joystick functionality
  for (int i=0; i<number_of_joystick_pins; i++) {
    input_tmp = digitalRead(joystick_pins[i]);
    if (input_tmp != last_joystick_states[i]) {
      digitalWrite(LED_BUILTIN, last_joystick_states[i]);
      boolean is_low = input_tmp == LOW;
      printButtonStatus(false, i, is_low);
      if (is_low) {
        // Press key and keep it down
        Keyboard.press(joystick_keys[i]);
      }
      else {
        // Release key
        Keyboard.release(joystick_keys[i]);
      }
      last_joystick_states[i] = input_tmp;
    }
  }
  // Handle button functionality
  for (int i=0; i<number_of_buttons; i++) {
    input_tmp = digitalRead(button_pins[i]);
    if (input_tmp != last_states[i]) {
      digitalWrite(LED_BUILTIN, last_states[i]);
      boolean is_low = input_tmp == LOW;
      printButtonStatus(true, i, is_low);
      if (is_low) {
        // Single press for buttons
        Keyboard.print(button_keys[i]);
      }
      last_states[i] = input_tmp;
    }
  }
  delay(20);
}
