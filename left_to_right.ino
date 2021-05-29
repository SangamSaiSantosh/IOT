#include <LiquidCrystal.h>
LiquidCrystal ld(12,11,5,4,3,2);

void clr(){
  int a;
  for(a=0;a<16;a++){
    ld.setCursor(a,1);
    ld.print("  ");
  }
}
void right(){
  
  int i;
  for (i=16;i>=-28;i--){
    clr();
    ld.setCursor(i,1);
    ld.print("iot with aws class");
    delay(100);
  }
  
}
void left(){
  
  
  int i;
  for (i=0;i<=28;i++){
    clr();
    ld.setCursor(i,1);
    ld.print("iot with aws class");
      delay(100);
  }
}




void setup() {
  // put your setup code here, to run once:
 ld.begin(16,2);
 ld.setCursor(4,0);
 ld.print("welcome");
 
}

void loop() {
  // put your main code here, to run repeatedly:
left();
right();
}
