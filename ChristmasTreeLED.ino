#include <FastLED.h>

#define NUM_LEDS 2
#define DATA_PIN 9
#define BUTTON_PIN A5

// define the array of leds
CRGB leds[NUM_LEDS];

// define button variable
bool button = false;

int selectedPattern = 0;

void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  pinMode(DATA_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() { 
  buttonState();

  switch (selectedPattern){
    case 0:
      patternOne();
      break;
    case 1:
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      FastLED.show();
    default:
      patternOne();
  }
}

bool buttonState(){
  button = digitalRead(BUTTON_PIN);
  selectedPattern ++;
  if (selectedPattern > 1){
    selectedPattern = 0;
  }
  return button;
}

void patternOne(){
    // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Green;
  leds[1] = CRGB::Red;
  FastLED.show();
  delay(500);
}
