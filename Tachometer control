  int ENA = 2; //Setting pin 2 as a PWM for A
  int IN1 = 49; //Setting pin 49 for the MC pin 1
  int IN2 = 48; //Setting pin 48 for the MC pin 2
  int IN3 = 47; //Setting pin 47 for the MC pin 3
  int IN4 = 46; //Setting pin 46 for the MC pin 4
  int ENB = 3; //Setting pin 3 as a PWM for B
  int MOTORA = 200;
  int MOTORB = 200;
  int tachA = 10;
  int tachB = 11;
 /* unsigned long widthA;
  unsigned long widthB; */
  int widthA;
  int widthB;
  int MA1;
  int MA2;
  int MA3;
  int MA4;
  int MA5;
  int MA6;
  int MA7;
  int MA8;
  int MA9;
  int MA10;
  int MA11;
  int MA12; 
  int MB1;
  int MB2;
  int MB3;
  int MB4;
  int MB5;
  int MB6;
  int MB7;
  int MB8;
  int MB9;
  int MB10;
  int MB11;
  int MB12; 
  int AVwidthA;
  int AVwidthB;
  
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(tachA,INPUT);
    pinMode(tachB,INPUT);   
}

 void forward(){
    analogWrite(ENA, MOTORB);
    analogWrite(ENB, MOTORA);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Forward");
    comparison();

}



void comparison(){
  // Cheching MOTORB is quicker than MOTORA
  MA1 = pulseIn(tachA, HIGH);
  MB1 = pulseIn(tachB, HIGH);
  MA2 = pulseIn(tachA, HIGH);
  MB2 = pulseIn(tachB, HIGH);
  MA3 = pulseIn(tachA, HIGH);
  MB3 = pulseIn(tachB, HIGH);
  MA4 = pulseIn(tachA, HIGH);
  MB4 = pulseIn(tachB, HIGH);
  MA5 = pulseIn(tachA, HIGH);
  MB5 = pulseIn(tachB, HIGH);
  MA6 = pulseIn(tachA, HIGH);
  MB6 = pulseIn(tachB, HIGH);
  MA7 = pulseIn(tachA, HIGH);
  MB7 = pulseIn(tachB, HIGH);
  MA8 = pulseIn(tachA, HIGH);
  MB8 = pulseIn(tachB, HIGH);
  MA9 = pulseIn(tachA, HIGH);
  MB9 = pulseIn(tachB, HIGH);
  MA10 = pulseIn(tachA, HIGH);
  MB10 = pulseIn(tachB, HIGH);
  MA11 = pulseIn(tachA, HIGH);
  MB11 = pulseIn(tachB, HIGH);
  MA12 = pulseIn(tachA, HIGH);
  MB12 = pulseIn(tachB, HIGH);
  widthA = ((MA1 + MA2 + MA3 + MA4 + MA5 + MA6 + MA7 + MA8 + MA9 + MA10 + MA11 + MA12)/120); // Averages the values if the value of 60 is increased by a power of 10 it
  widthB = ((MB1 + MB2 + MB3 + MB4 + MB5 + MB6 + MB7 + MB8 + MB9 + MB10 + MB11 + MB12)/120); //reduces the accuracy
  Serial.print("This is widthA: ");
  Serial.println(widthA);
  Serial.print("This is MOTORA: ");
  Serial.println(MOTORA);
  Serial.print("This is widthB: ");
  Serial.println(widthB);
  Serial.print("This is MOTORB: ");
  Serial.println(MOTORB);
  if((widthA > widthB) && (MOTORB >= 150)){
    MOTORB--;
    }
  else if((widthA < widthB) && (MOTORB < 250)){
    MOTORB++;
    }
  else if((widthA < widthB) && (MOTORB >= 250 )){
    MOTORB -= 10;
    }
  else if(MOTORB < 150 ){
    MOTORA == 0;
    MOTORB == 0;
    }  
  else{
    Serial.println("SYNCHED");
    }
}



void loop() {
  // put your main code here, to run repeatedly:
    forward();

}
