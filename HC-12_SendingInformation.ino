#include <SoftwareSerial.h>
//SoftwareSerial HC12(10,11); //10,11 for Arduino uno Tx, Rx
SoftwareSerial HC12(12,13); //12,13 for Arduino Mega Tx, Rx
float voltage = 2;
float locationx = 12;
float locationy = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC12.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
  HC12.println("Starting communication");
  communication();
 
  
}

void communication(){
  if(HC12.available()){ // if HC-12 module has data
    Serial.write(HC12.read()); // sends data from HC12 to Serial monitor
  }
  
  if(Serial.available()){ // if Serial monitor has data
    HC12.write(Serial.read()); // sends data from arduino to HC12 module which will transmit
  }

    HC12.print("Voltage: <");
    HC12.print(voltage);
    HC12.println(">");
    Serial.print("Voltage: <");
    Serial.print(voltage);
    Serial.println(">");
    voltage = voltage + 1;
    HC12.print("Location X: ");
    HC12.println(locationx);
    locationx = locationx - 1.23;
    HC12.print("Location Y: ");
    HC12.println(locationy);
    locationy = locationy + 1.76;
    delay(200);


}
