// a modified version of https://forum.arduino.cc/index.php?topic=359928.0 to run on (at least it works on mine) SPFD5408 lcd screens. nobody intentionally buys them, but mine was claimed to be an ili9431.
// btw jason kenny sucks dong, don't vote for him

#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

// Calibrate values
#define TS_MINX 123
#define TS_MINY 127
#define TS_MAXX 937
#define TS_MAXY 945

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define MINPRESSURE 10
#define MAXPRESSURE 1000

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define IsWithin(x, a, b) ((x>=a)&&(x<=b))

#include <avr/pgmspace.h>

const char Mobile_KB[3][13] PROGMEM = {
  {0, 13, 10, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
  {1, 12, 9, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
  {3, 10, 7, 'Z', 'X', 'C', 'V', 'B', 'N', 'M'},
};

const char Mobile_NumKeys[3][13] PROGMEM = {
  {0, 13, 10, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
  {0, 13, 10, '-', '/', ':', ';', '(', ')', '$', '&', '@', '"'},
  {5, 8, 5, '.', '\,', '?', '!', '\''}
};

const char Mobile_SymKeys[3][13] PROGMEM = {
  {0, 13, 10, '[', ']', '{', '}', '#', '%', '^', '*', '+', '='},
  {4, 9, 6, '_', '\\', '|', '~', '<', '>'}, //4
  {5, 8, 5, '.', '\,', '?', '!', '\''}
};

const char textLimit = 25;
char MyBuffer[textLimit];

void MakeKB_Button(const char type[][13])
{
  tft.setTextSize(2);
  tft.setTextColor(0xffff, 0xf000);
  for (int y = 0; y < 3; y++)
  {
    int ShiftRight = 15 * pgm_read_byte(&(type[y][0]));
    for (int x = 3; x < 13; x++)
    {
      if (x >= pgm_read_byte(&(type[y][1]))) break;

      drawButton(15 + (30 * (x - 3)) + ShiftRight, 100 + (30 * y), 20, 25); // this will draw the button on the screen by so many pixels
      tft.setCursor(20 + (30 * (x - 3)) + ShiftRight, 105 + (30 * y));
      tft.print(char(pgm_read_byte(&(type[y][x]))));
    }
  }
  //ShiftKey
  drawButton(15, 160, 35, 25);
  tft.setCursor(27, 168);
  tft.print('^');

  //Special Characters
  drawButton(15, 190, 35, 25);
  tft.setCursor(21, 195);
  tft.print(F("SP"));

  //BackSpace
  drawButton(270, 160, 35, 25);
  tft.setCursor(276, 165);
  tft.print(F("BS"));

  //Return
  drawButton(270, 190, 35, 25);
  tft.setCursor(276, 195);
  tft.print(F("RT"));

  //Spacebar
  drawButton(60, 190, 200, 25);
  tft.setCursor(105, 195);
  tft.print(F("SPACE BAR"));
}

void drawButton(int x, int y, int w, int h)
{
  // grey
  tft.fillRoundRect(x - 3, y + 3, w, h, 3, 0x8888); //Button Shading

  // white
  tft.fillRoundRect(x, y, w, h, 3, 0xffff);// outter button color

  //red
  tft.fillRoundRect(x + 1, y + 1, w - 1 * 2, h - 1 * 2, 3, 0xf800); //inner button color
}

void GetKeyPress(char * textBuffer)
{
  char key = 0;
  static bool shift = false, special = false, back = false, lastSp = false, lastSh = false;
  static char bufIndex = 0;

  waitOneTouch();

  Serial.println("get keypress");
  //ShiftKey
  if (TouchButton(15, 160, 35, 25))
    Serial.println("shift");
  {
    shift = !shift;
    delay(200);
  }

  //Special Characters
  if (TouchButton(15, 190, 35, 25))
  {
    Serial.println("space");
    special = !special;
    delay(200);
  }

  if (special != lastSp || shift != lastSh)
  {
    if (special)
    {
      if (shift)
      {
        tft.fillScreen(BLUE);
        MakeKB_Button(Mobile_SymKeys);
      }
      else
      {
        tft.fillScreen(BLUE);
        MakeKB_Button(Mobile_NumKeys);
      }
    }
    else
    {
      tft.fillScreen(BLUE);
      MakeKB_Button(Mobile_KB);
      tft.setTextColor(0xffff, 0xf800);
    }

    if (special)
      tft.setTextColor(0x0FF0, 0xf800);
    else
      tft.setTextColor(0xFFFF, 0xf800);

    tft.setCursor(21, 195);
    tft.print(F("SP"));

    if (shift)
      tft.setTextColor(0x0FF0, 0xf800);
    else
      tft.setTextColor(0xffff, 0xf800);

    tft.setCursor(27, 168);
    tft.print('^');

    lastSh = shift;

    lastSp = special;
    lastSh = shift;
  }

  for (int y = 0; y < 3; y++)
  {
    Serial.println("other keys");
    int ShiftRight;
    if (special)
    {
      if (shift)
        ShiftRight = 15 * pgm_read_byte(&(Mobile_SymKeys[y][0]));
      else
        ShiftRight = 15 * pgm_read_byte(&(Mobile_NumKeys[y][0]));
    }
    else
      ShiftRight = 15 * pgm_read_byte(&(Mobile_KB[y][0]));

    for (int x = 3; x < 13; x++)
    {
      if (x >=  (special ? (shift ? pgm_read_byte(&(Mobile_SymKeys[y][1])) : pgm_read_byte(&(Mobile_NumKeys[y][1]))) : pgm_read_byte(&(Mobile_KB[y][1])) )) break;

      if (TouchButton(15 + (30 * (x - 3)) + ShiftRight, 100 + (30 * y), 20, 25)) // this will draw the button on the screen by so many pixels
      {
        if (bufIndex < (textLimit - 1))
        {
          delay(200);

          if (special)
          {
            if (shift)
              textBuffer[bufIndex] = pgm_read_byte(&(Mobile_SymKeys[y][x]));
            else
              textBuffer[bufIndex] = pgm_read_byte(&(Mobile_NumKeys[y][x]));
          }
          else
            textBuffer[bufIndex] = (pgm_read_byte(&(Mobile_KB[y][x])) + (shift ? 0 : ('a' - 'A')));

          bufIndex++;
        }
        break;
      }
    }
  }

  //Spacebar
  if (TouchButton(60, 190, 200, 25))
  {
    textBuffer[bufIndex++] = ' ';
    delay(200);
  }

  //BackSpace
  if (TouchButton(270, 160, 35, 25))
  {
    if ((bufIndex) > 0)
      bufIndex--;
    textBuffer[bufIndex] = 0;
    tft.setTextColor(0, BLUE);
    tft.setCursor(15, 80);
    tft.print(F("                          "));
    delay(200);
  }

  //Return
  if (TouchButton(270, 190, 35, 25))
  {
    Serial.println(textBuffer);
    while (bufIndex > 0)
    {
      bufIndex--;
      textBuffer[bufIndex] = 0;
    }

    tft.setTextColor(0, BLUE);
    tft.setCursor(15, 80);
    tft.print(F("                         "));
  }
  //}
  tft.setTextColor(0xffff, 0xf800);
  tft.setCursor(15, 80);
  tft.print(textBuffer);
}


void setup(void)
{
  Serial.begin(115200);
  tft.reset();
  tft.begin(0x9341); // SDFP5408
  tft.fillScreen(BLUE);
  tft.setRotation(1);
  MakeKB_Button(Mobile_KB);
}

void loop()
{
  // See if there's any  touch data for us
  GetKeyPress(MyBuffer);
}


byte TouchButton(int x, int y, int w, int h)
{
  int X, Y;

  // Retrieve a point
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  Y = map(p.x, TS_MINY, TS_MAXY, tft.height(), 0);
  X = map(p.y, TS_MINX, TS_MAXX, 0, tft.width());
  Serial.print(X);
  Serial.print(" ");
  Serial.print(Y);
  Serial.print(" ");
  Serial.print(x);
  Serial.print(" ");
  Serial.println(y);
  return (IsWithin(X, x, x + w) & IsWithin(Y, y, y + h));
}

TSPoint waitOneTouch() {
  // wait 1 touch to exit function
  TSPoint p;
  do {
    p = ts.getPoint();

    pinMode(XM, OUTPUT); //Pins configures again for TFT control
    pinMode(YP, OUTPUT);

  } while ((p.z < MINPRESSURE ) || (p.z > MAXPRESSURE));

  return p;
}
