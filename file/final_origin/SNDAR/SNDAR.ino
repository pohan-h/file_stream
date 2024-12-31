  // 轉向
#define dirPin 2
#define stepPin 3

// 測距(要換角位)
#define TrigPin 12
#define EchoPin 13

float ProgTime, Dist;
int degree = 0;
int j = 0;
bool dir = true;



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
  
  

}

void loop() {
  // 測距
  ProgTime = Trigger();

  
  // 轉向
  digitalWrite(dirPin ,dir);

  for(int i=0; i<17; i++){
    digitalWrite(stepPin, HIGH);
    delay(100);
    digitalWrite(stepPin, LOW);
    delay(100);
  }
delay(500);

  
  j++;
  if(dir){
    degree += 30;
  }
  else{
    degree -= 30;
  }
  Serial.print(ProgTime*0.0172);
  Serial.print(' ');
  Serial.println(degree);
  if(j == 0 || j == 9){
    j = 0;
    dir = !dir;
  }
  
}
