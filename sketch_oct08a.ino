int data0;

void setup() {
  
  Serial.begin(9600);
  pinMode(D7,OUTPUT);
  digitalWrite(D7, LOW);

}

void loop() {
  data0 = analogRead(A1);
  if(data0 > 2000){
    digitalWrite(D7,HIGH);
    delay(100);
  }else{
      digitalWrite(D7, LOW);
      delay(100);
}
}
