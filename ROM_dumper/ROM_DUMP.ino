// CONNECTIONS

#define out1 A1
#define out2 A2
#define out3 A3
#define out4 A4
#define out5 A5
#define out6 A6
#define out7 A7
#define out8 A8


#define in0  22
#define in1  23
#define in2  24
#define in3  25
#define in4  26
#define in5  27
#define in6  28
#define in12 29

#define in10 32
#define in11 33
#define in9  34
#define in8  35
#define in13 36
#define in14 37

#define in7 38

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("ROM DUMP");

  pinMode(out1, INPUT);
  pinMode(out2, INPUT);
  pinMode(out3, INPUT);
  pinMode(out4, INPUT);
  pinMode(out5, INPUT);
  pinMode(out6, INPUT);
  pinMode(out7, INPUT);
  pinMode(out8, INPUT);

  pinMode(in0, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  pinMode(in9, OUTPUT);
  pinMode(in10, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(in12, OUTPUT);
  pinMode(in13, OUTPUT);
  pinMode(in14, OUTPUT);
}

unsigned int addresscounter = 0;
unsigned int addressmod = 2;

int binaryvalue[7] = {};

void loop() {
  // put your main code here, to run repeatedly:
  
  // output the current binary number
  addressmod = 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in0, HIGH);} else{digitalWrite(in0, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in1, HIGH);} else{digitalWrite(in1, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in2, HIGH);} else{digitalWrite(in2, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in3, HIGH);} else{digitalWrite(in3, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in4, HIGH);} else{digitalWrite(in4, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in5, HIGH);} else{digitalWrite(in5, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in6, HIGH);} else{digitalWrite(in6, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in7, HIGH);} else{digitalWrite(in7, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in8, HIGH);} else{digitalWrite(in8, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in9, HIGH);} else{digitalWrite(in9, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in10, HIGH);} else{digitalWrite(in10, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in11, HIGH);} else{digitalWrite(in11, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in12, HIGH);} else{digitalWrite(in12, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in13, HIGH);} else{digitalWrite(in13, LOW);} addressmod = addressmod * 2;
  if ((addresscounter%addressmod) > (addressmod/2)-1){digitalWrite(in14, HIGH);} else{digitalWrite(in14, LOW);} addressmod = addressmod * 2;
  
  // wait for ROM to output the value
  delay(5);

  // print the ROM value
  Serial.print(addresscounter);
  Serial.print("  ");
  Serial.print(digitalRead(out1));
  Serial.print(digitalRead(out2));
  Serial.print(digitalRead(out3));
  Serial.print(digitalRead(out4));
  Serial.print(digitalRead(out5));
  Serial.print(digitalRead(out6));
  Serial.print(digitalRead(out7));
  Serial.println(digitalRead(out8));
  
  // increment the address number
  addresscounter ++;
  if (addresscounter > 32770){
    Serial.println("DONE!");
    exit(0);
  }
}
