void setup() {
  // put your setup code here, to run once:
  //Connected To Motor A
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  //Connected To Motor A 
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  forwards(255);
  delay(1000);
  stop();
  delay(1000);

  left(200);
  delay(250);
  stop();
  delay(1000);
//--------------------
 forwards(255);
  delay(1000);
  stop();
  delay(1000);

  left(200);
  delay(250);
  stop();
  delay(1000);
//--------------------
 forwards(255);
  delay(1000);
  stop();
  delay(1000);

  left(200);
  delay(250);
  stop();
  delay(1000);
//--------------------
 forwards(255);
  delay(1000);
  stop();
  delay(1000);

  left(200);
  delay(250);
  stop();
  delay(1000);
//--------------------
 
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
