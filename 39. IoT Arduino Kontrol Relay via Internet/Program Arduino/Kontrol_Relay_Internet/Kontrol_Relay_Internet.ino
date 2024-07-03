/*************************************
 * Program : Project 39. IoT Arduino Kontrol Relay via Internet
 * Input   : Sensor , Tombol push
 * Output  : LCD 2x16, BUZZER, Relay
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/

#include <SoftwareSerial.h> 
#define DEBUG true 
SoftwareSerial esp8266(2,3); 
//TX (ESP) -- PIN 2 (ARDUINO)
//RX (ESP) -- PIN 3 (ARDUINO)
void setup()
{
  Serial.begin(9600);
  esp8266.begin(9600);   
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);  
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);  
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);   
  sendData("AT+RST\r\n",2000,DEBUG); // reset module
  sendData("AT+CWMODE=1\r\n",1000,DEBUG); // configure as access point
  //ganti nama SSID dan password sesuai dengan SSID dan password Hotspot anda :
  sendData("AT+CWJAP=\"TokotronikWiFi\",\"inkubatek\"\r\n", 2000, DEBUG);   //connect wifi network
  while(!esp8266.find("OK")) { //wait for connection
  } 
  sendData("AT+CIFSR\r\n",1000,DEBUG); // get ip address
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG); // configure for multiple connections
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // turn on server on port 80
}
 
void loop()
{
  if(esp8266.available()) // check if the esp is sending a message 
  {    
    //Serial.write(esp8266.read());
    if(esp8266.find("+IPD,"))
    {
     delay(1000); 
     int connectionId = esp8266.read()-48; 
     esp8266.find("pin=");      
     int pinNumber = (esp8266.read()-48); 
     Serial.print(pinNumber);
     digitalWrite(pinNumber, !digitalRead(pinNumber));      
     // make close command
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId; // append connection id
     closeCommand+="\r\n";     
     sendData(closeCommand,1000,DEBUG); // close connection
    }
  }
}
 
String sendData(String command, const int timeout, boolean debug)
{
    String response = "";    
    esp8266.print(command);     
    long int time = millis();    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {          
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }    
    if(debug)
    {
      Serial.print(response);
    }    
    return response;
}
