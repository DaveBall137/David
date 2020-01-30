  int ENA = 10; //Setting pin 2 as a PWM for A changed to 10
  int IN1 = 49; //Setting pin 49 for the MC pin 1
  int IN2 = 48; //Setting pin 48 for the MC pin 2
  int IN3 = 47; //Setting pin 47 for the MC pin 3
  int IN4 = 46; //Setting pin 46 for the MC pin 4
  int ENB = 11; //Setting pin 3 as a PWM for B changed to 11
  int MOTORA;
  int MOTORB;
  
  int tachA = 3; // changed from 10 -> 3
  int tachB = 2; // changed from 11 -> 2
  
  int widthA;  int widthB;
  int MA1;  int MA2;  int MA3;  int MA4;  int MA5;  int MA6;  int MA7;  int MA8;  int MA9;  int MA10;  int MA11;  int MA12; 
  int MB1;  int MB2;  int MB3;  int MB4;  int MB5;  int MB6;  int MB7;  int MB8;  int MB9;  int MB10;  int MB11;  int MB12; 
  int AVwidthA;  int AVwidthB;
  
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
  pinMode(tachA,INPUT);
  pinMode(tachB,INPUT);
  Serial.begin(9600);
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
