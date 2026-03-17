# Robot Car Control

## Overview

This project implements basic control of a two-wheel robot car using an Arduino and a motor driver.

The car can move in four directions:
- Forward
- Backward
- Left
- Right

Motor speed is controlled using PWM signals.

---

## Hardware Components

- Arduino UNO
- Motor driver module
- 2 × DC motors
- Robot chassis
- Battery (9V)
- Jumper wires

---

## Pins Used

The following pins are used for motor control:

- 3
- 5
- 6
- 9

---

## Behavior

- Each motor is controlled using two digital pins
- Direction is determined by HIGH/LOW combinations
- Speed is controlled using PWM (`analogWrite`)
- The car performs:
  - Forward movement
  - Backward movement
  - Left turn
  - Right turn
- Each movement is followed by a stop state

---

## Concepts Practiced

- `digitalWrite()`
- `analogWrite()`
- PWM control
- Function abstraction
- Motor direction logic
- Basic robotics control

---

## Source Code

- [car_control.ino](./car_control.ino)

---

## Status

Completed
