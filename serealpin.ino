
void setup() { 

  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
   
 int val;
  if(Serial.available()>0){
     val=Serial.read();//for sting readsting
    // Serial.print(val);for sting
 if(val=='1' )
  {
    digitalWrite(13,1);
    Serial.println("LED ON");
    //delay(1000);
    
  }
  else if(val=='2')
  {
    digitalWrite(13,0);
    Serial.println("LED OFF");
    //delay(1000);
   }

}
}

  
