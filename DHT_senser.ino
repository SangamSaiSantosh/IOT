#include <DHT.h>
#include <DHT_U.h>
#define dhtpin 4
#define sensor DHT11

DHT wear(dhtpin,sensor);
 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
wear.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
int temp, hum;
temp=wear.readTemperature();
hum=wear.readHumidity();
Serial.println("the tempreture is " + String(temp));
Serial.println("the humidity is"+String(hum));
delay(1000);






}
