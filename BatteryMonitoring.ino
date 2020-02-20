float ReadVoltage = 0;
float voltage = 0;
float threshold = 5.5; //Threshold depending on the battery to determine low battery SoC
float v_read = A3;
float Adjustment = 0.110;




void setup() {
  // put your setup code here, to run once:
  pinMode(v_read,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:  
  ReadVoltage = analogRead(v_read);
  //Serial.print("Read Voltage:"); //Prints to monitor
  //Serial.println(ReadVoltage); // Only needed for testing
  voltage = ((ReadVoltage*(7.5/1023))- Adjustment);
  Serial.print("Voltage:"); //Prints to monitor
  Serial.println(voltage);

  if(voltage < threshold){
    Serial.print("Voltage is too low:"); //Prints to monitor
    Serial.println(voltage);
  }

}
