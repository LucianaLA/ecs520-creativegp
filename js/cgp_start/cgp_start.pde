import processing.serial.*;

Serial myPort;
String val;

void setup(){
  background(#FFFFFF);
  size(800,800);
  
  // I know that the first port in the serial list on my mac
  // is Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
}

void draw(){
  if (myPort.available() > 0 ){
    val = myPort.readStringUntil('\n');
      println(val);
      //int valInt = int(val);
      ellipse(400, 400, float(val), float(val));
  }
}
