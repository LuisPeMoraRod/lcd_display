#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int b0=2;
int b1=3;
int b2=4;
int b3=5;
int b4=6;
int b5=7;
int b6=8;
int b7=9;
int b8=10;
int a0 = A0;
void setup()
{
  pinMode(b0,INPUT);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(b5,INPUT);
  pinMode(b6,INPUT);
  pinMode(b7,INPUT);
  pinMode(b8,INPUT);
  pinMode(a0, INPUT);

	// initialize the LCD
	lcd.init();
  
	// Turn on the blacklight and print a message.
	lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  bool b0_p=digitalRead(b0);
  bool b1_p=digitalRead(b1);
  bool b2_p=digitalRead(b2);
  bool b3_p=digitalRead(b3);
  bool b4_p=digitalRead(b4);
  bool b5_p=digitalRead(b5);
  bool b6_p=digitalRead(b6);
  bool b7_p=digitalRead(b7);
  bool scale = digitalRead(b8);
  
  float v = b0_p+2*b1_p+4*b2_p+8*b3_p+16*b4_p+32*b5_p+64*b6_p+128*b7_p;

  int refValue = analogRead(a0);
  float vRef = refValue * (5.0 / 1023.0);

  v =  v * (vRef / 255.0) * 2.0;

	lcd.clear();
  lcd.print("Voltaje es: "+String(v));
  delay(100);
}
