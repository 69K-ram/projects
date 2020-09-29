/*
Uses the Arduino Joystick Library to act as a gamepad, capable of being configured as the steering input for Dirt Rally and likely many more games
https://github.com/MHeironimus/ArduinoJoystickLibrary 
*/

#include <Joystick.h> 

Joystick_ Joystick; // the default declaration for the gamepad object. this makes the computer think it has 32 buttons and two joysticks, but if you only use one button it doesn't matter

// pins for the various inputs
int wheel = A0; // analog pin for the steering potentiometer
int accel = 7;  // digital pin for the throttle button. unfortunately its not an analog throttle, so it's either full throttle or no throttle
int drift = 6;  // same thing as above ^ but this one is for a handbrake

void setup() {
  // set up the inputs. for buttons you can use INPUT_PULLUP and connect one lead of the button to ground
  pinMode(wheel, INPUT);
  pinMode(accel, INPUT_PULLUP);
  pinMode(drift, INPUT_PULLUP);
  Joystick.setXAxisRange(0,1023); // sets the range of the joystick x axis. i set it to the range of analogRead
  Joystick.setYAxisRange(0, 1);   // sets range of joystick y axis. i set to 0-1 becuase that's what my game accelerator reads, and my gas pedal is only on or off
  Joystick.begin(); // begins joystick library. 
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
