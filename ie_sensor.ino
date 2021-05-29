#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  pinMode(6,INPUT);
  lcd.begin(16,2); 
}

void loop() {
int a;
a=digitalRead(6);
if(a==1){
  lcd.setCursor(0,0);
  lcd.print("object is detected");
}
if(a==0){
  lcd.setCursor(0,0);
  lcd.print("object is not detected");
}

}
