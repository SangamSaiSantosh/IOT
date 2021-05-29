#include <ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>
#include<DHT.h>



#define dhtpin 5
#define dhttype DHT11



const char* ssid = "ACTFIBERNET";
const char* password = "Happy@home";
const char* fingerprint = "271892dda426c30709b97ae6c521b95b48f716e1";



WiFiClientSecure client;



DHT dht(dhtpin, dhttype);




void setup() {



Serial.begin(9600);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
Serial.print("...");
delay(500);
}
Serial.println("\n Connected");
dht.begin();
}



void loop() {
String url = "https://api.thingspeak.com/update?api_key=0LFE7AIFIACZSPXW";
float temp, hum;
temp = dht.readTemperature();
hum = dht.readHumidity();
String fields = "&field1=" + String(temp) + "&field2=" + String(hum);
url = url + fields; //http://api.thingspeak.com/update?api_key=0LFE7AIFIACZSPXW&field1=30.0&field2=42.0
Serial.println(url);
client.connect(url, 443);
client.setFingerprint(fingerprint);
if (WiFi.status() == WL_CONNECTED)
{
HTTPClient http;
http.begin(client, url);
int httpcode = http.GET();
if (httpcode > 0)
{
String response = http.getString();
Serial.println(response);
}



http.end();



}
else
{
Serial.println("WiFi Disconnected");
}




delay(15000);




}
