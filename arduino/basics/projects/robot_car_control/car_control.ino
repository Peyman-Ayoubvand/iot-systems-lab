#define DECODE_NEC
#include <IRremote.hpp>

int globalSpeed = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(11, true);
  //Connected To Motor A
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  //Connected To Motor A 
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);

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
          globalspeed = globalspeed + 10;
          if (globalspeed > 255){
          globalspeed = 255;
          Serial.println(globalSpeed);
          break;
          }
    
         break;
      }
   }
}

void forwards(int speed){
  Serial.println("Moving Foewards");
  //motor A
  digitalWrite(3,LOW);
  analogWrite(5,speed);
  //motor b
  digitalWrite(6,LOW);
  analogWrite(9,speed);
}

void backwards(int speed){
  Serial.println("Moving Backwards");
  //motor A
  analogWrite(3,speed);
  digitalWrite(5,LOW);
  //motor b
  analogWrite(6,speed);
  digitalWrite(9,LOW);

}


void left(int speed){
  Serial.println("Turning Left");
  //motor A
  digitalWrite(3,LOW);
  analogWrite(5,speed);
  //motor b
  analogWrite(6,speed);
  digitalWrite(9,LOW);

}

void right(int speed){
  Serial.println("Turning Right");
  //motor A
  analogWrite(3,speed);
  digitalWrite(5,LOW);
  //motor b
  digitalWrite(6,LOW);
  analogWrite(9,speed);

}

void stop(){
  Serial.println("Stoping");
  //motor A
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  //motor b
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
}

