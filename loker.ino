#include <LiquidCrystal.h>

#include <Key.h>
#include <Keypad.h>

LiquidCrystal lcd(13,12,11,10,9,8);

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {4,3,2,1}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,6,7}; //connect to the column pinouts of the keypad
Keypad mykey =Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int pass_length=6;
char master_password[7]="123456";
char data[7];
byte dc=0,mc=0;
char key;
bool door=false;


void setup()
{
pinMode(0,OUTPUT);
pinMode(A0,OUTPUT);
lcd.begin(20,2);
lcd.setCursor(0,0);
lcd.print("PASSWORD BASED");
lcd.setCursor(0,1);
lcd.print("Door Lock SYSTEM");
delay(2000);
lcd.clear();
}

void loop()
{
if (door==0)
{
lcd.setCursor(0,0);
lcd.print("Door is unlocked");
key=mykey.getKey();
if(key=='#')
{
digitalWrite(0,1);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Door was closed");
delay(1000);
digitalWrite(0,0);
door=1;

}

}


else if(door ==1)
{
digitalWrite(A0,0);
lcd.setCursor(0,0);
lcd.print("Enter Password");

key=mykey.getKey();
if(key)
{
data[dc] =key;
lcd.setCursor(dc,1);
lcd.print(data[dc]);
dc=dc+1;
 

}
if(dc==pass_length)
{
  
if(!strcmp(data,master_password))
{
  
lcd.clear();
digitalWrite(0,1);
digitalWrite(A0,0);
lcd.print("Access Granted");
lcd.setCursor(0,1);
lcd.print("Door is Opend");
delay(2000);
door=0;
lcd.clear();
dc=0;
}
else
{
lcd.clear();
digitalWrite(A0,1);
digitalWrite(0,0);
lcd.print("Access Dinied");
lcd.setCursor(0,1);
lcd.print("Please Try Agian");
delay(2000);
door=1;
lcd.clear();
dc=0;
}

}
}


}


 
