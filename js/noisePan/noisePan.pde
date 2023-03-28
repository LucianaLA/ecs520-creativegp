import processing.sound.*;
import processing.serial.*;

Serial myPort;

// citation: https://processing.org/reference/libraries/sound/SoundFile_play_.html
float w=1023;
float h=100;
SoundFile file, file2, file3;
float files = 3;
float div = w/files;
int val;
float amp1 = 0;
float amp2 = 0;
float amp3 = 0;
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

  file.loop();
  file2.loop();
  file3.loop();
  file.amp(0);
  file2.amp(0);
  file3.amp(0);
}

void draw() {
    serialEvent(myPort);   
    if (val!=0){
    background(255);
  
    //file.pan(1); //fully left
    //file.amp(val/(w));
    //file3.pan(1);
    // file3.amp((1/3)+(mouseX/(w/3))); //middle?
    //file2.pan(-1); //fully right
    //file2.amp(1.0-(val/(w)));
    line(val, 0, val, h);
    stroke(255,0,0);//val*random(0.5),val*random(0.5));
    strokeWeight(4);
    amp1 = val/div;
    amp2 = (val-div)/(div);
    amp3 = (val-2*div)/(2*div);


      if (1 < val && val < div){
        line(div, 0, div, sin(PI*amp1)*h);
        stroke(255,0,0);
        //println("sound 1");
        //println(sin(PI*amp1) + " amp1");
        file.amp(sin(PI*amp1));
        //file.loop();
      } else if ((div) < val && val < (2*div)){
        line(div*2, 0, div*2, h*sin(PI*amp2));
        stroke(255,0,0);
        //println("sound 2");
        //println(amp2+" amp2");
         file2.amp(sin(PI*amp2));
         //file2.loop();
      } else if ((2*div) < val && val < w){
        line(w, 0, w, sin(PI*amp3)*h);
        stroke(255,0,0);
        //println("sound 3");
        //println(amp3+" amp3");
        file3.amp(sin(PI*amp3));
        //file3.loop();
      }
    }
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
