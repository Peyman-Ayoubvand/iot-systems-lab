import processing.serial.*;

Serial myPort;

int buttonWidth = 100;
int buttonHeight = 100;
int padding =20;

color forwardColor = #FFF59D;
color stopColor = #FFF59D;
color backwardColor = #FFF59D;
color leftColor = #FFF59D;
color rightColor = #FFF59D;

char leftSensor = '0';
char rightSensor = '0';
char frontSensor = '0';


void setup(){
  myPort = new Serial(this,"COM7",9600);
  size(640,370);
  
  
}

void draw() {
  background(255);
  drawDirectionPad();
  //println(mouseX, ' ',mouseY);
  receivedUIData();
  
  
}

void receivedUIData(){
  String val = "";
  if (myPort.available() > 0) {
    val = myPort.readStringUntil('\n');
    println(val);
    }
    
   if (val !=null && val.length() == 5){
      leftSensor = val.charAt(0);
      rightSensor = val.charAt(1);
      frontSensor = val.charAt(2);
    
    println("Left Sensor: " , leftSensor);
    println("Right Sensor: " , rightSensor);
    println("Front Sensor: " , frontSensor);
    
   }
    
   
}

void drawDirectionPad(){

  
  //forward
  fill(forwardColor);
  rect (padding + buttonWidth ,padding ,buttonWidth ,buttonHeight);
  fill(0);
  textAlign(CENTER,CENTER);
  text("FORWARDS", padding + buttonHeight+ buttonWidth/2 , padding + buttonHeight/2);
  
  // Drow front Sensor data
  fill(0);
  textAlign(CENTER,CENTER);
  text("Front Sensor: "+ frontSensor, padding + buttonWidth + buttonWidth/2 , padding * 2 + buttonHeight *3 );
  
  
  //stop
  fill(stopColor);
  rect (padding + buttonWidth ,padding + buttonHeight ,buttonWidth ,buttonHeight);
  fill(0);
  textAlign(CENTER,CENTER);
  text("STOP", padding + buttonHeight+ buttonWidth/2 , padding + buttonHeight + buttonHeight/2);
  
  
  //left
  fill(leftColor);
  rect (padding ,padding + buttonHeight,buttonWidth ,buttonHeight);
  fill(0);
  textAlign(CENTER,CENTER);
  text("LEFT", padding + buttonWidth/2 , padding + buttonHeight + buttonHeight/2);
  
  // Drow left Sensor  data
  fill(0);
  textAlign(CENTER,CENTER);
  text("Left Sensor: "+ leftSensor, padding + buttonWidth/2 , padding * 2 + buttonHeight *3 );
  
  
  //right
  fill(rightColor);
  rect (padding + (buttonWidth * 2),padding + buttonHeight,buttonWidth ,buttonHeight);
  fill(0);
  textAlign(CENTER,CENTER);
  text("RIGHT", padding + (buttonHeight * 2)+ buttonWidth/2 , padding + buttonHeight + buttonHeight/2);
  
  // Drow Right Sensor data
  fill(0);
  textAlign(CENTER,CENTER);
  text("Right Sensor: "+ rightSensor, padding + buttonWidth*2 + buttonWidth/2 , padding * 2 + buttonHeight *3 );
  
  
  //backward
  fill(backwardColor);
  rect (padding + buttonWidth  ,padding + (buttonHeight * 2),buttonWidth ,buttonHeight);
  fill(0);
  textAlign(CENTER,CENTER);
  text("BACKWARD", padding + buttonHeight+ buttonWidth/2 , padding + (buttonHeight * 2) + buttonHeight/2);
  
  
}

void mousePressed(){
  //println("MOUSE PRESSED, MOUSE COORDINATES: " ,mouseX , ' ', mouseY);
  if(mouseX > padding && mouseX < padding + (buttonWidth * 3) && mouseY > padding && mouseY < padding +(buttonHeight * 3)){
    if(mouseX > padding + buttonWidth && mouseX < padding + (buttonWidth * 2) && mouseY > padding && mouseY < padding +buttonHeight){
      forwardColor = #B2DFDB;
     println("FORWARD");
     myPort.write("F\n");
    }
    else if(mouseX > padding + buttonWidth && mouseX < padding + (buttonWidth * 2) && mouseY > padding +buttonHeight && mouseY < padding +(buttonHeight * 2)){
      stopColor = #B2DFDB;
     println("STOP");
     myPort.write("S\n");
    }
    else if(mouseX > padding && mouseX < padding + buttonWidth  && mouseY > padding +buttonHeight && mouseY < padding +(buttonHeight * 2)){
      leftColor = #B2DFDB;
     println("LEFT");
     myPort.write("L\n");
    }
    else if(mouseX > padding + buttonWidth && mouseX < padding + (buttonWidth * 2) && mouseY > padding +(buttonHeight *2) && mouseY < padding +(buttonHeight * 3)){
      backwardColor = #B2DFDB;
     println("BACKWARD"); 
     myPort.write("B\n");
    }
    else if(mouseX > padding + (buttonWidth * 2) && mouseX < padding + (buttonWidth * 3)   && mouseY > padding + buttonHeight && mouseY < padding +(buttonHeight * 2)){
      rightColor = #B2DFDB;
     println("RIGHT");
     myPort.write("R\n");
    }
    
  }
}


void mouseReleased(){
forwardColor = #FFF59D;
stopColor = #FFF59D;
backwardColor = #FFF59D;
leftColor = #FFF59D;
rightColor = #FFF59D;
}
