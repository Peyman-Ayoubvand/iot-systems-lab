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
- The car can be controlled using an IR remote
- Each button triggers a movement:
  - Forward
  - Backward
  - Left
  - Right
  - Stop
- Speed can be increased or decreased using remote buttons
- The car can detect obstacles using an ultrasonic sensor
- If an obstacle is detected, the car reacts automatically
- Supports both:
  - manual control (IR remote)
  - autonomous behavior (obstacle avoidance)

---

## Concepts Practiced

- `digitalWrite()`
- `analogWrite()`
- PWM control
- Function abstraction
- Motor direction logic
- Basic robotics control
- IR remote input
- Signal decoding
- `switch-case` logic
- Global state management
- Input-driven control systems
- Ultrasonic sensing
- Distance measurement using time-of-flight
- `pulseIn()` usage
- Sensor integration
- Autonomous decision making

---

## Source Code

- [car_control.ino](./car_control.ino)

---

## Status

Completed
