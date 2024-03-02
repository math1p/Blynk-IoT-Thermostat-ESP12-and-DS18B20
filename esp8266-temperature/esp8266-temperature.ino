#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

float temperature = 0;
float humidity = 0;

void sendData() {
  updateData();
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
}

void setup() {
  delay(1000);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(sendDataDelay, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void updateData() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
}
