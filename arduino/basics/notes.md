# Arduino Basics Notes

---

## Introduction to Arduino

- Arduino is both **hardware** (a microcontroller board) and **software** (Arduino IDE).
- It is an **open-source ecosystem**.
- Open-source means hardware designs and software code are publicly available and modifiable by anyone.
- The main purpose of Arduino is **rapid prototyping**.
- Rapid prototyping workflow:
  Write code → Upload → Test → Modify → Repeat
- Commonly used in:
  - robotics
  - embedded systems
  - electronics projects
  - automation

---

## Hardware Basics

### Power

- Arduino operates at **5V DC**
- `5V` and `GND` pins provide power to external components
- This is constant DC voltage (not AC)
- All components in a circuit must share **common GND**

---

### Digital Pins

Digital pins have two states only:

- HIGH → 5V
- LOW → 0V

Used for:
- switches
- buttons
- LEDs (on/off)
- relays

Important:
Digital signals are binary (no in-between values).

---

### Analog Input (ADC)

- Reads variable voltage from 0V to 5V
- Uses a **10-bit ADC**
- Output range:
  - 0V → 0
  - 5V → 1023
- Used for:
  - sensors
  - potentiometers
  - variable signals

Resolution formula:
1024 steps (2^10)

---

### PWM (Pulse Width Modulation)

- Simulates analog output using fast HIGH/LOW switching
- Controlled using `analogWrite(pin, value)`
- Value range: 0–255 (8-bit resolution)

Examples:
- 0 → OFF
- 127 → medium brightness
- 255 → fully ON

Used for:
- LED brightness control
- motor speed control

Note:
PWM is not true analog voltage — it is a time-based digital signal.

---

## Arduino IDE

### Sketch Structure (Execution Model)

Every Arduino program (sketch) contains two main functions:

- `setup()`
  - Runs **once**
  - Used for initialization
  - Example:
    - `pinMode()`
    - `Serial.begin()`
    - hardware setup

- `loop()`
  - Runs **forever**
  - Contains device behavior
  - Reads sensors
  - Controls actuators

Key Idea:
Arduino is a **reactive system** (continuous execution over time),
not a run-once program like traditional software.

---

### Upload & Board Memory

- After uploading, the program is stored in flash memory.
- If you unplug and reconnect power, the same program runs again.
- Reset button restarts execution from `setup()`.

---

### Serial Monitor (Debugging & Communication)

Serial Monitor allows communication between Arduino and the computer.

Used for:
- Debugging
- Logging sensor values
- Sending simple commands

How to use:

Start serial communication in `setup()`:

`Serial.begin(9600);`

Send data in `loop()`:

`Serial.println("Hello");`

Important:
The baud rate in Serial Monitor must match the value used in `Serial.begin(...)`.

Indicators:
- TX LED → sending data
- RX LED → receiving data

---

## Practical Notes

- Every LED must use a current-limiting resistor (e.g., 220Ω)
- Circuits must share a common ground
- `delay(ms)` blocks execution during waiting time
- Use PWM pins (marked with ~) for brightness control

---

## Current Level

Basic understanding of:
- Digital IO
- Analog Input
- PWM
- Execution model
- Serial debugging
