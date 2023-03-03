import processing.sound.*;

// citation: https://processing.org/reference/libraries/sound/SoundFile_play_.html
float w=1000;
float h=360;
SoundFile file, file2, file3;
//mouseX= x loc of mouse
// mouseX/w = will decrease as the mouseX gets bigger towards 1 
void setup(){
  size(1000,360);
  background(255);
  
  file= new SoundFile(this, "../../../media/bird.mp3");
  file2= new SoundFile(this, "../../../media/canal.mp3");
  file3= new SoundFile(this, "../../../media/gsquare.mp3");

  file.play();
  file2.play();
  file3.play();
}

void draw(){
  file.pan(1); //fully left
  file.amp(mouseX/(w/3));
  file3.pan(1);
  file3.amp((1/3)+(mouseX/(w/3))); //middle?
  file2.pan(-1); //fully right
  file2.amp(1.0-(mouseX/(w)));
}
