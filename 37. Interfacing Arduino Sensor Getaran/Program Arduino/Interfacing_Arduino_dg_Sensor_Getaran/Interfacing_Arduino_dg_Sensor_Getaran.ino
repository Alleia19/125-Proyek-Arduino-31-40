/*************************************
 * Program : Project 37. Interfacing Arduino Sensor Getaran
 * Input   : Sensor Getaran
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
word vib;

void setup(){
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  lcd.begin(16, 2);
  lcd.print("   Interface");
  lcd.setCursor(0, 1);
  lcd.print("Vibration Sensor");
  delay(2000);
  // aktivasi interupsi eksternal 0
  //jika ada interupsi program menuju subrutin vibration
  //interupsi dikerjakan saat pin int0 (pin 2) dlm kondisi FALLING 
  attachInterrupt(0, vibration, FALLING);
}

void loop(){
  vib = 0;  
  lcd.clear();
  lcd.print("Jumlah Getaran");
  lcd.setCursor(0, 1);
  lcd.print("/5detik:");
  lcd.setCursor(8,1);
  lcd.print(vib);
  lcd.print("      ");
  //tunda 5 detik
  for(int i=1; i<6; i++){    
    lcd.setCursor(15,1);
    lcd.print(i);
    delay(1000);
  }  
}

void vibration(){
  vib++;
  lcd.setCursor(8,1);
  lcd.print(vib);
  lcd.print("    ");
}

