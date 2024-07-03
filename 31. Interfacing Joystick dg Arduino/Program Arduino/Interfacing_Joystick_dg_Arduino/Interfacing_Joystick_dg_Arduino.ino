/*************************************
 * Program : Project 31. Interfacing Joystick dg Arduino
 * Input   : Sensor Joystick
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int joyX = A0;
int joyY = A1;
int value1 = 0;
int value2 = 0;
int SW = 8;
int led = 0;
 
void setup() {
  pinMode(13, OUTPUT);
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
  lcd.begin(16, 2);
  lcd.print("Baca Joystick");
}
 
void loop() {
  value1 = analogRead(joyX);   
  value2 = analogRead(joyY); 
  lcd.setCursor(0 ,1);
  //X=46 --> 1018
  lcd.print("X:");
  lcd.print(value1);
  //Y=46 --> 1018
  lcd.print(" Y:");
  lcd.print(value2);
  lcd.print("  ");
  if(digitalRead(SW)==0){
    delay(100);
    led=!led;
    digitalWrite(13, led);
  }
  delay(100);
  }
