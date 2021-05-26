// Light Blinking


void setup() {

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  
}

void loop() {
  int i,j,k;
  for(i=0;i<2;i++)
  {
    for(j=0;j<2;j++)
    {
      
  digitalWrite(2,i);
  delay(100);
  digitalWrite(3,j);
delay(100);
 

delay(1000);
    }}
}
