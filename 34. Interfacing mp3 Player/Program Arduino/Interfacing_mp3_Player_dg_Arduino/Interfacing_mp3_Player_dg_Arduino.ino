/*************************************
 * Program : Project 34. Interfacing mp3 Player
 * Input   : 4 Tombol push ON
 * Output  : Module mp3 player MP3-TF-16P 
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int music;

void setup () {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  mySerial.begin(9600);
  mp3_set_serial(mySerial);	
  delay(1);  
  mp3_set_volume(15);  // value 0~30
  mp3_play(1);
}

void loop() {   
  if(digitalRead(3) == LOW){  //tombol next >>
    mp3_next();
    delay(1000);
    music++;
  }
  
  if(digitalRead(4) == LOW){  //tombol prev <<
    mp3_prev();
    delay(1000);
    if(music > 1){
      music--;
    }
  }
  
  if(digitalRead(5) == LOW){  //tombol play
    mp3_play(music);
    delay(1000);
  }
  
  if(digitalRead(6) == LOW){  //tombol stop 
    mp3_stop();
    delay(1000);
  }
}


