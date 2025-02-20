/*************************************
 * Program : Project 35.  Interfacing Sensor Arus
 * Input   : Sensor Arus ACS712
 * Output  : LCD 2x16
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <LiquidCrystal.h>
const int currentPin = 0;
const unsigned long sampleTime = 100000UL;    // sample over 100ms, it is an exact number of cycles for both 50Hz and 60Hz mains
const unsigned long numSamples = 250UL;       // choose the number of samples to divide sampleTime exactly, but low enough for the ADC to keep up
const unsigned long sampleInterval = sampleTime/numSamples;  // the sampling interval, must be longer than then ADC conversion time
const int adc_zero = 510;                     // relative digital zero of the arudino input from ACS712 (could make this a variable and auto-adjust it)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
 Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Sensor Arus");
  lcd.setCursor(0,1);
  lcd.print("Arus:"); 
  delay(1000);
}

void loop()
{
 unsigned long currentAcc = 0;
 unsigned int count = 0;
 unsigned long prevMicros = micros() - sampleInterval ;
 while (count < numSamples)
 {
   if (micros() - prevMicros >= sampleInterval)
   {
     int adc_raw = analogRead(currentPin) - adc_zero;
     currentAcc += (unsigned long)(adc_raw * adc_raw);
     ++count;
     prevMicros += sampleInterval;
   }
 }
 
 float rms = sqrt((float)currentAcc/(float)numSamples) * (75.7576 / 1024.0);
 //Serial.println(rms);
  lcd.setCursor(5,1);
  lcd.print(rms); 
  lcd.print("A           "); 
 
}

