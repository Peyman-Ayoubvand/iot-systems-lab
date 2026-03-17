#define trigPin 7
#define echoPin 4

#define DECODE_NEC
#include <IRremote.hpp>

#define trigPin 7
#define echoPin 4

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

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

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

  // Detect obstacls
  detectObstacle();
}

void forwards(int speed){
  Serial.println("Moving Foewards");
  int leftSpeed = speed;  
  int rightSpeed = speed - 20;
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

void detectObstacle(){
  float distance = readDistance();
  Serial.print("Destance: ");
  Serial.println(distance);
  if (distance < 10 ){
    stop();
    delay(1000);
    left(200);
    delay(250);
    forwards(globalSpeed);

  }
  delay(100);
}

