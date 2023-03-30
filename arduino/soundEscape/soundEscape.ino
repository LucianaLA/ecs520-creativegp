// import libraries for LCD, LED and seril
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <FastLED.h>

// init data pins for LED
#define numLED 8
#define DATA_PIN 9
#define CLOCK_PIN 13

int numAudio = 6;
int intervalPotentiometer = 1023 / numAudio;
//potentiometer pin
int knobPin = A0;
//led variables
int greenery;
int animals;
int bioDiv;

CRGB leds[numLED];

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// set up strings to be used on LCD
  String lsquare = "...library square        ";
  String canal =   "...the canal             ";
  String gsquare = "...geography square      ";
  String underw =  "... inside the canal     ";
  String blackp =  "... black poplar trees   ";
  String bee =     "... the bee hives        ";

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("You're listening to");
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, numLED);

}

void loop() {
  // start lcd writing
  lcd.setCursor(0, 1);
// red potentiometer value
  int val = analogRead(knobPin);

  detectAudio(val);
    if(val>0){
      //send data to processing
      Serial.println(val);
    }
    //print on lcd
    lcd.print(listeningTo(val));
    // Serial.println(listeningTo(val));
}


void detectAudio(int val) {
//change the biodiversity meter based on potentiometer readings
  if (0 < val && val < intervalPotentiometer) {
    //lsquare
    greenery = 3;
    animals = 0;
    bioDiv = greenery + animals;
    showColours(bioDiv);
  } else if (intervalPotentiometer < val && val < (intervalPotentiometer * 2)) {
    //canal
    greenery = 1;
    animals = 3;
    bioDiv = greenery + animals;
    showColours(bioDiv);
  } else if ((intervalPotentiometer * 2) < val && val < (intervalPotentiometer * 3)) {
    //gsquare
    greenery = 2;
    animals = 0;
    bioDiv = greenery + animals;
    showColours(bioDiv);
  }else if ((intervalPotentiometer * 3) < val && val < (intervalPotentiometer * 4)) {
    //underw
    greenery = 2;
    animals = 4;
    bioDiv = greenery + animals;
    showColours(bioDiv);
  }else if ((intervalPotentiometer * 4) < val && val < (intervalPotentiometer * 5)) {
    //blackp
    greenery = 7;
    animals = 1;
    bioDiv = greenery + animals;
    showColours(bioDiv);
  }else if ((intervalPotentiometer * 5) < val && val < (intervalPotentiometer * 6)) {
    //bee
    greenery = 4;
    animals = 3;
    bioDiv = greenery + animals;
    showColours(bioDiv);
  }
}


void showColours(int bioDiv) {
  //light up led according to place
  for (int i = 0; i < numLED; i++) {
    //set all to dim
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }
  for (int i = 0; i < bioDiv; i++) {
    if (i<=2){
      leds[i] = CRGB(255, 10, 10);
    }else if (2<i && i<=4){
      leds[i] = CRGB(255, 255, 10); 
    }else if (4<=i && i<bioDiv){
    leds[i] = CRGB(10, 255, 10);
    }else if (bioDiv<=i){
    leds[i+1,i+2,i+3,i+4,i+5] = CRGB(0, 0, 0);
    }
    FastLED.show();
    }
}

String listeningTo(int val){
int total = 1023;
int divide = total/6;
//print string on lcd based on potentiometer reading
    if (0<=val && val<divide){
      return lsquare;
      } else if (divide<val && val<(divide*2)){
        return canal;
      } else if ((divide*2)<val && val<=(divide*3)){
        return gsquare;
      }else if ((divide*3)<val && val<=(divide*4)){
        return underw;
      }else if ((divide*4)<val && val<=(divide*5)){
        return blackp;
      }else if ((divide*5)<val && val<=(divide*6+90)){
        return bee;
      }
      // else if (768<val && val<1024){
      //   return "place 4";
      // }
}
