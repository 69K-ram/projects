/*
Uses the Arduino Joystick Library to act as a gamepad, capable of being configured as the steering input for Dirt Rally and likely many more games
https://github.com/MHeironimus/ArduinoJoystickLibrary 
*/

#include <Joystick.h> 

Joystick_ Joystick; // the default declaration for the gamepad object

int wheel = A0; //pins for the various inputs
int accel = 7;
int drift = 6;

void setup() {
  pinMode(wheel, INPUT);
  pinMode(accel, INPUT_PULLUP);
  pinMode(drift, INPUT_PULLUP);
  Joystick.setXAxisRange(0,1023);
  Joystick.setYAxisRange(0, 1);
  Joystick.begin();
}

void loop() {
   // you can easily add more inputs in you want. for example, if you wanted to add a brake, you could simply add: " Joystick.setButton( BUTTON_#, digitalRead(BUTTON_PIN) );
   // then configure your game to use that input
   // if you want help, email me @ lonsbury0@gmail.com
   Joystick.setXAxis(analogRead(wheel));
   Joystick.setYAxis(digitalRead(7));
   Joystick.setButton(7,digitalRead(drift));
   Joystick.sendState();
}
