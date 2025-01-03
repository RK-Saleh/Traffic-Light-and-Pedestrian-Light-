enum TrafficState { GREEN, YELLOW, RED, PEDESTRIAN_CROSSING, BACK_TO_GREEN };
TrafficState currentState = GREEN;

void setup() {
  pinMode(2, OUTPUT);  // Traffic Red light
  pinMode(4, OUTPUT);  // Traffic Yellow light
  pinMode(7, OUTPUT);  // Traffic Green light
  pinMode(9, OUTPUT);  // Pedestrian Red light
  pinMode(6, OUTPUT);  // Pedestrian Green light
  pinMode(8, INPUT);   // Pedestrian button
}

void loop() {
  switch (currentState) {
    case GREEN:
      digitalWrite(7, HIGH);   // Traffic Green light ON
      digitalWrite(4, LOW);    // Traffic Yellow light OFF
      digitalWrite(2, LOW);    // Traffic Red light OFF
      digitalWrite(9, HIGH);   // Pedestrian Red light ON
      digitalWrite(6, LOW);    // Pedestrian Green light OFF
      if (digitalRead(8) == HIGH) { // Check if pedestrian button is pressed
        currentState = YELLOW;
      }
      break;

    case YELLOW:
      digitalWrite(7, LOW);    // Traffic Green light OFF
      digitalWrite(4, HIGH);   // Traffic Yellow light ON
      delay(2000);             // Yellow light delay for 2 seconds
      currentState = RED;
      break;

    case RED:
      digitalWrite(4, LOW);    // Traffic Yellow light OFF
      digitalWrite(2, HIGH);   // Traffic Red light ON
      digitalWrite(9, HIGH);   // Pedestrian Red light ON (stays on initially)
      delay(1500);             // Red light delay for 1.5 seconds
      currentState = PEDESTRIAN_CROSSING;
      break;

    case PEDESTRIAN_CROSSING:
      digitalWrite(9, LOW);    // Pedestrian Red light OFF
      digitalWrite(6, HIGH);   // Pedestrian Green light ON
      delay(5000);             // Time for pedestrian to cross (5 seconds)
      digitalWrite(6, LOW);    // Pedestrian Green light OFF
      digitalWrite(9, HIGH);   // Pedestrian Red light ON again
      currentState = BACK_TO_GREEN;
      break;

    case BACK_TO_GREEN:
      digitalWrite(2, LOW);    // Traffic Red light OFF
      digitalWrite(4, HIGH);   // Traffic Yellow light ON
      delay(2000);             // Yellow light delay before turning green
      digitalWrite(4, LOW);    // Traffic Yellow light OFF
      digitalWrite(7, HIGH);   // Traffic Green light ON
      delay(1000);             // Additional delay before going back to the normal green state
      currentState = GREEN;
      break;
  }
}
