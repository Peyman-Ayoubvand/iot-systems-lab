/*
  Project: PWM LED Sequence
  Section: Arduino Basics
  Description: Simple LED sequence using digital output pins.
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(11,255);
  delay(200);
  analogWrite(11,20);
  analogWrite(10,255);
  delay(200);
  analogWrite(10,20);
  analogWrite(9,255);
  delay(200);
  analogWrite(9,20);
  analogWrite(6,255);
  delay(200);
  analogWrite(6,20);
  analogWrite(5,255);
  delay(200);
  analogWrite(5,20);
  analogWrite(3,255);
  delay(200);
  analogWrite(3,20);
  analogWrite(5,255);
  delay(200);
  analogWrite(5,20);
  analogWrite(6,255);
  delay(200);
  analogWrite(6,20);
  analogWrite(9,255);
  delay(200);
  analogWrite(9,20);
  analogWrite(10,255);
  delay(200);
  analogWrite(10,20);
  analogWrite(11,255);
  delay(200);
  analogWrite(11,20);
  }

