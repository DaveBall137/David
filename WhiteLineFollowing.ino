  int FR = 50; //setting pin 50 to the Front Right sensor
  int FL = 51; //setting pin 51 to the Front Left sensor
  int BL = 52; //setting pin 52 to the Back Left sensor
  int BR = 53; //setting pin 53 to the Back Right sensor
  
  int ENA = 10; //Setting pin 2 as a PWM for A changed to 10
  int IN1 = 49; //Setting pin 49 for the MC pin 1
  int IN2 = 48; //Setting pin 48 for the MC pin 2
  int IN3 = 47; //Setting pin 47 for the MC pin 3
  int IN4 = 46; //Setting pin 46 for the MC pin 4
  int ENB = 11; //Setting pin 3 as a PWM for B changed to 11
  int MOTORA;
  int MOTORB;
  int MotorGND = 44;
  
  int tachA = 2; // changed from 10 -> 3
  int tachB = 3; // changed from 11 -> 2

  int RWL = A0; //setting pin White line middle to pin 24
  int MWL = A1; //setting pin White line middle to pin 24
  int LWL = A2; //setting pin White line middle to pin 24
  int PWL = 23;
  int ZWL = 22;
  int LeftWhite;
  int MiddleWhite;
  int RightWhite;
  int LeftBlack;
  int MiddleBlack;
  int RightBlack;
  int ThresholdComplete; 
  int LeftTest = 0;
  int MiddleTest = 0;
  int RightTest = 0;
  float ThreshL;
  float ThreshM;
  float ThreshR;
   

  
void setup() {
  // put your setup code here, to run once:
  pinMode(PWL, OUTPUT);
  pinMode(ZWL, OUTPUT);
  pinMode(BR, INPUT);
  pinMode(BL, INPUT);
  pinMode(FR, INPUT);
  pinMode(FL, INPUT);
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MotorGND, OUTPUT);
  digitalWrite(MotorGND, LOW);
  pinMode(tachA,INPUT);
  pinMode(tachB,INPUT);
  digitalWrite(PWL, LOW);
  digitalWrite(ZWL, LOW);
  Serial.begin(9600);
  LeftWhite = 0;
  MiddleWhite = 0;
  RightWhite = 0;
  LeftBlack = 0;
  MiddleBlack = 0;
  RightBlack = 0;
  LeftTest = 0;
  MiddleTest = 0;
  RightTest = 0;
  ThresholdComplete = 0;
  int ThreshL = 0;
  int ThreshM = 0;
  int ThreshR = 0;
  MOTORA = 200;
  MOTORB = 200; 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ThresholdComplete == 0){
    digitalWrite(PWL, HIGH);
    digitalWrite(ZWL, LOW);
    MOTORA = 150;
    MOTORB = 150; //125 for both for a higher accuracy of following the line.
    WhiteLineSensors();  
  }
  else{
    WhiteLineFollowing();   
  }
}

void forward(){
  analogWrite(ENA, MOTORA);
  analogWrite(ENB, MOTORB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //Serial.println("Forward");
}

void back() {
  analogWrite(ENA, MOTORA);
  analogWrite(ENB, MOTORB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //Serial.println("Back");
}

void right() {
  analogWrite(ENA, MOTORA);
  analogWrite(ENB, MOTORB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //Serial.println("Right");
}

void left() {
  analogWrite(ENA, MOTORA);
  analogWrite(ENB, MOTORB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //Serial.println("Left");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
 // Serial.println("Stop!");
}

void WhiteLineFollowing(){
  for(;;){
    LeftTest = analogRead(LWL);
    MiddleTest = analogRead(MWL);
    RightTest = analogRead(RWL);

    
    //Analogue reading of white is less than the analogue reading of black
    if((LeftTest > ThreshL)&& (RightTest > ThreshR) && (MiddleTest < ThreshM)){  // M = White with R && L = Black
      forward();
      Serial.println("Middle ");
    }
    else if((LeftTest < ThreshL)&& (RightTest > ThreshR) && (MiddleTest < ThreshM)){//L = M = White R = Black
      left();
      delay(10);
      forward();
      delay(3);
      Serial.println("Swerving Left ");
    }
    else if((LeftTest > ThreshL)&& (RightTest < ThreshR) && (MiddleTest < ThreshM)){ //R = M = White and L = Black
      right();
      delay(10);
      forward();
      delay(3);
      Serial.println("Swerving Right ");
    }
    else if((LeftTest < ThreshL)&& (RightTest > ThreshR) && (MiddleTest > ThreshM)){ //L = White & R = M = Black
        forward();
    }
     else if((LeftTest > ThreshL)&& (RightTest < ThreshR) && (MiddleTest > ThreshM)){ //R = White & L = M = Black
        forward();
    }
    else if((LeftTest < ThreshL)&& (RightTest < ThreshR) && (MiddleTest < ThreshM)){ //R = M = L = White
      stop();
      delay(3);
      right();
      delay(10);
      forward();
      delay(3);
      Serial.println("Swerving Right ");
    }
    /*else if((LeftTest > ThreshL)&& (RightTest > ThreshR) && (MiddleTest > ThreshM)){ //R = M = L = Black
      stop();
      delay(5);
      back();
      delay(5);
      right();
      delay(15);
      Serial.println("All Black ");
    } */
    else{
      right();
      delay(20);
      stop();
      delay(10);
      Serial.println("Unsure ");
      }
  }
}

void ADCWhite(){
  LeftWhite = analogRead(LWL);
  MiddleWhite = analogRead(MWL);
  RightWhite = analogRead(RWL); 
  Serial.print("Left white is: ");
  Serial.println(LeftWhite);
  Serial.print("Middle white is: ");
  Serial.println(MiddleWhite);
  Serial.print("Right white is: ");
  Serial.println(RightWhite);
}
void ADCBlack(){
  LeftBlack = analogRead(LWL);
  MiddleBlack = analogRead(MWL);
  RightBlack = analogRead(RWL);
  Serial.print("Left Black is: "); 
  Serial.println(LeftBlack);
  Serial.print("Middle Black is: ");
  Serial.println(MiddleBlack);
  Serial.print("Right Black is: ");
  Serial.println(RightBlack);
  ADCThresholds();
}
void ADCThresholds(){
  ThreshL = ((LeftBlack + LeftWhite)/2);
  ThreshM = ((MiddleBlack + MiddleWhite)/2);
  ThreshR = ((RightBlack + RightWhite)/2);
  Serial.print("Threshold for Left is: ");
  Serial.println(ThreshL);
  Serial.print("Threshold for Middle is: ");
  Serial.println(ThreshM);
  Serial.print("Threshold for Right is: ");
  Serial.println(ThreshR);
  ThresholdComplete = 1;
  delay(100);
}

void WhiteLineSensors(){
  delay(10);
  while((LeftWhite == 0)||(MiddleWhite == 0)||(RightWhite == 0)){
  if(digitalRead(FR) == HIGH){
   ADCWhite();
   }
  else{
    
  }
 }
  while((LeftBlack == 0)||(MiddleBlack == 0)||(RightBlack == 0)){
  if(digitalRead(BR) == HIGH){
    ADCBlack();
  }
  else{
    
  }
  } 
  }
