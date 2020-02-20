  int FRBumpPower = 40;
  int FRBump = 41;
  int FLBumpPower = 42;
  int FLBump = 43;
  int BumpGND = 45;


void setup() {
  // put your setup code here, to run once:
  pinMode(FLBump,INPUT);
  pinMode(FRBump, INPUT);
  pinMode(FRBumpPower, OUTPUT);
  pinMode(FLBumpPower,OUTPUT);
  pinMode(BumpGND,OUTPUT);
  digitalWrite(FRBumpPower,HIGH);
  digitalWrite(FLBumpPower,HIGH);
  digitalWrite(BumpGND,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(FRBump)==HIGH) && (digitalRead(FLBump)==HIGH)){
    Serial.println("FRONT Bumpers DETECT");
  }
  else if((digitalRead(FRBump)==HIGH) && (digitalRead(FLBump)==LOW)){
    Serial.println("Front Right Bumper - STOP");
  }
  else if((digitalRead(FRBump)==LOW) && (digitalRead(FLBump)==HIGH)){
    Serial.println("Front Left Bumper - STOP");
    }
    else{
      Serial.println("No bumper detecting");
    }
}
