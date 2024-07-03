/*************************************
 * Program : Project 38. IoT Arduino Kontrol Relay WiFi Android
 * Input   : Module WiFi ESP8266
 * Output  : 4 Relay
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
char auth[] = "e567dc13241043499d1dab8c929dbcd9";
// Sesuaikan dengan ssid dan password hotspot anda
char ssid[] = "TokotronikWiFi";
char pass[] = "inkubatek";
SoftwareSerial EspSerial(2, 3); // RX, TX
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
void setup()
{  
  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass); 
}

void loop()
{
  Blynk.run(); 
}

