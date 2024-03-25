#include "config.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define GPIO2 2
#define BLYNK_PRINT Serial

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

BlynkTimer timer;

float temperatureC;

void setup() {
  pinMode(GPIO2, OUTPUT);
  digitalWrite(GPIO2, LOW);
  delay(1000);
  digitalWrite(GPIO2, HIGH);
  delay(1000);
  digitalWrite(GPIO2, LOW);
  delay(1000);
  digitalWrite(GPIO2, HIGH);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(sendDataDelay, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendData() {
  updateData();
  Blynk.virtualWrite(V0, temperatureC);
  // wifi_set_sleep_type(LIGHT_SLEEP_T)
}

void updateData() {
  digitalWrite(GPIO2, LOW);
  delay(2000);
  digitalWrite(GPIO2, HIGH);
  sensors.requestTemperatures();              // Solicitar leitura da temperatura
  temperatureC = sensors.getTempCByIndex(0);  // Obter a temperatura em graus Celsius
}
