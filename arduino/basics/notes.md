## Introduction to Arduino

- Arduino is both hardware (a microcontroller board) and software (Arduino IDE).
- It is an open-source ecosystem.
- Open-source means the hardware designs and software code are publicly available and can be modified by anyone.
- The main purpose of Arduino is rapid prototyping.
- Rapid prototyping allows quick testing:
  Write code → Upload to board → Test → Modify quickly.
- It is mainly used for robotics and electronics projects.

## Hardware Basics 

### Power
- Arduino operates on 5V DC.
- 5V and GND pins provide power to external components.
- This is a constant DC voltage (not AC).

### Digital Pins
- Two states only:
  - HIGH (5V)
  - LOW (0V)
- Used for switches, buttons, LEDs (on/off)

### Analog Input
- Reads variable voltage from 0V to 5V
- Uses a 10-bit ADC
- Output range: 0 → 1023
- Used for sensors and potentiometers

### PWM (Pulse Width Modulation)
- Digital pin switches rapidly between 0V and 5V
- Simulates analog output using duty cycle
- Example:
  - 0% → OFF
  - 50% → medium brightness
  - 100% → fully ON

## Arduino IDE

### Sketch structure (execution model)
Arduino programs (sketches) have two main functions:

- `setup()` runs **once** when the board powers up / resets / after upload.
  Use it for initialization (e.g., `pinMode`, `Serial.begin`, WiFi setup).
- `loop()` runs **forever**.
  This is where the device behavior lives (reading sensors, controlling LEDs/motors, etc.).

Key idea:
Arduino is a **reactive system** (behavior over time), not a “run once and exit” program.

### Upload + board memory
After uploading, the Arduino stores the last program in memory.
If you unplug and plug it back in, it will run the same program again.

### Serial Monitor (debugging & communication)
Serial Monitor is a tool to see messages sent from Arduino to the computer (and optionally send messages back).

To use it:
- Start serial in `setup()`:
  - `Serial.begin(9600);`
- Print messages in `loop()`:
  - `Serial.println("Hello");`

Important:
The Serial Monitor baud rate must match the value in `Serial.begin(...)` (e.g., 9600).
TX/RX LEDs indicate sending/receiving data over serial.
