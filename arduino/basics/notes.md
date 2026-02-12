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
