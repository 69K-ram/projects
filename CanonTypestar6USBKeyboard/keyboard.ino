/* @file MultiKey.ino
|| @version 1.0
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is an
|| | example of how you can get multiple key presses from a keypad or
|| | keyboard.
|| #
*/

#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 8; //four rows
const byte COLS = 8; //three columns
char keys[ROWS][COLS] = {
  {'a', 'i', 'q', 'y', '6', ',', 179, '"'}, // 179-tab
  {'b', 'j', 'r', 'z', '7', '.', 216, '%'}, // 216 left
  {'c', 'k', 's', '0', '8', '/', 215, '`'}, // 215-right
  {'d', 'l', 't', '1', '9', '-', 130, 131}, //131-windows // 130-alt
  {'e', 'm', 'u', '2', '=', 32, '#', '$'}, // 32-space
  {'f', 'n', 'v', '3', '{', 176, '-', '_'}, // 176-enter // 201
  {'g', 'o', 'w', '4', ';', 128, ';', ':'}, // 128-leftctrl
  {'h', 'p', 'x', '5', 39, 8, 177, '{'} // 8-backspace /// 39 -' 177-esc
};
byte rowPins[ROWS] = {13,12,11,10,9,8,7,6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {5,4,3,2,A0,A1,A2,A3}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
    //Keyboard.begin();
    Serial.begin(9600);
    pinMode(A5, INPUT);
}

unsigned long shiftPressedTime = millis();
bool shiftPressed = false;
bool lastShift = shiftPressed;

void loop() {   
    if (digitalRead(A5) == HIGH) {
      if (shiftPressedTime - millis() > 50) {
         shiftPressedTime = millis();
         shiftPressed = true;
      }
    } else {
      shiftPressed = false;
    }

    if (shiftPressed != lastShift) {
      switch (shiftPressed) {
        case true:
          Keyboard.press(129);
          break;
        case false:
          Keyboard.release(129);
          break;
      }
    }
    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                  case PRESSED:
                    //Serial.println(kpd.key[i].kchar);
                    if (kpd.key[i].kchar == '{') {
                      if (shiftPressed) {
                        Keyboard.print('}');
                      } else{
                        Keyboard.print('{');
                      }
                    } else if (kpd.key[i].kchar == '`') {
                      Keyboard.press(131); // windows
                      delay(50);
                      Keyboard.release(131);
                      delay(200);
                      Keyboard.print("notepad");
                      delay(50);
                      Keyboard.press(176); // enter
                      delay(50);
                      Keyboard.release(176);
                    }
                    else {
                      Keyboard.press(kpd.key[i].kchar);
                    };
                    break;
                  case HOLD:
                    //
                    break;
                  case RELEASED:
                    Keyboard.release(kpd.key[i].kchar);
                    break;
                  case IDLE:
                    //
                    break;
                }
            }
        }
    }
    lastShift = shiftPressed;
}  // End loop
