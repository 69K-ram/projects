//libraries
#include <LowPower.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//display setup
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'Shrek', 43x64px
const unsigned char shrek [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xfd, 0xff,
  0xff, 0xe0, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xe0, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xe0, 0xff, 0xf7,
  0x0f, 0xff, 0xff, 0xe0, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xe0, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xe0,
  0xff, 0x60, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xc0, 0x93, 0xff, 0xff, 0xe0, 0xff, 0xe0, 0x3b, 0xff,
  0xff, 0xe0, 0xff, 0xe0, 0x77, 0xff, 0xff, 0xe0, 0xff, 0xf0, 0x6f, 0xdf, 0xff, 0xe0, 0xff, 0xf0,
  0x0f, 0xe1, 0xff, 0xe0, 0xff, 0xf0, 0x13, 0xe1, 0xff, 0xe0, 0xff, 0x80, 0x07, 0xc1, 0xff, 0xe0,
  0xff, 0x00, 0x06, 0xc1, 0xff, 0xe0, 0xff, 0x00, 0x04, 0x81, 0xff, 0xe0, 0xff, 0x00, 0x01, 0x01,
  0xff, 0xe0, 0xfe, 0x00, 0x02, 0x00, 0xff, 0xe0, 0xfe, 0x00, 0x08, 0x00, 0x3f, 0xe0, 0xf8, 0x00,
  0xf0, 0x00, 0x1f, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0xf0, 0x00, 0x10, 0x00, 0x07, 0xe0,
  0xf0, 0x00, 0xb0, 0x00, 0xc7, 0xe0, 0xe0, 0x01, 0xf8, 0x00, 0xcf, 0xe0, 0xe0, 0x01, 0xff, 0xf0,
  0xcf, 0xe0, 0xc0, 0x03, 0xff, 0xff, 0xcf, 0xe0, 0xc0, 0xc7, 0xff, 0xff, 0xcf, 0xe0, 0xc0, 0x4f,
  0xff, 0xff, 0x9f, 0xe0, 0xe0, 0x1f, 0xff, 0xff, 0x9f, 0xe0, 0xe0, 0x0f, 0xff, 0xff, 0x9f, 0xe0,
  0xe0, 0x07, 0xff, 0xff, 0x8f, 0xe0, 0xf0, 0x03, 0xff, 0xff, 0x03, 0xe0, 0xf8, 0x01, 0xff, 0xfe,
  0x01, 0xe0, 0xf8, 0x01, 0xff, 0xfc, 0x01, 0xe0, 0xfc, 0x00, 0xff, 0xf1, 0x01, 0xe0, 0xfe, 0x00,
  0x3f, 0x83, 0x83, 0xe0, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xe0,
  0xff, 0xc0, 0x01, 0xff, 0xff, 0xe0, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xe0, 0xff, 0x80, 0xff, 0xff,
  0xff, 0xe0, 0xff, 0xc8, 0x0b, 0xff, 0xff, 0xe0, 0xff, 0xc4, 0x03, 0xe1, 0xff, 0xe0, 0xff, 0xc0,
  0x03, 0x01, 0xff, 0xe0, 0xff, 0xc1, 0xff, 0x03, 0xff, 0xe0, 0xff, 0xc1, 0xff, 0x03, 0xff, 0xe0,
  0xff, 0xc0, 0xff, 0x03, 0xff, 0xe0, 0xff, 0xc0, 0xff, 0x03, 0xff, 0xe0, 0xff, 0xc0, 0xff, 0x01,
  0xff, 0xe0, 0xff, 0xe0, 0xff, 0x03, 0xff, 0xe0, 0xff, 0xe1, 0xff, 0x83, 0xff, 0xe0, 0xff, 0xe1,
  0xff, 0x83, 0xff, 0xe0, 0xff, 0xe1, 0xff, 0xc3, 0xff, 0xe0, 0xff, 0xc1, 0xff, 0xc1, 0xff, 0xe0,
  0xff, 0xc1, 0xff, 0x81, 0xff, 0xe0, 0xff, 0x81, 0xff, 0xc1, 0xff, 0xe0, 0xff, 0x00, 0xff, 0xc1,
  0xff, 0xe0, 0xfc, 0x00, 0xff, 0xc0, 0xff, 0xe0, 0xfc, 0x07, 0xff, 0xc0, 0xff, 0xe0, 0xff, 0xff,
  0xff, 0xc0, 0x7f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0
};

