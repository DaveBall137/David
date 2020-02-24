#include <SoftwareSerial.h>
SoftwareSerial HC12(10,11); //10,11 for Arduino uno Tx, Rx
//SoftwareSerial HC12(12,13); //12,13 for Arduino Mega Tx, Rx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC12.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(HC12.available()){ // if HC-12 module has data
    Serial.write(HC12.read()); // sends data from HC12 to Serial monitor
  }
  if(Serial.available()){ // if Serial monitor has data
    HC12.write(Serial.read()); // sends data from arduino to HC12 module which will transmit
  }
}
