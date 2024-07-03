/*************************************
 * Program : Project Reciver
 * Input   : Modul RF Module 433 Mhz
 * Output  : Serial Monitor
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <VirtualWire.h>
String inString="";
void setup(){
    Serial.begin(9600);
    Serial.println("Interfacing Arduino dg Wireless 433MHz");
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(12);
    vw_setup(4000);  // Bits per sec
    vw_rx_start();       // Start the receiver PLL running
}

void loop(){
    uint8_t buf[VW_MAX_MESSAGE_LEN];     //data RF
    uint8_t buflen = VW_MAX_MESSAGE_LEN; //panjang data

    if (vw_get_message(buf, &buflen)){ // Non-blocking
        inString="";
        for(char i; i<buflen; i++){
          inString += char(buf[i]);
        }
        Serial.println(inString);
    }
}

