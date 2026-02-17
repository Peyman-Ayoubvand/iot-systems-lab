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
Arduino is a **reactive system** (continuous execution over time), not a run-once program like traditional software.

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

---

## Digital Input – Button

Digital pins can only read two states:

HIGH → 5V  
LOW → 0V

Buttons are a common example of digital input.

### Floating State
If the input pin is not connected to either GND or 5V,
its value becomes unstable and randomly changes between HIGH and LOW.

This is called a floating pin.

### Internal Pull-up Resistor

Arduino has built-in pull-up resistors that can be enabled in software:

`pinMode(8, INPUT_PULLUP);`

Important: Logic becomes inverted

Released → HIGH  
Pressed → LOW

---

### Debouncing

Mechanical buttons do not switch cleanly.
When pressed, the signal rapidly toggles between HIGH and LOW for a few milliseconds.

Arduino reads this as multiple presses.

This effect is called **bouncing**.

Solutions:
- Small delay
- Time based filtering using millis()

---

## Analog Input – Potentiometer

Analog pins read a range of voltage values using a 10-bit ADC.

0V → 0  
5V → 1023

A potentiometer is a variable resistor used to generate a changing voltage.

### Wiring
- One side → 5V
- Other side → GND
- Middle pin → A0

### Mapping Values

Analog input range: 0–1023  
PWM output range: 0–255

To convert between ranges:

`map(value, 0,1023, 0,255);`

Concept:

Sensor → ADC → Processing → Output

---

## Hardware Communication

Sometimes HIGH/LOW signals are not enough to communicate complex data.
Microcontrollers use communication protocols.

### Serial (UART)
- Two devices
- Requires baud rate agreement
- Used with Serial Monitor

### SPI
- Fast communication
- Multiple wires
- One master, multiple slaves

### I2C
- Only two wires  
SDA → A4  
SCL → A5

Multiple devices share the same bus using addresses.

---

## I2C LCD

Using the `LiquidCrystal_I2C` library, Arduino can send text to an LCD display.

This allows complex output such as characters and messages,
which cannot be achieved using simple digital signals alone.
