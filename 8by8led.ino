#include <LedControl.h>
int din=12,cs=11,clk=10;
LedControl lc=LedControl(din,clk,cs,1);

byte a[8]={0X00,0X3C,0X42,0X81,0X44,0XEE,0X44,0X00};


void setup() {
   lc.shutdown(0,false);
   lc.setIntensity(0,8);
   lc.clearDisplay(0);
}

void loop() { 
  int i;
  for(i=0;i<8;i++){
    lc.setRow(0,i,a[i]);
  }
  delay(100);
}
