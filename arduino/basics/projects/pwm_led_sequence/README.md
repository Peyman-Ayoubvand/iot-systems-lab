# PWM LED Sequence

## Overview

This project implements a forward and reverse LED sequence using PWM control on multiple Arduino pins.

The LEDs gradually light up one by one, then reverse direction, creating a flowing light effect.

---

## Hardware Components

- Arduino UNO
- 6 LEDs
- 6 × 220Ω resistors
- Breadboard
- Jumper wires

---

## Pins Used

The following PWM-capable pins are used:

- 11
- 10
- 9
- 6
- 5
- 3

---

## Behavior

- Each LED turns fully ON using PWM (value 255)
- Then dims to a lower brightness (value 20)
- The sequence moves forward
- Then reverses direction
- The cycle repeats continuously

---

## Concepts Practiced

- `pinMode()`
- `analogWrite()`
- PWM (0–255 range)
- `delay()`
- Sequential LED control
- Understanding execution flow inside `loop()`

---

## Circuit Images

- [Setup Image 1](./images/Setup1.jpg)
- [Setup Image 2](./images/Setup2.jpg)

---

## Source Code

- [pwm_sequence.ino](./pwm_sequence.ino)

---

## Status

Completed
