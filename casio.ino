#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(13,12,11,10,1,0);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {​​​​​
{​​​​​'7','8','9','/'}​​​​​,
{​​​​​'4','5','6','*'}​​​​​,
{​​​​​'1','2','3','-'}​​​​​,
{​​​​​'o','0','=','+'}​​​​​
}​​​​​;
byte rowPins[ROWS] = {​​​​​9, 8, 7, 6}​​​​​; //connect to the row pinouts of the keypad
byte colPins[COLS] = {​​​​​5, 4, 3, 2}​​​​​; //connect to the column pinouts of the keypad
//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 long Num1,Num2,Number;
char key,action;
boolean result = false;

void setup(){​​​​​
lcd.begin(16,2);
}​​​​​


void loop(){​​​​​
char key = keypad.getKey();// Read the key
if (key)
{​​​​​
lcd.clear();
if (key=='o') //If cancel Button is pressed
{​​​​​
Number=Num1=Num2=0;
result=false;
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​

if (key == '1') //If Button 1 is pressed
{​​​​​
if (Number==0)
{​​​​​
Number=1;
}​​​​​
else{​​​​​
Number = (Number*10) + 1; //Pressed twice
}​​​​​
 lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
if (key == '4') //If Button 4 is pressed
{​​​​​
if (Number==0)
{​​​​​
Number=4;
}​​​​​
else
{​​​​​
Number = (Number*10) + 4; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
if (key == '7') //If Button 7 is pressed
{​​​​​
if (Number==0)
{​​​​​
Number=7;
}​​​​​
else{​​​​​
Number = (Number*10) + 7; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​

 if (key == '0')
{​​​​​//Button 0 is Pressed
if (Number==0)
{​​​​​
Number=0;
}​​​​​
else{​​​​​
Number = (Number*10) + 0; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
if (key == '2') //Button 2 is Pressed
{​​​​​
if (Number==0){​​​​​
Number=2;
}​​​​​
else{​​​​​
Number = (Number*10) + 2; //Pressed twice
}​​​​​lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
if (key == '5')
{​​​​​
if (Number==0){​​​​​
Number=5;
}​​​​​
else{​​​​​
Number = (Number*10) + 5; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
if (key == '8')
{​​​​​
if (Number==0){​​​​​

Number=8;
}​​​​​
else{​​​​​
Number = (Number*10) + 8; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​

 if (key == '=')
{​​​​​
Num2=Number;
result = true;
}​​​​​
if (key == '3')
{​​​​​
if (Number==0)
{​​​​​
Number=3;
}​​​​​
else{​​​​​
Number = (Number*10) + 3; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
if (key == '6')
{​​​​​
if (Number==0)
{​​​​​
Number=6;
}​​​​​
else{​​​​​
Number = (Number*10) + 6; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
if (key == '9')
{​​​​​
if (Number==0){​​​​​
Number=9;
}​​​​​
else{​​​​​
Number = (Number*10) + 9; //Pressed twice
}​​​​​
lcd.setCursor(0,0);
lcd.print(Number);
}​​​​​
 if (key == '+' || key == '-' || key == '*' || key == '/') //Detecting Buttons on Column 4
{​​​​​
Num1 = Number;
Number =0;
if (key == '+')
{​​​​​action = '+';}​​​​​
if (key == '-')
{​​​​​action = '-'; }​​​​​
if (key == '*')
{​​​​​ action = '*';}​​​​​
if (key == '/')
{​​​​​ action = '/';}​​​​​
 delay(100);
}​​​​​
}​​​​​
if (result==true)
{​​​​​
if (action=='+')
{​​​​​
Number = Num1+Num2;
}​​​​​
 if (action=='-')
{​​​​​
Number = Num1-Num2;
}​​​​​
 if (action=='*')
{​​​​​
Number = Num1*Num2;
}​​​​​
 if (action=='/')
{​​​​​
Number = Num1/Num2;
}​​​​​
 lcd.setCursor(0,0);
lcd.print(Num1);
lcd.print(action);
lcd.print(Num2);
lcd.print("=");
lcd.setCursor(0,1);
lcd.print(Number);
result=0;
Number=Num1=Num2=0;
}​​​​​
//DisplayResult();
}​​​​​
