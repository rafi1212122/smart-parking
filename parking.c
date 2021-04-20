// Download Blynk and ESP8266 in your Arduino libraries

#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

char auth[] = ""; // Your auth token from Blynk
char ssid [] = ""; // Your WiFi name
char pswd [] = ""; // Your WiFi password

WidgetLED led1(V1);

int sensor1 = D4;

void setup()
{

Serial.begin(9600);
Blynk.begin(auth,ssid,pswd);
pinMode(sensor1, INPUT);
while (Blynk.connect() == false) {
Serial.println("Tidak terkoneksi");
  }
}

void loop()
{
  int sensorval1 = digitalRead(sensor1);
  delay(1000);
if (sensorval1 == 1)
  {
led1.on();
  }
if (sensorval1 == 0)
  {
led1.off();
  }
  Blynk.run();
}