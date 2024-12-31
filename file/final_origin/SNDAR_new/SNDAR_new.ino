// 轉向
#define dirPin 2
#define stepPin 3

// 測距(要換角位)
#define TrigPin 12
#define EchoPin 13

float ProgTime, Dist;
int j = 0;


float Trigger(){
  digitalWrite(TrigPin, LOW);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  return pulseIn(EchoPin, HIGH);
}



void setup() {
  // 轉向
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);


  // 測距
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);
  
  delay(9000);
  

}

void loop() {
  digitalWrite(dirPin ,HIGH);
  // 測距
  ProgTime = Trigger();

  for(int i=0; i<8; i++){
    digitalWrite(stepPin, HIGH);
    delay(10);
    digitalWrite(stepPin, LOW);
    delay(10);
  }
  delay(100);
  Serial.println(ProgTime*0.01768);
  j++;
  
  
  ProgTime = Trigger();
  for(int i=0; i<9; i++){
    digitalWrite(stepPin, HIGH);
    delay(10);
    digitalWrite(stepPin, LOW);
    delay(10);
  }
  delay(100);
  Serial.println(ProgTime*0.01768);
  j++;
  
  if(j==18){
    j=0;
    digitalWrite(dirPin ,LOW);
    delay(30);
    
    for(int i=0; i<153; i++){
    digitalWrite(stepPin, HIGH);
    delay(15);
    digitalWrite(stepPin, LOW);
    delay(15);
    }
    delay(30);
    
  }
  
  
}
