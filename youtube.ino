#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7


byte a[] = {
  B01111,
  B11101,
  B11100,
  B11100,
  B11100,
  B11100,
  B11101,
  B01111
};

byte b[] = {
  B11110,
  B11111,
  B11111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11110
};



void setup() {
lcd.begin(16,2);
lcd.createChar(1,a);
lcd.createChar(2,b); 
}

void loop() {
  
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.write(byte(2)); 
  lcd.setCursor(1,1);
  
  lcd.print("youtube");
}
