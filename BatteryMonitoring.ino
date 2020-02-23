float voltage = 0;
float threshold = 5.9; //Threshold depending on the battery to determine low battery SoC
float v_read = A3;
float Adjustment = 0.110;

void setup() {
  // put your setup code here, to run once:
  pinMode(v_read,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:  
  //Serial.print("Read Voltage:"); //Prints to monitor
  //Serial.println(ReadVoltage); // Only needed for testing
  voltage = ((analogRead(v_read)*(7.5/1023))- Adjustment);
  Serial.print("Voltage:"); //Prints to monitor
  Serial.println(voltage);

  if(voltage < threshold){
    Serial.print("Voltage is too low:"); //Prints to monitor
    Serial.println(voltage);
  }

}
