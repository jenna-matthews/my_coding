//using Arduino Uno
//declaring the necessary variables for the program
#include "LPD8806.h"
#include "SPI.h"

long randNumber; //so color change can be randomized

//number of RGB LEDs in strand, declared first as per manufacturer instructions
int nLEDs = 22;

//output pins for first strand
int dataPin = 11;
int clockPin = 13;

//this section can be repeated for all the strands you want to include.
//output pins for second strand
int dataPin2 = 2;
int clockPin2 = 3;

//identifying the strip of leds--can add an additional line for each additional strand.
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);
LPD8806 strip2 = LPD8806(nLEDs, dataPin2, clockPin2);


void setup() {
  //start the LED strip
  strip.begin();
  strip2.begin();
  //update strip, starts 'off'
  strip.show();
  strip2.show();
  
  //setting up the randomness...
  Serial.begin(9600);
  randomSeed(analogRead(0)); //if this pin is unconnected, random noise will generate a different number every time it runs
}

// function prototypes, do not remove these!
void colorChase(uint32_t c, uint8_t wait);
void colorWipe(uint32_t c, uint8_t wait);
void dither(uint32_t c, uint8_t wait);
void scanner(uint8_t r, uint8_t g, uint8_t b, uint8_t wait);
void wave(uint32_t c, int cycles, uint8_t wait);
void rainbowCycle(uint8_t wait);
uint32_t Wheel(uint16_t WheelPos);


void loop() {
     colorChase(strip.Color( 0, 0, 127), 500); //making string chase Blue
     colorChase(strip2.Color( 0, 127, 127), 500); //making string2 chase Cyan
}

  //being random here
//  randNumber = random(1, 10);
//  if(randNumber < 5) {
  
//    //string should be Blue, string2 should be Cyan (rest colors) 
//    //both strings should be chasing at rest
//   for (int i=0; i < 120; i++) {
//insert the colorChase section here
    //every ~2 minutes, run rainbow wheel equally distributed for ~1 min
//   for (int i=120; i < 180; i++) {
      //run the rainbow wheel here
//      }
//  }
//  else {  //if the random number generated is more than 5, the strings will be orange and yellow instead
//    //randomly change string to orange and string2 to yellow (still chasing)
//  
//  }
//  
  //final request, accept input (0 to 384) to get a color value (displayed, like you can change the colors?)
  

