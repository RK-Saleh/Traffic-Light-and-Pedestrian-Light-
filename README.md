# Traffic-Light-and-Pedestrian-Light-

This project simulates a traffic light system with a pedestrian crossing mechanism. The system uses a single Arduino to control the traffic and pedestrian lights, responding to a pedestrian button press.

---

## Overview

The system includes:
- **Traffic Lights**: Green, Yellow, and Red lights to manage vehicle flow.
- **Pedestrian Lights**: Green and Red lights to signal pedestrians when it's safe to cross.
- **Pedestrian Button**: Allows pedestrians to request a crossing.

### System Workflow:
1. Vehicles move freely (green light for vehicles).
2. When the pedestrian button is pressed:
   - Traffic transitions to yellow, then red.
   - Pedestrian lights transition to green, allowing crossing.
   - After crossing, the system resets and traffic resumes.

---

## Hardware Requirements

- 1 Arduino board
- 5 LEDs:
  - 3 for traffic lights (red, yellow, green)
  - 2 for pedestrian lights (red, green)
- 1 push button
- Resistors (220Ω or similar for LEDs)
- Connecting wires
- Breadboard(s)

---

## Circuit Diagram

- **Traffic Lights**:
  - Red LED: Connected to pin 2.
  - Yellow LED: Connected to pin 4.
  - Green LED: Connected to pin 7.
- **Pedestrian Lights**:
  - Red LED: Connected to pin 9.
  - Green LED: Connected to pin 6.
- **Pedestrian Button**: Connected to pin 8 (with pull-down resistor).

---

## Code Explanation

### Enum `TrafficState`
Defines the states of the traffic light system:
- `GREEN`: Vehicles move, pedestrians wait.
- `YELLOW`: Prepares vehicles to stop.
- `RED`: Vehicles stop, but pedestrians wait briefly.
- `PEDESTRIAN_CROSSING`: Pedestrians cross safely.
- `BACK_TO_GREEN`: Prepares to resume vehicle flow.

### Setup
- Configures LEDs and the pedestrian button as inputs/outputs.
- Initializes the system in the `GREEN` state.

### Loop
The system operates as a finite state machine:
1. **GREEN**:
   - Traffic green light ON, pedestrian red light ON.
   - Waits for the pedestrian button press to transition to `YELLOW`.
2. **YELLOW**:
   - Traffic yellow light ON for 2 seconds.
   - Prepares to stop traffic by transitioning to `RED`.
3. **RED**:
   - Traffic red light ON for 1.5 seconds.
   - Pedestrian red light remains ON momentarily before transitioning.
4. **PEDESTRIAN_CROSSING**:
   - Pedestrian green light ON for 5 seconds.
   - Pedestrian can cross safely during this time.
   - Returns control to vehicles by transitioning to `BACK_TO_GREEN`.
5. **BACK_TO_GREEN**:
   - Traffic yellow light ON briefly before turning green.
   - Returns to the `GREEN` state.

---

## Timing

- **Traffic Yellow Light**: 2 seconds.
- **Traffic Red Light (before crossing)**: 1.5 seconds.
- **Pedestrian Crossing**: 5 seconds.
- **Reset to Green (Back to Green)**: 3 seconds total (2 seconds yellow, 1 second green delay).

---

## How to Use

1. Build the circuit as described above.
2. Upload the provided code to the Arduino.
3. Press the pedestrian button to request crossing.
4. Observe the traffic and pedestrian light transitions.

---

## Notes

- A pull-down resistor is recommended for the pedestrian button to ensure stable operation.
- The delays in the code can be adjusted to modify light timings.
- Ensure proper power supply and ground connections.

---

## Future Improvements

- Add sensors for vehicles and pedestrians to automate light changes.
- Include a buzzer to alert pedestrians when it’s safe to cross.
- Expand the system to handle multiple crossings or intersections.

---

## License

This project is open-source and available under the MIT License.
