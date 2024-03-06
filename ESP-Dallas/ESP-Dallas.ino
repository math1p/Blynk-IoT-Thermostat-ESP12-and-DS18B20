#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

BlynkTimer timer;

float temperatureC = 0;

void sendData() {
  updateData();
  Blynk.virtualWrite(V0, temperatureC);
}

void setup() {
  delay(1000);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(sendDataDelay, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void updateData() {
  sensors.requestTemperatures();  // Solicitar leitura da temperatura
  temperatureC = sensors.getTempCByIndex(0);  // Obter a temperatura em graus Celsius
}