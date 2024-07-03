/*************************************
 * Program : Project Reciver
 * Input   : Modul RF Module 433 Mhz
 * Output  : Serial Monitor
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <VirtualWire.h>
char *controller;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  controller="INKUBATEK JOGJA @2016";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  delay(100);
  digitalWrite(13,0);
  delay(1000);
}



