# Smart Car UI (Processing)

## Description
A graphical user interface built with Processing to control an Arduino-based smart car.

This interface enables real-time control and monitoring using serial communication between the computer and Arduino.

## Features
- Directional control (Forward, Backward, Left, Right, Stop)
- Mouse-based interaction (clickable UI buttons)
- Visual feedback (button color changes on press)
- Real-time sensor monitoring
- Two-way serial communication

## How it works
- Processing sends commands to Arduino via serial communication
- Arduino executes movement commands (F, B, L, R, S)
- Arduino sends sensor data back to Processing
- UI updates based on sensor values

## Communication Protocol

### Commands sent to Arduino:
- F → Forward  
- B → Backward  
- L → Left  
- R → Right  
- S → Stop  

### Data received from Arduino:
A 3-character string representing sensor states:

- First → Left sensor  
- Second → Right sensor  
- Third → Front sensor  

Example: 101  
(Left = obstacle, Right = clear, Front = obstacle)

## Technologies Used
- Processing (Java-based)
- Arduino Serial Communication

## Code
- smart_car_ui.pde
