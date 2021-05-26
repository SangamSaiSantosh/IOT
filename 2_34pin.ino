// Light Blinking


void setup() {

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
 int i,j,k;
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
  {
    for(k=0;k<2;k++){
      digitalWrite(2,i); 
      digitalWrite(3,j);
      digitalWrite(4,k);
      delay(1000);  
      }
  }
 }
}
