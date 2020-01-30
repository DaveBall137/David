  int FR = 50; //setting pin 50 to the Front Right sensor
  int FL = 51; //setting pin 51 to the Front Left sensor
  int BL = 52; //setting pin 52 to the Back Left sensor
  int BR = 53; //setting pin 53 to the Back Right sensor
  
void setup() {
  // put your setup code here, to run once:
  pinMode(BR, INPUT);
  pinMode(BL, INPUT);
  pinMode(FR, INPUT);
  pinMode(FL, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(FR)==HIGH) && (digitalRead(FL)==HIGH)){
    Serial.println("FRONT DETECT");
    delay(50);
  }
  else if((digitalRead(FR)==HIGH) && (digitalRead(FL)==LOW)){
    Serial.println("Front Right Active - STOP");
    delay(50);  
  }
  else if((digitalRead(FR)==LOW) && (digitalRead(FL)==HIGH)){
    Serial.println("Front Left Active - STOP");
    delay(50);
    }
    else if((digitalRead(BR)==HIGH) && (digitalRead(BL)==HIGH)){
    Serial.println("Back DETECT");
    delay(50);
  }
  else if((digitalRead(BR)==HIGH) && (digitalRead(BL)==LOW)){
    Serial.println("Back Right Active - STOP");
    delay(50);  
  }
  else if((digitalRead(BR)==LOW) && (digitalRead(BL)==HIGH)){
    Serial.println("Back Left Active - STOP");
    delay(50);
    }
}
