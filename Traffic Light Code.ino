// Pin assignments
const int pin1 = 2; // pin1 is Red
const int pin2 = 4; // pin2 is Yellow
const int pin3 = 7; // pin3 is Green

void setup() {
  // Set up all the used pins as OUTPUT
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
}

void loop() {
  // Turn on and off each pin with specific delays
  controlPin(pin1, 3000); // Pin 2 ON for 3 seconds
  controlPin(pin2, 1500); // Pin 4 ON for 1.5 seconds
  controlPin(pin3, 3000); // Pin 7 ON for 3 seconds
  
  // Special case: Turn pin2 ON and pin3 OFF for 1.5 seconds
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  delay(1500);
  digitalWrite(pin2, LOW); // Ensure pin2 turns off after the delay
}

// Helper function to control pins with a delay
void controlPin(int pin, int duration) {
  digitalWrite(pin, HIGH);  // Turn the pin ON
  delay(duration);          // Wait for the specified time
  digitalWrite(pin, LOW);   // Turn the pin OFF
}
