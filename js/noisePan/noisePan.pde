import processing.sound.*;
import processing.serial.*;

Serial myPort;

// citation: https://processing.org/reference/libraries/sound/SoundFile_play_.html
float w=1023;
float h=100;
SoundFile file, file2, file3;
int val;
//mouseX= x loc of mouse
// mouseX/w = will decrease as the mouseX gets bigger towards 1 
void setup() {
  size(1023, 100);
  background(255);
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);

  file= new SoundFile(this, "../../media/bird.mp3");
  file2= new SoundFile(this, "../../media/canal.mp3");
  file3= new SoundFile(this, "../../media/gsquare.mp3");

  file.play();
  file2.play();
  //file3.play();
}

void draw() {
    background(255);

    serialEvent(myPort);   
    file.pan(1); //fully left
    file.amp(val/(w));
    //file3.pan(1);
    // file3.amp((1/3)+(mouseX/(w/3))); //middle?
    file2.pan(-1); //fully right
    file2.amp(1.0-(val/(w)));
    line(val, 0, val, h);
    stroke(val*random(0.5),val*random(0.5),val*random(0.5));
    strokeWeight(4);

    println(val);
}

void serialEvent (Serial port) {
  String inStr = port.readStringUntil('\n');
//  println(inStr);
  if (inStr != null) {
    String trimStr = trim(inStr);
    val = int(trimStr);
    //println("str = " + trimStr +  " : int = " + val);
  }
}
