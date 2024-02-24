/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  NOTE: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL2qIWkHS-J"
#define BLYNK_TEMPLATE_NAME "Temperature"
#define BLYNK_AUTH_TOKEN "dx5rkZB1TvJiPMKQqVPPQVn4JDs4jga8"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "5406 2.4GHz";
char pass[] = "25112911";

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN x                   // Arduino pin connect to DHT Sensor
DHT_Unified dht(DHTPIN, DHTTYPE);  // DHT Sensor config
uint32_t delayMS;                  // Variable for delay

void displayHardwareDetails() {  // Show hardware details in Serial Monitor

  dht.begin();  // Start the function (DHT11)
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);  // Print DHT11 details - temperature
  dht.humidity().getSensor(&sensor);  // Print DHT11 details - humidity
  delayMS = sensor.min_delay / 100;  // delay between readings
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  delay(delayMS);                      // atraso entre as medições
  sensors_event_t event;               // inicializa o evento da Temperatura
  dht.temperature().getEvent(&event);  // faz a leitura da Temperatura
  if (isnan(event.temperature))        // se algum erro na leitura
  {
    Serial.println("Erro na leitura da Temperatura!");  // colocar alerta para o blynk
  } else  // senão
  {
    Serial.print("Temperatura: ");  // imprime a Temperatura
    Serial.print(event.temperature);
    Serial.println(" *C");
    Terminal.print("Temeperatura: ");
  }
  dht.humidity().getEvent(&event);     // faz a leitura de umidade
  if (isnan(event.relative_humidity))  // se algum erro na leitura
  {
    Serial.println("Erro na leitura da Umidade!");
  } else  // senão
  {
    Serial.print("Umidade: ");  // imprime a Umidade
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}