char* schedule[] = {"SCI", "FSL", "MAT", "ELA", "ART", "SOC", //mon
                    "MAT", "ART", "SCI", "ELA", "GYM", "CON", //tues
                    "SCI", "FSL", "ELA", "MAT", "CON", "SOC", //wed
                    "MAT", "GYM", "ART", "SCI", "SOC", "ELA", //thu
                    "GYM", "SOC", "CON", "ELA", "FSL", "MAT"  //fri
                   };
//variables
unsigned long start_millis; // to keep track of time while not sleeping
int oldminutes = 1; //to see if time needs to be udated
int oldhours;
String oled_time;   //string to convert integers to char
int loops = 0;

int time_hour;
int time_minute;
unsigned long time_hour_modifier = 0;
unsigned long time_minute_modifier = 0;
unsigned long time_a;

bool display_updated = false;
int menu = 0; //0=time, 1=schedule
int old_menu;
int time_selected = 0;
bool setting_time = 0;

bool a;
unsigned long a_end_last_pressed = 0;
unsigned long a_press_start = 0;
bool a_just_released = 0;
bool b;
unsigned long b_end_last_pressed = 0;
unsigned long b_press_start = 0;
bool b_just_released = 0;

void setup() {
  // put your setup code here, to run once:
  shrek_exe();
  delay(2000);
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(64); //where c is a value from 0 to 255 (sets contrast e.g. brightness)
  Serial.begin(9600);//initialization
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);

  display.clearDisplay();
  display.display();
  start_millis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  noInterrupts();
  LowPower.idle(SLEEP_120MS, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_ON, SPI_OFF, USART0_ON, TWI_ON);
  interrupts();

  //update time and check the buttons////////////////////////////////////////////////////
  update_time();
  menu_buttons();

  //print to display/////////////////////////////////////////////////////////////////////
  switch (menu) {
    case 0:
      menu_zero();
      break;
    case 1:
      menu_one();
      break;
    case 2:
      menu_two();
      break;
    case 4:
      menu_three();
      break;
    default:
      break;
  }
  if (display_updated == true) { //update display only when needed to save power
    display.display();
    display_updated = false;
  }
  //update control variables
  oldminutes = time_minute;
  oldhours = time_hour;
  old_menu = menu;
  loops++;
  if (loops > 15) {
    loops = 0;
  }
}

