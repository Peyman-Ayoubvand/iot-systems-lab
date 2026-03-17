
#define trigPin 7
#define echoPin 4

#define DECODE_NEC
#include <IRremote.hpp>

int globalSpeed = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(11, true);
  //Connected To Motor A
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  //Connected To Motor A 
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  //ULTRASONIC SENSOR
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  //IRPROXIMETRY SENSOR
  pinMode(8,INPUT);
  pinMode(2,INPUT);

  stop();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){
      IrReceiver.resume();
      // IrReceiver.printIRResultShort(&Serial);
      switch (IrReceiver.decodedIRData.command){
        case 0x18:
         forwards(globalSpeed);
         
        break;
        case 0x1c:
          stop();
        break;
        case 0x5A:
          right(globalSpeed);
        break;
         case 0x52:
            backwards(globalSpeed);
         break;
         case 0x8:
           left(globalSpeed);
         break;
         case 0x15:
           globalSpeed = globalSpeed - 15;
           if (globalSpeed < 180)globalSpeed = 180;
           Serial.println(globalSpeed);
         break;
         case 0x9:
          globalSpeed = globalSpeed + 10;
          if (globalSpeed > 255){
          globalSpeed = 255;
          Serial.println(globalSpeed);
          break;
          }
    
         break;
      }
   }

  // read ultrasonic sensor
  float distance;
  readUltrasonicSensor(distance);



  // read IR proximitry sensor
  bool leftSensor, rightSensor;
  readIRProximitySensors(leftSensor, rightSensor);

  if (!leftSensor){
    stop();
    delay(500);
    right(globalSpeed);
    delay(250);
    stop();
    delay(500);
    forwards(globalSpeed);
  }

    if (!rightSensor){
    stop();
    delay(500);
    left(globalSpeed);
    delay(250);
    stop();
    delay(500);
    forwards(globalSpeed);
  }

    if (distance < 15){
    stop();
    delay(1000);
    left(globalSpeed);
    delay(300);
    forwards(globalSpeed);
  }

  delay(1000);
}

void forwards(int speed){
  Serial.println("Moving Foewards");
  int rightSpeed = speed -10;
  int leftSpeed = speed;
  //motor A
  digitalWrite(5,LOW);
  analogWrite(6,rightSpeed);
  //motor b
  analogWrite(9,speed);
  digitalWrite(10,LOW);
}

void backwards(int speed){
  Serial.println("Moving Backwards");
  //motor A
  analogWrite(5,speed);
  digitalWrite(6,LOW);
  //motor b
  digitalWrite(9,LOW);
  analogWrite(10,speed);
}


void left(int speed){
  Serial.println("Turning Left");
  //motor A
  digitalWrite(5,LOW);
  analogWrite(6,speed);
  //motor b
  digitalWrite(9,LOW);
  analogWrite(10,speed);
}

void right(int speed){
  Serial.println("Turning Right");
  //motor A
  analogWrite(5,speed);
  digitalWrite(6,LOW);
  //motor b
  analogWrite(9,speed);
  digitalWrite(10,LOW);
}

void stop(){
  Serial.println("Stoping");
  //motor A
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  //motor b
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

float readDistance(){
  float distance, duration;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = (duration * 0.0343)/2;

  return distance;

}

void readUltrasonicSensor(float &distance){
  distance = readDistance();
  Serial.print("Destance: ");
  Serial.println(distance);
  delay(100);
}


void readIRProximitySensors(bool &leftSensor, bool &rightSensor){
  leftSensor = digitalRead(8);
  rightSensor = digitalRead(2);
      Serial.print("Left sensor reading: ");
  if (leftSensor == false){
    Serial.println("OBSTACLE");
  }else{
    Serial.println("NO OBSTACLE");
  }
  Serial.println(leftSensor);
  Serial.print("Right sensor reading: ");
   if (rightSensor == false){
    Serial.println("OBSTACLE");
  }else{
    Serial.println("NO OBSTACLE");
  }
}



