#include<ESP8266WiFi.h>

const char *ssid="Sai ganesh";// Your username
const char *password="6302916661";//Your password

WiFiClient espclient;
void setup() {

Serial.begin(9600);
Serial.println("ESP8266 is connecting with the Username of "+String(ssid));
Serial.println("======================================================");
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED)
{
Serial.println("*****");
delay(100);
}
Serial.println("\n WiFi Connected");
Serial.print("IP Address is :");
Serial.println(WiFi.localIP());

}

void loop() {
}
