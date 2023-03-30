// import libraries for LCD, LED and seril
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <FastLED.h>

// init data pins for LED
#define numLED 19
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
String canal = "...the canal             ";
String gsquare = "...geography square      ";
String underw = "... inside the canal     ";
String blackp = "... black poplars        ";
String bee = "... the bee hives        ";

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("You're listening to");
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, numLED);
}

void loop() {
  // for (int i = 0; i < numLED; i++) {
  //   //set all to dim
  //   leds[i] = CRGB(0, 0, 0);
  //   FastLED.show();
  // }
  // start lcd writing
  lcd.setCursor(0, 1);
  // red potentiometer value
  int val = analogRead(knobPin);

  detectAudio(val);
  if (val > 0) {
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
    showColours(7);
  } else if (intervalPotentiometer < val && val < (intervalPotentiometer * 2)) {
    //canal
    showColours(5);
  } else if ((intervalPotentiometer * 2) < val && val < (intervalPotentiometer * 3)) {
    //gsquare
    showColours(10);
  } else if ((intervalPotentiometer * 3) < val && val < (intervalPotentiometer * 4)) {
    //underw
    showColours(3);
  } else if ((intervalPotentiometer * 4) < val && val < (intervalPotentiometer * 5)) {
    //blackp
    showColours(4);
  } else if ((intervalPotentiometer * 5) < val && val < (intervalPotentiometer * 6 + 90)) {
    //bee
    showColours(8);
  }
}


void showColours(int bioDiv) {
  //light up led according to place
  if (bioDiv <= 3) {
    //red - led 14 & 15
    leds[13] = CRGB(255, 10, 10);
    leds[14] = CRGB(255, 10, 10);
    leds[15] = CRGB(255, 10, 10);

    //yellow - led 16 - 17 - 18
    leds[16] = CRGB(0, 0, 0);
    leds[17] = CRGB(0, 0, 0);
    leds[18] = CRGB(0, 0, 0);
    // green - led 1-13
    leds[0] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);

    Serial.println("biodiv less than 2");
    FastLED.show();
  } else if (4 <= bioDiv && bioDiv <= 6) {
    leds[13] = CRGB(255, 10, 10);
    leds[14] = CRGB(255, 10, 10);
    leds[15] = CRGB(255, 10, 10);
    //yellow - led 16 - 17 - 18
    leds[16] = CRGB(255, 255, 10);
    leds[17] = CRGB(255, 255, 10);
    leds[18] = CRGB(255, 255, 10);

    leds[0] = CRGB(0, 0, 0);
    leds[1] = CRGB(0, 0, 0);
    leds[2] = CRGB(0, 0, 0);
    leds[3] = CRGB(0, 0, 0);
    leds[4] = CRGB(0, 0, 0);
    leds[5] = CRGB(0, 0, 0);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);

    Serial.println("biodiv less than 5");
    FastLED.show();
  } else if (7 <= bioDiv && bioDiv <= 10) {
    //red
    leds[13] = CRGB(255, 10, 10);
    leds[14] = CRGB(255, 10, 10);
    leds[15] = CRGB(255, 10, 10);
    //yellow - led 16 - 17 - 18
    leds[16] = CRGB(255, 255, 10);
    leds[17] = CRGB(255, 255, 10);
    leds[18] = CRGB(255, 255, 10);
    // green - led 1-4
    leds[0] = CRGB(0, 0, 0);
    leds[1] = CRGB(10, 255, 10);
    leds[2] = CRGB(10, 255, 10);
    leds[3] = CRGB(10, 255, 10);
    leds[4] = CRGB(10, 255, 10);
    leds[5] = CRGB(10, 255, 10);
    leds[6] = CRGB(0, 0, 0);
    leds[7] = CRGB(0, 0, 0);
    leds[8] = CRGB(0, 0, 0);
    leds[9] = CRGB(0, 0, 0);
    leds[10] = CRGB(0, 0, 0);
    leds[11] = CRGB(0, 0, 0);
    leds[12] = CRGB(0, 0, 0);
    Serial.println("biodiv good");
    FastLED.show();
  }

  FastLED.show();
}

String listeningTo(int val) {
  int total = 1023;
  int divide = total / 6;
  //print string on lcd based on potentiometer reading
  if (0 <= val && val < divide) {
    return lsquare;
  } else if (divide < val && val < (divide * 2)) {
    return canal;
  } else if ((divide * 2) < val && val <= (divide * 3)) {
    return gsquare;
  } else if ((divide * 3) < val && val <= (divide * 4)) {
    return underw;
  } else if ((divide * 4) < val && val <= (divide * 5)) {
    return blackp;
  } else if ((divide * 5) < val && val <= (divide * 6 + 90)) {
    return bee;
  }
  // else if (768<val && val<1024){
  //   return "place 4";
  // }
}