#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void clr(){
  int a;
  for(a=0;a<16;a++){
    lcd.setCursor(a,1);
    lcd.print("  ");
  }
}
 

void setup() {
  pinMode(6,INPUT);
  lcd.begin(16,2);  
}

void loop() {
 
 int b;
 b=digitalRead(6);
  if (b==1)
  {
    for(int i=0;i<=28;i++){
      clr();
      lcd.setCursor(0,0);
      lcd.print("some one is detected");
    }   
  }
  
  if(b==0){
  for(int i=0;i<=28;i++){
    clr();
    lcd.setCursor(0,0);
    lcd.print("no one is detected");
  }
  }
}
