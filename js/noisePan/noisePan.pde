import processing.sound.*;
import processing.serial.*;

Serial myPort;

// citation: https://processing.org/reference/libraries/sound/SoundFile_play_.html
float w=1023;
float h=100;
// initiate sound files
SoundFile file, file2, file3, file4, file5, file6;
// control variables for amp
float files = 6;
float div = w/files;
int val;
// initiate amplitude variables
float amp1,amp2,amp3,amp4,amp5,amp6;

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
  file4= new SoundFile(this, "../../media/underwater.mp3");
  file5= new SoundFile(this, "../../media/blackpoplar.mp3");
  file6= new SoundFile(this, "../../media/bee.mp3");
// play audios on loop and set volumes to start at 0
  file.loop();
  file2.loop();
  file3.loop();
  file4.loop();
  file5.loop();
  file6.loop();

  file.amp(0);
  file2.amp(0);
  file3.amp(0);
  file4.amp(0);
  file5.amp(0);
  file6.amp(0);

}

void draw() {
  // check that we received something
    serialEvent(myPort);   
    // if the value is not null play audio
    if (val!=0){
      // clean background 
    background(255);
  // line on potentiometer value reading to make life easy
    line(val, 0, val, h);
    stroke(255,0,0);
    strokeWeight(4);
    // make amplitudes change with value
    amp1 = val/div;
    amp2 = (val-div)/(div);
    amp3 = (val-2*div)/(2*div);
    amp4 = (val-3*div)/(3*div);
    amp5 = (val-4*div)/(4*div);
    amp6 = (val-5*div)/(5*div);

// play sounds based on potentiometer readings
      if (1 < val && val < div){
        line(div, 0, div, sin(PI*amp1)*h);
        stroke(255,0,0);
        // making amplitude rise and fall by multiplying it by sin(PI)
        file.amp(sin(PI*amp1));
      } else if ((div) < val && val < (2*div)){
        line(div*2, 0, div*2, h*sin(PI*amp2));
        stroke(255,0,0);
         file2.amp(sin(PI*amp2));
      } else if ((2*div) < val && val < (3*div)){
        line(w, 0, w, sin(PI*amp3)*h);
        stroke(255,0,0);
        file3.amp(sin(PI*amp3));
      } else if ((3*div) < val && val < (4*div)){
        line(w, 0, w, sin(PI*amp4)*h);
        stroke(255,0,0);
        file4.amp(sin(PI*amp4));
      } else if ((4*div) < val && val < (5*div)){
        line(w, 0, w, sin(PI*amp5)*h);
        stroke(255,0,0);
        file5.amp(sin(PI*amp5));
      } else if ((5*div) < val && val < (6*div)){
        line(w, 0, w, sin(PI*amp6)*h);
        stroke(255,0,0);
        file6.amp(sin(PI*amp6));
      }
    }
    println(val);
}
// trimming values from serial port to make sure we get the correct readings
void serialEvent (Serial port) {
  String inStr = port.readStringUntil('\n');
  if (inStr != null) {
    String trimStr = trim(inStr);
    val = int(trimStr);
  }
}
