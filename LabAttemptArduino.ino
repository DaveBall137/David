  int FR = 50; //setting pin 50 to the Back Right sensor
  int FL = 51; //setting pin 51 to the Back Left sensor
  int BR = 52; //setting pin 52 to the Front Left sensor
  int BL = 53; //setting pin 53 to the Front Right sensor
  int ENA = 2; //Setting pin 2 as a PWM for A
  int IN1 = 49; //Setting pin 49 for the MC pin 1
  int IN2 = 48; //Setting pin 48 for the MC pin 2
  int IN3 = 47; //Setting pin 47 for the MC pin 3
  int IN4 = 46; //Setting pin 46 for the MC pin 4
  int ENB = 3; //Setting pin 3 as a PWM for B
  int carSpeed = 250; //Setting speed to 250  THIS VALUE DEFINES THE PWM OF THE SIGNAL 255 = 5V
  int slowcarSpeed = 210; //Setting slow speed to 125 for more complex manouvers
  //int BatteryLevel = A0; //Setting the battery level to pin 22, later this will be set by the battery monitoring
  //int Leaving = 22;

  
void setup() {
  // put your setup code here, to run once:
  pinMode(BR, INPUT);
  pinMode(BL, INPUT);
  pinMode(FR, INPUT);
  pinMode(FL, INPUT);
  //pinMode(BatteryLevel, INPUT);
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //pinMode(Leaving, OUTPUT);
  
}


void forward(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, slowcarSpeed);
  /*digitalWrite(ENA, HIGH);
  digitalWrite(ENB,HIGH);*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, slowcarSpeed);
  /*digitalWrite(ENA, HIGH);
  digitalWrite(ENB,HIGH);*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}

void right() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, slowcarSpeed);
  /*digitalWrite(ENA, HIGH);
  digitalWrite(ENB,HIGH);*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}

void left() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, slowcarSpeed);
  /*digitalWrite(ENA, HIGH);
  digitalWrite(ENB,HIGH);*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Left");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}

void obstacleavoidance(){
  if((digitalRead(FR)==HIGH) && (digitalRead(FL)==HIGH)){
    Serial.println("FRONT DETECT");
    stop();
    delay(10);
    back();
    delay(10);
    right();
    delay(50);
  }
  else if((digitalRead(FR)==HIGH) && (digitalRead(FL)==LOW)){
    Serial.println("Front Right Active - STOP");
    stop();
    delay(10);
    left();
    delay(50);  
  }
  else if((digitalRead(FR)==LOW) && (digitalRead(FL)==HIGH)){
    Serial.println("Front Left Active - STOP");
    stop();
    delay(10);
    back();
    delay(10);
    right();
    delay(50);
    }
/*    else if((digitalRead(BR)==HIGH) && (digitalRead(BL)==HIGH)){
    Serial.println("BACK DETECT");
    forward();
    delay(10);
  }
  else if((digitalRead(BR)==HIGH) && (digitalRead(BL)==LOW)){
    Serial.println("Back Right Active - STOP");
    right();
    delay(50);
    forward();
  }
  else if((digitalRead(BR)==LOW) && (digitalRead(BL)==HIGH)){
    Serial.println("Back Left Active - STOP");
    left();
    delay(50);
    forward();
  }*/
  else{
    forward();
    delay(10);
}
}

void loop() {
  // put your main code here, to run repeatedly:
  obstacleavoidance(); 
}