//functions//////////////////////////////////////////////////////////////////////////////
void menu_zero() {
  if (old_menu == 2) {
    display.ssd1306_command(SSD1306_DISPLAYON); // To switch display off
  }
  if (oldminutes != time_minute || old_menu != menu) {
    display_updated = true;

    display.setCursor(26, 20);
    display.setTextSize(3);
    display.setTextColor(1);
    display.clearDisplay();
    oled_time = "";
    if (time_hour < 10) {
      oled_time += 0;
    }
    oled_time += time_hour;
    oled_time += ":";
    if (time_minute < 10) {
      oled_time += 0;
    }
    oled_time += time_minute;
    display.print((char*) oled_time.c_str());
  }
}
void menu_one() {
  if (old_menu == 2) {
    display.ssd1306_command(SSD1306_DISPLAYON); // To switch display off
  }
  if (old_menu != menu) {
    display.clearDisplay();
    display.drawFastHLine(0, 0, 128, 1);
    display.drawFastHLine(0, 13, 128, 1);
    display.drawFastHLine(0, 23, 128, 1);
    display.drawFastHLine(0, 33, 128, 1);
    display.drawFastHLine(0, 43, 128, 1);
    display.drawFastHLine(0, 53, 128, 1);
    display.drawFastHLine(0, 63, 128, 1);
    display.drawFastVLine(0, 0, 64, 1);
    display.drawFastVLine(28, 0, 64, 1);
    display.drawFastVLine(53, 0, 64, 1);
    display.drawFastVLine(78, 0, 64, 1);
    display.drawFastVLine(103, 0, 64, 1);
    display.drawFastVLine(127, 0, 64, 1);
    display.setTextSize(1);
    display.setTextColor(1);
    draw_schedule(5, 0); //monday
    draw_schedule(30, 6); //tuesday
    draw_schedule(56, 12); //wednesday
    draw_schedule(81, 18); //thursday
    draw_schedule(106, 24); //friday
    display_updated = true;
  }
}
void menu_two() {
  if (menu != old_menu) {
    display.ssd1306_command(SSD1306_DISPLAYOFF); // To switch display off, for power savings
  }
}
void menu_three() {
  if (old_menu == 2) {

    display.ssd1306_command(SSD1306_DISPLAYON);
  }
  setting_time = true;
  time_selected = 0;
  while (setting_time == true) {
    check_buttons();
    update_time();

    switch (time_selected) {
      case 0:
        if (a_just_released == true) {
          time_hour_modifier ++;
          a_just_released = false;
        }
        break;

      case 1:
        if (a_just_released == true) {
          time_minute_modifier += 5;
          a_just_released = false;
        }
        break;

      case 2:
        if (a_just_released == true) {
          time_minute_modifier ++;
          a_just_released = false;
        }
        break;

      default:
        break;
    }

    if (b_just_released == true) {
      time_selected ++;
      b_just_released = false;

      if (time_selected == 3) {
        b_just_released = false;
        setting_time = false;
        menu = 0;
      }
    }
    if (oldminutes != time_minute || oldhours != time_hour || old_menu != menu) {
      display.setCursor(0, 0);
      display.setTextSize(1);
      display.setTextColor(1);
      display.clearDisplay();
      display.print("Set time:\nA=confirm, B=adjust");

      display.setCursor(26, 20);
      display.setTextSize(3);
      display.setTextColor(1, 0);
      oled_time = "";
      if (time_hour < 10) {
        oled_time += 0;
      }
      oled_time += time_hour;
      oled_time += ":";
      if (time_minute < 10) {
        oled_time += 0;
      }
      oled_time += time_minute;
      display.print((char*) oled_time.c_str());
      display.display();
    }
  }
}
void update_time() {
  time_a = 0;
  time_a += millis();
  time_a += time_minute_modifier * 60000;
  time_minute = ((time_a / 60000) % 60);

  time_a = 0;
  time_a += millis();
  time_a += time_hour_modifier * 3600000;
  time_a += (time_minute_modifier / 60) * 3600000;
  time_hour = ((time_a / 3600000) % 24);
}

void draw_schedule(int x, int start_schedule_array) {
  for (int y = 5; y < 64; y += 10) {
    display.setCursor(x, y);
    oled_time = schedule[start_schedule_array];
    display.print((char*) oled_time.c_str());
    start_schedule_array ++;
  }
}
void menu_buttons() {
  if (loops == 15) {
    check_buttons();
  }

  //change menu screens/////////////////////////////////////////////////////////////////
  if (menu != 4) {
    if (loops == 15) {
      if (a_just_released == true) { //cycle menu screens
        menu++;
        if (menu == 3) {
          menu = 0;
        }
      }
    }
  }
  if (b == true && (millis() -  b_press_start) > 2000) { //set time screen
    b_press_start = millis();
    if (menu == 0) {
      menu = 4;
      return;
    }
    if (menu == 4) {
      menu = 0;
      return;
    }
  }
}
void check_buttons() { //check buttons
  pinMode(A3, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  if (analogRead(A3) < 1000 && millis() - a_end_last_pressed > 100) { //pressed
    a_just_released = 0;
    if (a == false) {
      a_press_start = millis();
      a_just_released = 1;
    }
    a = true;
  }
  else if (analogRead(A3) > 1000 && millis() - a_end_last_pressed > 100) { //not pressed
    if (a == true) {
      a_end_last_pressed = millis();
    }
    a_just_released = 0;
    a = false;
  }
  if (analogRead(A2) < 1000 && millis() - b_end_last_pressed > 100) { //pressed
    b_just_released = 0;
    if (b == false) {
      b_press_start = millis();
      b_just_released = 1;
    }
    b = true;
  }
  else if (analogRead(A2) > 1000 && millis() - b_end_last_pressed > 100) { //not pressed
    if (a == true) {
      b_end_last_pressed = millis();
    }
    b_just_released = 0;
    b = false;
  }
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
}
void shrek_exe() { //inital display code
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //start display
  display.clearDisplay();
  display.display();
  display.drawBitmap(0, 0, shrek, 43, 64, 1); //draw Shrek
  display.display();
  display.setCursor(45, 0);
  display.setTextColor(1);
  display.setTextSize(1);
  display.write("Shrek OS");
  display.setCursor(45, 56);
  display.write("Ver. 1.4");
  display.display();
}
