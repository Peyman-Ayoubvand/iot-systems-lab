# Smart Car (Arduino)

## Description
An autonomous + remote-controlled smart car built using Arduino.

## Features
- IR Remote Control
- Ultrasonic Distance Detection
- IR Proximity Sensors (Left & Right)
- Obstacle Avoidance System
- Adjustable Speed

## Components
- Arduino Uno
- Motor Driver
- DC Motors
- IR Receiver + Remote
- Ultrasonic Sensor (HC-SR04)
- IR Proximity Sensors

## Pin Configuration

### Motor Driver
- 5, 6 → Motor A
- 9, 10 → Motor B

### IR Receiver
- Pin 11

### Ultrasonic Sensor
- Trig → 7
- Echo → 4

### IR Proximity Sensors
- Left → Pin 8
- Right → Pin 2

## Controls (IR Remote)
- 2 → Forward
- 8 → Backward
- 4 → Left
- 6 → Right
- 5 → Stop
- + / - → Speed Control

## Behavior
- Obstacle (front) → Stop
- Obstacle (left) → Turn right
- Obstacle (right) → Turn left

## Version
v1 (Final)

## Code
See `smart_car_v1.ino` for the full implementation.

