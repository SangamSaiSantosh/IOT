#include <DHT.h>
#include <DHT_U.h>
#include<ESP8266WiFi.h>
#include<PubSubClient.h>

#define ClientID "Nodemcu01"
#define dhtpin 5
#define dhttype DHT11
DHT dht(dhtpin,dhttype);
const char *ssid="Sai ganesh";
const char *password="6302916661";
const char *mqttserver="broker.hivemq.com";
int port=1883;

WiFiClient espclient;
PubSubClient client(espclient);

void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Message arrived [");
Serial.print(topic);
Serial.print("] ");
for (int i = 0; i < length; i++)
{
Serial.print((char)payload[i]);
}
//Serial.println();
//if((char)payload[i])
//{
//digitalWrite(16,LOW);
//Serial.println("LED ON");
//client.publish("iot/data","LED ON");
//}
//else if((char)payload[0]=='0')
//{
//digitalWrite(16,HIGH);
//Serial.println("LED OFF");
//client.publish("iot/data","LED OFF");
//}
}

char msg[30];
String mesg;
float temp,Hum;



void setup() {
dht.begin();
pinMode(16,OUTPUT);
Serial.begin(9600);
Serial.println("WiFi Connect with username: "+String(ssid));
Serial.println("=================================");
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED)
  {
     Serial.print("*/#\*");
     delay(150);
   }
Serial.print("\n WiFi Connected with IP: ");
Serial.println(WiFi.localIP());
client.setServer(mqttserver,port);
client.subscribe("iot/subdata");
client.setCallback(callback);



}



void loop() {
if(!client.connected())
{
while(!client.connected())
{
Serial.println("Attempting to MQTT Connection");
if(client.connect(ClientID))
   {
     client.subscribe("iot/subdata");
     client.publish("iot/data","Attempting connected");
Serial.println("client Connected with "+String(ClientID));
   }

}

}
client.loop();
temp=dht.readTemperature();
Hum=dht.readHumidity();
mesg="Temp="+String(temp)+",Hum="+String(Hum);
Serial.println(mesg);
mesg.toCharArray(msg,30);
}
