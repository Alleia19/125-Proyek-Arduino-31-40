 /*************************************
 * Program : Project 32. Interfacing LCD Nokia 5110
 * Output  : LCD Nokia 5110
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Koneksi pin SPI Arduino - LCD Nokia 5110 :
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup()   {
  display.begin(); 
  display.setContrast(50);
  delay(100);
  display.clearDisplay(); 
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Arduino & LCD");
   display.setCursor(0,10);
  display.println("NOKIA 5110");
  display.setCursor(0,20);
  display.println("tokotronik");
  display.setTextSize(2);
  display.setCursor(0,30);
  display.println("JOGJA");  
  display.display();
}

void loop() {
  
}


