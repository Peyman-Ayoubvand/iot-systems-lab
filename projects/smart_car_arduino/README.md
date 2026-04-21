# Smart Car (Arduino)

## 📌 Description
An autonomous + remote-controlled smart car built using Arduino.  
The robot can detect obstacles and navigate automatically, or be controlled manually using an IR remote.

---

## 📸 Robot

![Robot](images/robot-front-view.jpg)

---

## 🚀 Features
- IR Remote Control  
- Ultrasonic Distance Detection (HC-SR04)  
- IR Proximity Sensors (Left & Right)  
- Obstacle Avoidance System  
- Adjustable Speed  

---

## 🧰 Components
- Arduino Uno  
- Motor Driver  
- DC Motors  
- IR Receiver + Remote  
- Ultrasonic Sensor (HC-SR04)  
- IR Sensors  

---

## 🔌 Pin Configuration

### Motor Driver
- 5, 6 → Motor A  
- 9, 10 → Motor B  

### IR Receiver
- Pin 11  

### Ultrasonic Sensor
- Trig → 7  
- Echo → 4  

### IR Sensors
- Left → Pin 8  
- Right → Pin 2  

---

## 🎮 Controls (IR Remote)
- 2 → Forward  
- 8 → Backward  
- 4 → Left  
- 6 → Right  
- 5 → Stop  
- +/- → Speed Control  

---

## ⚙️ Behavior
- Obstacle (front) → Stop  
- Obstacle (left) → Turn right  
- Obstacle (right) → Turn left  

---

## 🎥 Demo Videos

### Obstacle Avoidance
https://youtu.be/BQObJWiTIyM

### IR Remote Control
https://youtu.be/699cxRvl1Wk

---

## 💻 Code
See `smart_car.ino` for full implementation.
